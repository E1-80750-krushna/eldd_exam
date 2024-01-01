#include<linux/module.h>



 extern int var;

void fun(void);


static __init int imp_init(void){

    printk(KERN_INFO "%s : imp_init() called\n",THIS_MODULE->name);
    printk(KERN_INFO " %s : var = %d\n", THIS_MODULE->name, var);
	fun();
    printk(KERN_INFO " %s : After fun() called ,var = %d\n", THIS_MODULE->name, var);

    return 0;

}

static __exit void imp_exit (void){

    printk(KERN_INFO"%s : imp_exit() called \n",THIS_MODULE->name);
    printk(KERN_INFO " %s : var = %d\n", THIS_MODULE->name, var);

}

module_init(imp_init);
module_exit(imp_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("krushna mhaske");
MODULE_DESCRIPTION("this is lab exam");
