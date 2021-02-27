/**
 * hello.c
 *
 * Kernel module that communicates with /proc file system.
 * 
 * The makefile must be modified to compile this program.
 * Change the line "simple.o" to "hello.o"
 *
 * Operating System Concepts - 10th Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/hash.h>
#include <linux/gcd.h>
#include <asm/param.h>
#include <linux/jiffies.h>

static int hello_init(void){
	printk(KERN_INFO "Loading Module \n");
	printk(KERN_INFO "Golden Ratio Prime : %lu\n", GOLDEN_RATIO_PRIME);
	printk(KERN_INFO "HZ : %d\n", HZ);
	printk(KERN_INFO "Jiffies : %lu\n", jiffies);
	return 0;
}

static void hello_exit(void){
	printk(KERN_INFO "Removing Module");
	unsigned long a = gcd(3300,24);
	printk(KERN_INFO "The GCD between 3300 and 24 is : %lu\n", a);
	printk(KERN_INFO "Jiffies : %lu\n", jiffies);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello Module");
MODULE_AUTHOR("SGG");
