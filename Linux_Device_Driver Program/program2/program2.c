#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("Dual BSD/GPL");

static char *whome = "world";
static int howmany = 3;

module_param(howmany, int, S_IRUGO);// S_IRUGO is permission flag
module_param(whome, charp, S_IWUSR);

static int hello_init(void)
{
	int i;
	for(i=0; i< howmany; i++)
		printk(KERN_ALERT "(%d) hello, %s\n",i, whome);
	return 0;
}
static void hello_exit(void)
{
	printk("Good bye,cruel world\n");
}
MODULE_AUTHOR("varun bhatnagar");

module_init(hello_init);
module_exit(hello_exit);
