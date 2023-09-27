### 1. Explain the Technical Concept 📘

A **Kernel Thread** in Linux is a specialized task that exclusively runs in kernel mode. 

- Unlike user-level threads, kernel threads are not created by the `fork()` or `clone()` system calls. 
- They operate in the background to assist the kernel in performing various operations and handling system-level tasks, like processing work queues and handling softirqs.

- The creation of a kernel thread involves using the API provided by Linux. 
- Specifically, `kthread_create` is used to create a kernel thread, but this only creates the thread; it does not run it. 
- To run the thread, `wake_up_process()` must be invoked. 
- Additionally, there’s a convenient function, `kthread_run`, that combines creation and waking up processes. 
- It’s crucial to stop the kernel thread properly using `kthread_stop` to avoid system errors (oops messages).

Kernel threads, like user threads, are represented by `task_struct`, but the notable difference lies in the absence of address space in kernel threads, denoted by having the `mm` variable of `task_struct` set to `NULL`.

### 2. Curious Questions 🤔

#### Q: How does a Kernel Thread differ from a User Thread in terms of structure representation in Linux?
**A:** Both are represented by `task_struct`, but Kernel Threads have no address space, marked by the `mm` variable of `task_struct` being set to `NULL`.

#### Q: Why is it important to properly stop a Kernel Thread using `kthread_stop`?
**A:** Properly stopping a Kernel Thread is crucial as not doing so may result in system errors, specifically oops messages, indicating a corruption in the kernel data structure, which could lead to instability or crashes.

#### Q: What is the significance of `kthread_should_stop()` in the context of Kernel Thread operations?
**A:** The `kthread_should_stop()` function is significant as it is used to check whether the kernel thread should stop executing, allowing for the controlled termination of the thread function.

### 3. Explain the Concept in Simple Words 🌟
- Imagine the Linux operating system as a busy kitchen 🍳. The User Threads are like the chefs 👨‍🍳 operating and preparing different dishes, each having their recipe (address space). 
- Now, think of the Kernel Threads as the kitchen assistants 👨‍🍳 who are not following any recipe (no address space) but are essential in aiding 🧑‍🔧 the overall kitchen operation, like cleaning and organizing.

Creating a Kernel Thread is like hiring a kitchen assistant. You create the assistant's role (`kthread_create`), define their tasks 📝 (thread function), but you also need to make sure they start working (`wake_up_process`) and know when to take a break or stop 🛑 (`kthread_should_stop`).

- Not doing so, not allowing them to stop, could lead to chaos in the kitchen (oops message)! 🚨


## all the task in [] are kthread
![](./Screenshot%20from%202023-09-26%2021-15-43.png)


## What are the some examples of Kernel Thread?
=============================================
1. ksoftirqd is Per CPU kernel thread runs processing softirqd.
2. kworker is a kernel thread which processes work queues.

How to Create a Kernel Thread?
====================================

API For creating a kernel thread.
```C
#include <linux/kthread.h>
struct task_struct *kthread_create(int (*threadfn)(void *data), void *data, const char name[], ...)
```

## Parameters:

```bash
threadfn -> the function which thread should run
data -> Argument for thread function
name -> Printf style format for the name of kernel thread.
Return Value: Pointer to struct  task_struct
```

## Note: **kthread_create** only creates the thread but doesn't run the thread, we need to call **wake_up_process()** with the return value of **kthread_create** as an argument to the wake_up_process for the thread function to run.

Linux provides an API which creates the kernel thread and calls wake_up_process().

```C
struct task_struct * kthread_run(int (*threadfn)(void *data), void *data, const char name[], ...)
```

To stop the kernel thread.

```C
int kthread_stop(struct task_struct *k);
```

Note: If you don't stop the kernel thread in your `module_exit` function, you will get oops message.

- `kthread_stop` is a blocking call, it waits until the function executed by thread exits. 
- `kthread_stop()` flag sets a variable in the task_struct variable which the function  `kthread_should_stop()` running in while(1) should check in each of its loop.

```C
int threadfunc(void *data)
{

     while(!kthread_should_stop())
     {
                //perform operations here
      }
	return 0;
}
```