#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <atomic>

struct Task {

    int priority;

    std::function<void()> func;

    bool operator<(const Task &other) const {

        return priority < other.priority;

    }

};

class ThreadPool {

public:

    ThreadPool(size_t threads);

    void enqueue(std::function<void()> task, int priority = 0);

    ~ThreadPool();

private:

    std::vector<std::thread> workers;

    std::priority_queue<Task> tasks;

    std::mutex queue_mutex;

    std::condition_variable condition;

    bool stop;

    std::atomic<int> tasks_completed;

};

#endif