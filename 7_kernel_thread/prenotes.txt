What is  Kernel Thread?
======================================
A Kernel Thread is a Linux Task running only in kernel mode. It is not created by running fork() or clone() system calls.

What is the use of Kernel Thread?
========================================
Kernel Threads helps the kernel to perform operations in background.

What are the some examples of Kernel Thread?
=============================================
1. ksoftirqd is Per CPU kernel thread runs processing softirqd.
2. kworker is a kernel thread which processes work queues.

What are the differences between Kernel Thread and User Thread?
==================================================================
Both Kernel Thread and User Thread are represented by task_struct. The main difference is that there is no address space in kernel threads. mm variable of task_struct is set to NULL.

How to Create a Kernel Thread?
====================================

API For creating a kernel thread.

#include <linux/kthread.h>
struct task_struct *kthread_create(int (*threadfn)(void *data), void *data, const char name[], ...)

Parameters:

threadfn -> the function which thread should run
data -> Argument for thread function
name -> Printf style format for the name of kernel thread.

Return Value: Pointer to struct  task_struct

Note: kthread_create only creates the thread but doesn't run the thread, we need to call wake_up_process() with the return value of kthread_create as an argument to the wake_up_process for the thread function to run.

Linux provides an API which creates the kernel thread and calls wake_up_process().

struct task_struct * kthread_run(int (*threadfn)(void *data), void *data, const char name[], ...)

To stop the kernel thread.

int kthread_stop(struct task_struct *k);

Note: If you don't stop the kernel thread in your module_exit function, you will get oops message.

kthread_stop is a blocking call, it waits until the function executed by thread exits. kthread_stop() flag sets a variable in the task_struct variable which the function running in while(1) should check in each of its loop.

int threadfunc(void *data)
{

     while(!kthread_should_stop())
     {
                //perform operations here
      }
	return 0;
}
