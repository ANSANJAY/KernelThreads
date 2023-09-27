### 1. **Explain the Technical Concept 📘:**
In a multithreading environment, multiple threads are allowed to exist within the context of a process, sharing certain resources and capable of executing concurrently. The experiment mentioned is designed to illustrate the concept of parallel execution of threads. 

When two threads are launched and asked to count from 0 to 9, they run in parallel and log their counts to `dmesg`. The log from `dmesg` confirms parallel execution by displaying interleaved outputs from both threads. The possibility of seeing interleaved outputs indicates that the threads are not blocked by each other and are scheduled independently by the kernel, hence proving they are running in parallel.

### 2. **Curious Questions 🤔:**
   **a. Question:** 
   How can one confirm that threads are running in parallel within a process?

   **Answer:** 
   One can confirm that threads are running in parallel by observing the interleaved execution of threads, where each thread is able to execute independently without waiting for the other thread to complete. The interleaved outputs in log files, like `dmesg` in this case, serve as proof of parallel execution.

   **b. Question:** 
   How does the kernel manage the execution of multiple threads in parallel?
   
   **Answer:** 
   The kernel manages multiple threads using a scheduler. The scheduler allocates CPU time to the threads based on scheduling algorithms, allowing threads to run concurrently. It gives the illusion of simultaneous execution on single-core processors through context switching and enables true parallel execution on multi-core processors.

   **c. Question:** 
   What could be the possible reason if the threads do not interleave and execute sequentially instead?
   
   **Answer:** 
   If threads are executing sequentially instead of interleaving, it may be due to thread contention for a shared resource, causing one thread to block until the other has released the lock on the shared resource. It could also be due to the configuration of the scheduler or due to thread priorities, where a high-priority thread may execute before a lower-priority one.

### 3. **Explain the Concept in Simple Words 🌟:**
Imagine you and your friend are both drawing on a drawing board at the same time. You both are like the two threads, and the drawing board is like the process. If you both are able to draw without waiting for the other to finish, you are drawing in parallel, just like the threads in the example. 

The teacher, who makes sure you both get equal chances to draw, is like the kernel scheduler. Sometimes, if you both want to draw at the same spot, one has to wait—this waiting is like thread contention for a shared resource. But if you see both your drawings intermixed on the board, it means you both were able to draw at the same time, proving that you were working in parallel!


<thread_id> <count>

Possible very likely outcome:

1 0
2 0
1 1
2 1
1 2
2 2
1 3
2 3

The threads almost always interleaved nicely, thus confirming that they are actually running in parallel.


