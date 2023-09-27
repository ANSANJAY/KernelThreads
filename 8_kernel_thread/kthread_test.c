#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/kthread.h>
#include <linux/delay.h>

struct task_struct *print_thread;
char buffer[256];
char * get_task_state(long state)
{
    switch (state) {
        case TASK_RUNNING:
            return "TASK_RUNNING";
        case TASK_INTERRUPTIBLE:
            return "TASK_INTERRUPTIBLE";
        case TASK_UNINTERRUPTIBLE:
            return "TASK_UNINTERRUPTIBLE";
        case __TASK_STOPPED:
            return "__TASK_STOPPED";
        case __TASK_TRACED:
            return "__TASK_TRACED";
	case TASK_IDLE:
	    return "(TASK_UNINTERRUPTIBLE | TASK_NOLOAD)";
	case TASK_KILLABLE:
	    return "(TASK_WAKEKILL | TASK_UNINTERRUPTIBLE)";
	case TASK_STOPPED:
	    return "(TASK_WAKEKILL | __TASK_STOPPED)";
	case TASK_TRACED:
	    return "(TASK_WAKEKILL | __TASK_TRACED)";
        default:
        {
            sprintf(buffer, "Unknown Type:%ld", state);
            return buffer;
        }
    }
}

static int print_running_thread(void *data)
{
	 while(!kthread_should_stop()) {
		 struct task_struct *task_list;
		 for_each_process(task_list) {
			 if (task_list->state == TASK_RUNNING)
				 pr_info("Process: %s\t PID:[%d]\t State:%s\n", 
						 task_list->comm, task_list->pid,
						 get_task_state(task_list->state));
		 }
		 msleep(500);
	 }
	 return 0;
}

MODULE_LICENSE("GPL");
static int test_tasks_init(void)
{
    pr_info("%s: In init\n", __func__);
    print_thread = kthread_run( , NULL,
				"print_running_cpu");
    return 0;
}

static void test_tasks_exit(void)
{
    pr_info("%s: In exit\n", __func__);
    kthread_stop(print_thread);
}

module_init(test_tasks_init);
module_exit(test_tasks_exit);

