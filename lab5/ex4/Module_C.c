#include <linux/module.h> /*needed by all module */

extern int symbol_variable;
module_param(symbol_variable, int, 0);
MODULE_PARM_DESC(symbol_variable, "user can change it");

int init_module(void){
	printk(KERN_INFO "Modole_C inserts successfully\n");
	printk(KERN_INFO "symbol_variable:%d\n", symbol_variable);
	return 0;
}

void cleanup_module(void){
	printk(KERN_INFO "Module_C removes successfully.\n");
}

//Module information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("OSLAB");
MODULE_DESCRIPTION("OSLAB_MODULE");

