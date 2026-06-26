

class ThreadPool{

    public: 
        std::queue<<std::function<void()>>
        ThreadPool(size_t threads);
        void enqueue(std::function<void()> task){
            
        }
        while(true){
    int client_socket = clientQueue.front();
    clientQueue.pop();

    handleClient(client_socket);
}
        
        


        ~ThreadPool();
};