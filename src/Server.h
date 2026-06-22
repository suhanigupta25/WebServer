#ifndef SERVER_H
#define SERVER_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

class Server{
    public:
        int socket_fd;
        struct sockaddr_in server_addr;

        Server(int port);
        void start(int socket_fd);
        ~Server();
        
};
#endif