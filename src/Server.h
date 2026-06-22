#ifndef SERVER_H
#define SERVER_H

class Server{
    public:
        int socket_fd;
        struct sockaddr_in server_addr;

    public:
        Server(int port);
        void start(){
            int bind();
            int listen();
            while(true){
                accept();
                recv();
                parse request;
                send reponse;
                close client socket;
            }
        };
        ~Server();
        
};
#endif