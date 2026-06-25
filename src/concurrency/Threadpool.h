#ifndef THREADPOOL_H
#define THREADPOOL_H

class ThreadPool{
    public: 
        ThreadPool(size_t threads);
        void enqueue(std::function<void()> task);
        //pool.push([client_socket]){
        //handleclient();}

        ~ThreadPool();
};

#endif

