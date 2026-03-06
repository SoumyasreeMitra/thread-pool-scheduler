#include "../include/threadpool.h"
#include <iostream>
#include <chrono>

ThreadPool::ThreadPool(size_t threads) : stop(false), tasks_completed(0) {

    for(size_t i = 0; i < threads; ++i) {

        workers.emplace_back([this] {

            while(true) {

                Task task;

                {
                    std::unique_lock<std::mutex> lock(queue_mutex);

                    condition.wait(lock, [this] {

                        return stop || !tasks.empty();

                    });

                    if(stop && tasks.empty())
                        return;

                    task = tasks.top();
                    tasks.pop();
                }

                auto start = std::chrono::high_resolution_clock::now();

                task.func();

                auto end = std::chrono::high_resolution_clock::now();

                auto duration =
                std::chrono::duration_cast<std::chrono::microseconds>(end - start);

                std::cout << "Task completed in "
                          << duration.count()
                          << " us\n";

                tasks_completed++;

            }

        });

    }

}

void ThreadPool::enqueue(std::function<void()> task, int priority) {

    {
        std::unique_lock<std::mutex> lock(queue_mutex);

        tasks.push(Task{priority, task});
    }

    condition.notify_one();

}

ThreadPool::~ThreadPool() {

    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }

    condition.notify_all();

    for(std::thread &worker : workers)
        worker.join();

    std::cout << "Total tasks executed: "
              << tasks_completed.load()
              << std::endl;

}