#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <sys/socket.h>
class ThreadPool {
public:
    ThreadPool(size_t numThreads);

    void enqueue(std::function<void()> task);

    ~ThreadPool();

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex mutex;
    std::condition_variable cv;
};

#endif