#ifndef ClIENT_SOCKET_H
#define CLIENT_SOCKET_H

#include <sys/socket.h>
#include <unistd.h>

class Client_Socket{
    public:
        int client_socket_fd;
        char buffer [1024];
        memset(buffer, 0, sizeof(buffer));
        ssize_t bytes_received;

        std::string Client_Socket_Formation(int client_socket_fd);
        void parseRequest(std::string raw_request);
        ~Client_Socket();

        
};
#endif