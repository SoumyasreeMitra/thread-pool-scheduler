# Multithreaded Task Scheduler (Thread Pool) in C++

## Overview

This project implements a **multithreaded task scheduler using a thread pool architecture in C++**.

Instead of creating a new thread for each task, a fixed number of worker threads process tasks from a shared queue.  
This approach significantly reduces thread creation overhead and improves concurrency performance.

The scheduler demonstrates key concepts from:

- Operating Systems
- Concurrent Programming
- Multithreading
- Task Scheduling

---

## Key Features

- Thread pool architecture
- Priority-based task scheduling
- Task execution time measurement
- Thread-safe task queue using mutex and condition variables
- Worker thread lifecycle management
- Task statistics logging

---

## Architecture


User Tasks
│
▼
Task Queue (Priority Queue)
│
▼
Thread Pool Workers
│
▼
Concurrent Task Execution


Worker threads continuously fetch tasks from the queue and execute them concurrently.

---

## Project Structure


thread-pool-scheduler/
│
├── include/
│ └── threadpool.h
│
├── src/
│ └── threadpool.cpp
│
├── tests/
│ └── test_scheduler.cpp
│
├── Makefile
│
└── README.md


---

## Build

Compile using:


make


---

## Run


make run


Example output:


Task 0 executed
Task completed in 50321 us
Task 1 executed
Task completed in 49822 us
...
Total tasks executed: 10


---

## Concepts Demonstrated

- Thread pools
- Mutex synchronization
- Condition variables
- Priority task scheduling
- Performance measurement
- Concurrent system design

---

## Future Improvements

- Dynamic thread scaling
- Work-stealing queues
- Task dependency graph
- Lock-free task queue

---

## Author

Soumyasree Mitra

GitHub: https://github.com/SoumyasreeMitra  
LinkedIn: https://www.linkedin.com/in/soumyasree-mitra/

---

## License

Educational project for learning systems programming.