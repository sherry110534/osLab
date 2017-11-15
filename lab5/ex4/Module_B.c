#include <linux/module.h> /*needed by all module */

extern int symbol_function(int);
int symbol_variable = 56;
int init_module(void){
	printk(KERN_INFO "Modole_B inserts successfully\n");
	printk(KERN_INFO "symbol_variable:%d\n", symbol_variable);
	printk(KERN_INFO "symbol_function(%d) = %d\n", symbol_variable, symbol_function(symbol_variable));	
	return 0;
}

void cleanup_module(void){
	printk(KERN_INFO "Module_B removes successfully.\n");
}
EXPORT_SYMBOL(symbol_variable);

//Module information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("OSLAB");
MODULE_DESCRIPTION("OSLAB_MODULE");

