#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("Dual BSD/GPL");

void add(int a,int b);
void sub(int a,int b);

static int hello_init(void)
{
	printk(KERN_ALERT "hello F1\n");
	return 0;
}
void add(int a,int b)
{
	int y;
	y = a + b;
	printk(KERN_ALERT "add of a + b = %d\n",y);
}

void sub(int a,int b)
{
	int y;
	y = a - b;
	printk(KERN_ALERT "sub of a - b = %d\n",y);
}

static void hello_exit(void)
{
	printk("Good bye,F1\n");
}
EXPORT_SYMBOL(add);
EXPORT_SYMBOL(sub);

MODULE_AUTHOR("varun bhatnagar");

module_init(hello_init);
module_exit(hello_exit);
