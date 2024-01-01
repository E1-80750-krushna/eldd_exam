#include<linux/module.h>
#include<linux/moduleparam.h>



 extern int var;

void fun(void);
int notify_change(const char *va, const struct kernel_param *kp)
{
	int res = param_set_int(va, kp);		// default callback
	if(res == 0)
	{
		printk(KERN_INFO " var is called\n");
		printk(KERN_INFO "new  value of var = %d\n", var);
		return 0;
	}
	return -1;
}

struct kernel_param_ops var_ops = {
	.set = &notify_change,		
	.get = &param_get_int		
};

module_param_cb(var, &var_ops, &var, 0644);


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
