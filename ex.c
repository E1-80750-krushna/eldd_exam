#include<linux/module.h>

static __init int exp_init(void){

    printk(KERN_INFO "%s : exp_init() called\n",THIS_MODULE->name);
    return 0;

}

static __exit void exp_exit (void){

    printk(KERN_INFO"%s : exp_exit() called \n",THIS_MODULE->name);

}

module_init(exp_init);
module_exit(exp_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("krushna mhaske");
MODULE_DESCRIPTION("this is lab exam");
