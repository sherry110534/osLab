#include <linux/module.h> /*needed by all module */

int init_module(void){
	printk(KERN_INFO "Hello module inserts successfully\n");
	return 0;
}

void cleanup_module(void){
	printk(KERN_INFO "Hello module removes successfully.\n");
}

//Module information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("OSLAB");
MODULE_DESCRIPTION("OSLAB_MODULE");

