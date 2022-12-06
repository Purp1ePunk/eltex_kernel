#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

int len,temp;
char *msg;

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Purple");
MODULE_DESCRIPTION("Second module.");

ssize_t	(*proc_read)(struct file *, char __user *, size_t, loff_t *);
ssize_t read_proc(struct file *filp, char *buf, size_t count, loff_t *offp )
{
    if (count > temp) {
        count = temp;
    }
    temp = temp - count;
    copy_to_user(buf, msg, count);
    if (count == 0) temp = len;
    return count;
}

//	ssize_t	(*proc_write)(struct file *, const char __user *, size_t, loff_t *);
ssize_t write_proc(struct file *filp,const char *buf,size_t count, loff_t *offp)
{
    copy_from_user(msg, buf, count);
    len = count;
    temp = len;
    return count;
}


struct proc_ops proc_fops = {
  .proc_read = read_proc,
  .proc_write = write_proc,
};

void create_new_proc_entry(void)  //use of void for no arguments is compulsory now
{
// struct proc_dir_entry *proc_create(const char *name, umode_t mode, struct proc_dir_entry *parent, const struct proc_ops *proc_ops)
  proc_create("hello_proc", 0, NULL, &proc_fops);
  msg = kmalloc(10*sizeof(char), GFP_KERNEL);
}


int proc_init (void) {
    printk(KERN_INFO "proc.ko insterted\n");
    create_new_proc_entry();
    return 0;
}

void proc_cleanup(void) {
    printk(KERN_INFO "proc.ko removed\n");
    remove_proc_entry("hello_proc", NULL);
    kfree(msg);
}

module_init(proc_init);
module_exit(proc_cleanup);
