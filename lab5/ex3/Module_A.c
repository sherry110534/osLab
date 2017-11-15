//export a variable symbol $ a function symbol.
#include <linux/module.h> /*needed by all module */

int symbol_variable = 99;//varaible symbol
int symbol_function(int x){//function symbol
	if(x > 0)
		return 1;
	else if(x == 0)
		return 0;
	else
		return -1;
}
int init_module(void){
	printk(KERN_INFO "Modole_A inserts successfully\n");
	return 0;
}

void cleanup_module(void){
	printk(KERN_INFO "Module_A removes successfully.\n");
}
EXPORT_SYMBOL(symbol_variable);
EXPORT_SYMBOL(symbol_function);

//Module information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("OSLAB");
MODULE_DESCRIPTION("OSLAB_MODULE");

