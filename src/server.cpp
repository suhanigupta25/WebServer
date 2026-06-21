#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include "server.h"
class Server{
    public: 
        Server(){};
        int socket_fd=socket(AF_INET, SOCK_STREAM, 0);
        if (socket_fd<0){
            std::cerr <<"socket not available";
        }
        int bind(int socket_fd, const struct sockaddr *address, socklen_t *address_len);
        int listen(int socket_fd, int backlog);
        int accept(int socket_fd, struct sockaddr *address, socklen_t *address_len);
        int client_fd=accept(socket_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        int close(int socket_fd);
        ~Server();
}

