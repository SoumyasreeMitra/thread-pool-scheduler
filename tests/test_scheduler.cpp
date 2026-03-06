#include "../include/threadpool.h"
#include <iostream>
#include <chrono>
#include <thread>

int main() {

    ThreadPool pool(4);

    for(int i = 0; i < 10; i++) {

        pool.enqueue([i] {

            std::this_thread::sleep_for(
            std::chrono::milliseconds(50));

            std::cout << "Task " << i
                      << " executed\n";

        }, i % 3);

    }

    return 0;

}