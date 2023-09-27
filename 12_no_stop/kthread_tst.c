#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/kthread.h>
#include <linux/delay.h>

struct task_struct *print_thread;

static int threadfunc(void *data)
{
	while(!kthread_should_stop()) {
		printk("In thread function\n");
		msleep(5000);
	}
	 return 0;
}

MODULE_LICENSE("GPL");
static int test_tasks_init(void)
{
    pr_info("%s: In init\n", __func__);
    print_thread = kthread_run(threadfunc, NULL,
				"print_running_cpu");
    return 0;
}

static void test_tasks_exit(void)
{
    pr_info("%s: In exit\n", __func__);
}

module_init(test_tasks_init);
module_exit(test_tasks_exit);

