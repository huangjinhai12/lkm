#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

char *msg_buf = "hello world!";
int n_arr[] = {1,2,3,4,5};
int n = 7;

module_param_array(n_arr,int,&n,S_IRUSR);
module_param(msg_buf,charp,S_IRUSR);

static int __init hello_init(void)
{
	int i;
	printk("%s\n",msg_buf);
	for(i=0; i<n ;i++)
	{
		printk(KERN_WARNING"n_arr[%d]=%d\n", i , n_arr[i]);
	}
	return 0;
}
static void __exit hello_exit(void)
{
	printk(KERN_WARNING"Goodbye,kernel!\n");
}
module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("DUAL BSD/GPL");
MODULE_AUTHOR("huangjinhai");
