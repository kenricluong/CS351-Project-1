#include <linux/init.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/proc_fs.h>
#include <linux/string.h>
#include <linux/timer.h>

static int proc_init(void);
static void proc_exit(void);

struct proc_dir_entry*my_proc;

ssize_t proc_read(struct file *file, char *buffer, size_t count, loff_t * off){
	static int complete = 0;
	if(complete){
		complete = 0;
		return 0;
		}
	complete = 1;

sprintf(buffer, "Jiffies : %lu \n",jiffies);
return strlen(buffer);
}

static struct file_operations proc_ops = {
.owner=THIS_MODULE,
.read=proc_read,
};

static int proc_init(void)
{

my_proc = proc_create("jiffies", 0666, NULL, &proc_ops);

if(my_proc == NULL){
printk(KERN_INFO "Cannot create proc file\n");
}

return 0;
}

static void proc_exit(void)
{
remove_proc_entry("jiffies",NULL);
return;
}

module_init(proc_init);
module_exit(proc_exit);
