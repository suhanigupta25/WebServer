#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <sys/socket.h>
#include <mutex>
#include <vector>
#include <queue>
#include <functional>
#include <thread>
#include <condition_variable>

class ThreadPool
{
public:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;

    ThreadPool(size_t numThreads);

    void enqueue(std::function<void()> task);
    void handleClients(int client_socket);

    ~ThreadPool();
};

#endif