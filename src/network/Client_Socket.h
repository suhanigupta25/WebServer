#ifndef ClIENT_SOCKET_H
#define CLIENT_SOCKET_H

#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <cstring>

class Client_Socket{
    public:
        int client_socket_fd;
        char buffer [1024];
        ssize_t bytes_received;

        Client_Socket(int client_socket_fd){
            memset(buffer, 0, sizeof(buffer));
        };
        std::string receiveRequest();
        void parseRequest(std::string raw_request);
        ~Client_Socket();
        
};
#endif