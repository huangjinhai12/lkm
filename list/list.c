#include <linux/init.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/completion.h>
#include <linux/kthread.h>
#include <linux/delay.h> 
#include <linux/slab.h>
MODULE_LICENSE("Dual BSD/GPL");
 
static struct task_struct *work_tsk;
 
static struct task_struct *watchdog_tsk;
 
spinlock_t work_list_lock;
 
static LIST_HEAD(work_list);
 
static DECLARE_COMPLETION(work_wait);
 
enum WORK_EVENT_TYPE {
	EVENT_TIMER,
	EVENT_EXIT
};
 
struct work_event {
	enum WORK_EVENT_TYPE type;
	int need_free;
	struct list_head list;
};
 
static int work_thread(void *data)
{
	int count = 0;
 	struct work_event *event;
	while(1){
		if(list_empty(&work_list))
			wait_for_completion(&work_wait);
		//spin_lock(&work_list_lock);
		while(!list_empty(&work_list)){
			//struct work_event *event;
			spin_lock(&work_list_lock);
			event = list_entry(work_list.next, struct work_event, list);
			if(event != NULL){
				list_del(&event->list);  //将这个node从work_list中剔除
				
				//spin_unlock(&work_list_lock);
				if(event->type == EVENT_TIMER){
					printk(KERN_INFO "event timer: count = %d\n", ++count);
					printk("free event node --EVENT_TIMER\n");
				}
				else if (event->type == EVENT_EXIT){
					if(event->need_free){
						kfree(event);
						printk("free event node --EVENT_EXIT\n");
					}
				goto exit;
				}
				if(event->need_free)
					kfree(event);
			}
			spin_unlock(&work_list_lock);
		}
	}
exit:
	spin_unlock(&work_list_lock);
	return count;
}
 
static int watchdog_thread(void *data)
{
	int count = 0;
	while(!kthread_should_stop()){
		msleep(300);
		count++;
		if(count%2 == 0){
			struct work_event *event;
			event = kmalloc(sizeof(struct work_event), GFP_KERNEL);
			if(event == NULL){
				printk(KERN_INFO "watchdog_thread: kmalloc failed!\n");
				break;
			}
			event->type = EVENT_TIMER;
			event->need_free = 1;
			spin_lock(&work_list_lock);
			list_add_tail(&event->list, &work_list);
			spin_unlock(&work_list_lock);
			complete(&work_wait);
		}
	}
	return count;
}
 
static int list_init(void)
{
	printk(KERN_INFO "list_init()\n");
 
	watchdog_tsk = kthread_run(watchdog_thread, NULL, "watchdog_thread");
	if(IS_ERR(watchdog_tsk))
		goto err1;
 
	work_tsk = kthread_run(work_thread, NULL, "work_thread");
	if(IS_ERR(work_tsk))
		goto err2;
	spin_lock_init(&work_list_lock);	
	return 0;
 
err2:
	kthread_stop(watchdog_tsk);
err1:
	return 1;
}
 
static void list_exit(void)
{
	int count;
	struct work_event event;
	printk(KERN_INFO "list_exit()\n");
	if(!IS_ERR(watchdog_tsk)){
		count = kthread_stop(watchdog_tsk);
		printk(KERN_INFO "watchdog_thread: running for %ds\n", count);
	}
	if(!IS_ERR(work_tsk)){
		get_task_struct(work_tsk);
		//struct work_event event;
		event.type = EVENT_EXIT;
		event.need_free = 0;
		spin_lock(&work_list_lock);
		list_add(&event.list, &work_list);
		spin_unlock(&work_list_lock);
		complete(&work_wait);
		
		count = kthread_stop(work_tsk);
		printk(KERN_INFO "work_thread: period 5s, running %d times\n", count);
	}
}
 
module_init(list_init);
module_exit(list_exit);
