#include "../include/threadpool.h"
#include <iostream>

int main() {

    ThreadPool pool(4);

    for(int i = 0; i < 10; i++) {

        pool.enqueue([i] {

            std::cout << "Task " << i << " executed\n";

        });

    }

    return 0;

}