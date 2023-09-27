# Kernel Thread Examples 🚀

This repository contains multiple practical examples demonstrating the creation and management of Kernel Threads in Linux. It consists of various scenarios, depicting race conditions, parallel execution of threads, processor IDs associated with threads, and more.

## Structure 📂

The repository is structured with individual directories, each hosting the files related to specific kernel thread examples. Here's a brief overview:

- **10_unique_kernel_thread**: Illustrates a unique kernel thread scenario.
  - `test.c`: Contains the source code for the kernel thread.
  - `Makefile`: The makefile to compile the module.
  
- **11_kernel_thread**: Demonstrates the creation of kernel threads.
  - `kthread_test.c`: Source code demonstrating kernel thread creation.
  - `Makefile`: Makefile for building the module.
  
- **12_no_stop**: Represents a kernel thread scenario where the threads are not stopped.
  - `kthread_tst.c`: Contains the example code.
  - `Makefile`: The makefile to compile the module.
  - `readme.md`: Additional information regarding this example.
  
- **13_kernel_thread**: Shows how to identify the processor id on which the thread is running.
  - `processor_id.c`: The source code illustrating processor ID identification.
  - `Makefile`: The makefile for building the module.
  - `readme.md`: Provides detailed explanations and instructions.
  
- **14_race_condition**: Demonstrates a scenario of race condition in kernel threads.
  - `hello.c`: The source code showcasing race conditions.
  - `Makefile`: The makefile for the module.
  - `readme.md`: Detailed documentation and instructions related to the scenario.
  
- **7_kernel_thread, 8_kernel_thread, 9_parallel_kernel_thread**: Other various scenarios depicting different aspects and features of kernel threads in Linux.

- **LICENSE**: The license file for this repository.
  
- **README.md**: The file you are currently viewing.

## Compilation & Execution 🛠️

To compile any example:

1. Navigate to the respective directory:
   ```sh
   cd <directory_name>
   ```
2. Run make to compile the module:
   ```sh
   make
   ```
3. Insert the module into the kernel:
   ```sh
   insmod <module_name>.ko
   ```
4. Check the `dmesg` logs or `/var/log/kern.log` to see the output and any possible messages from the module:
   ```sh
   dmesg
   ```
5. To remove the module from the kernel, use:
   ```sh
   rmmod <module_name>
   ```

## Contribution 🌐

Feel free to contribute to this repository by creating a pull request. For major changes, please open an issue first to discuss what you would like to change.

## License 📝

This project is licensed under the terms of the included [LICENSE](./LICENSE) file.


