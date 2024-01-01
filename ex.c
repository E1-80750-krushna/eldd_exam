#include<linux/module.h>

int var = 050;




void fun(void)
{
	printk(KERN_INFO " %s : fun called\n", THIS_MODULE->name);
	printk(KERN_INFO " %s :var = %d\n", THIS_MODULE->name, var);
	var++;
}

static __init int exp_init(void){

    printk(KERN_INFO "%s : exp_init() called\n",THIS_MODULE->name);
    	printk(KERN_INFO " %s : var = %d\n", THIS_MODULE->name, var);
    return 0;

}

static __exit void exp_exit (void){

    printk(KERN_INFO"%s : exp_exit() called \n",THIS_MODULE->name);
    


}

module_init(exp_init);
module_exit(exp_exit);

EXPORT_SYMBOL(var);
EXPORT_SYMBOL_GPL(fun);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("krushna mhaske");
MODULE_DESCRIPTION("this is lab exam");
