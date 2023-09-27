#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/kthread.h>
#include <linux/delay.h>

struct task_struct *thread1, *thread2;
unsigned long long counter = 0;
unsigned long loopcount = 10000;

module_param(loopcount,ulong, 0);

static int inc_thread(void *data)
{
	int i = 0;

	printk("Thread Started\n");
	for(i = 0; i < loopcount; i++) {
		counter++;
	}
	 printk("Thread completed\n");
	 return 0;
}

MODULE_LICENSE("GPL");
static int test_tasks_init(void)
{
    pr_info("%s: In init loop count :%lu\n", __func__, loopcount);
    thread1 = kthread_run(inc_thread, NULL,
				"thread1");
    thread2 = kthread_run(inc_thread, NULL,
				"thread2");
    return 0;
}

static void test_tasks_exit(void)
{
    pr_info("%s: In exit counter:%llu\n", __func__, counter);
}

module_init(test_tasks_init);
module_exit(test_tasks_exit);

