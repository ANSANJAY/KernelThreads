#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/smp.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

static struct task_struct *my_task = NULL;

static int my_kthread(void *data) {
    char *str = (char *)data;

    pr_info("my kthread data: %s\n", str);
    pr_info("my kthread smp_processor_id %d\n", smp_processor_id());
    while(!kthread_should_stop()) {
        msleep(5000);
        pr_info("my kthread: living. smp_processor_id %d\n", smp_processor_id());
        pr_info("=========================================\n");
    }
    pr_info("my kthread: stop\n");
    return 0;
}

static int __init my_init(void)
{
    pr_info("my init.\n");
    pr_info("smp_processor_id %d\n", smp_processor_id());

    my_task = kthread_run(my_kthread, "hello my kthread", "mykthread-%s", "test");

    pr_info("my init finish.\n");
    pr_info("=========================================\n");
    return 0;
}

static void __exit my_exit(void)
{
    pr_info("my exit.\n");
    pr_info("smp_processor_id %d\n", smp_processor_id());

    if (my_task) {
        pr_info("stop kthread\n");
        kthread_stop(my_task);
    }

    pr_info("my exit finish.\n");
    pr_info("=========================================\n");
}

module_init(my_init);
module_exit(my_exit);
