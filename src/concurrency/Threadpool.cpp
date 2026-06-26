#include <sys/socket.h>
#include <queue>
#include "Threadpool.h"

    ThreadPool::ThreadPool(){
        for(auto i: numThreads){
            std::thread thread{i};
        }
    }

    void Threadpool::enqueue(std::function<void()> task){
        std::lock_guard<std::mutex> lock(queueMutex);
        tasks.push(task)
        
    }
    condition.notify_one();

    void handleClients(){
        while(true){
        queueMutex.lock();
        
        auto task = tasks.front();
        tasks.pop();

        queueMutx.unlock();
        }
        
    }    
    ~ThreadPool();
