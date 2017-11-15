//use the symbols exported by MODULE_A.
#include <linux/module.h> /*needed by all module */

extern int symbol_variable;
extern int symbol_function(int);

int init_module(void){
	printk(KERN_INFO "Modole_B inserts successfully\n");
	printk(KERN_INFO "symbol_variable:%d\n", symbol_variable);
	printk(KERN_INFO "symbol_function(100) = %d\n", symbol_function(100));	
	printk(KERN_INFO "symbol_function(0) = %d\n", symbol_function(0));
	printk(KERN_INFO "symbol_function(-100) = %d\n", symbol_function(-100));
	return 0;
}

void cleanup_module(void){
	printk(KERN_INFO "Module_B removes successfully.\n");
}

//Module information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("OSLAB");
MODULE_DESCRIPTION("OSLAB_MODULE");

