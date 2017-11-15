#include <linux/module.h> /*needed by all module */

int variable = 99;
module_param(variable, int, 0);
MODULE_PARM_DESC(variable, "arguement");
int symbol_function(int x){//function symbol
	if(x > 100){
//		printk(KERN_INFO "Input: %d, Result: 1\n",x);
		return 1;
	}
	else if(x == 100){
//		printk(KERN_INFO "Input: %d, Result: 1\n",x);
		return 0;
	}
	else{
//		printk(KERN_INFO "Input: %d, Result: 1\n",x);
		return -1;
	}
}
int init_module(void){
	printk(KERN_INFO "Modole_A inserts successfully\n");
	return 0;
}
void cleanup_module(void){
	printk(KERN_INFO "Module_A removes successfully.\n");
}
EXPORT_SYMBOL(symbol_function);

//Module information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("OSLAB");
MODULE_DESCRIPTION("OSLAB_MODULE");

