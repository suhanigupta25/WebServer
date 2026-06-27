#include <sys/socket.h>
#include <queue>
#include "Threadpool.h"

    ThreadPool::ThreadPool(size_t numThreads){
        stop=false;
        for(size_t i = 0; i < numThreads; i++){
            workers.emplace_back(&ThreadPool::handleClients, this);
        }
    }
    

    void ThreadPool::enqueue(std::function<void()> task){
        std::lock_guard<std::mutex> lock(queueMutex);
        tasks.push(task);
        condition.notify_one(); 
    }
 
    void ThreadPool::handleClients(int client_socket)
    {
        while (true)
        {std::function<void()> task;
            {
                std::unique_lock<std::mutex> lock(queueMutex);
                condition.wait(lock, [this]
                               { return stop || !tasks.empty(); }); // going on sleep

                if (stop && tasks.empty())
                    return;
                
                auto task = tasks.front();
                tasks.pop();
                lock.unlock();
            }
            task();
        }
    }

    ThreadPool::~ThreadPool(){
        stop=true;
        condition.notify_all();

        for (std::thread &worker : workers) {
            if (worker.joinable()) {
                worker.join(); 
        }
    }
    };
