#include "Client_Socket.h"
#include "./http/RequestParser.h"
#include <iostream>

std::string recieveRequest(int client_socket_fd,char buffer[]){
    ssize_t bytes_received=recv(client_socket_fd, buffer, sizeof(buffer), 0);
    std::string raw_request(buffer, bytes_received);
}

void Client_Socket::parseRequest(std::string raw_request)
{    
    Request req;
    auto request = req.parse(raw_request);

    if (request->method == "GET")
    {
        std::cout << "get method called" << std::endl;
    }
    else if (request->method == "POST")
    {
        std::cout << "post method called"<< std::endl;
    }
    else if (request->method == "PUT")
    {
        std::cout << "put method called"<< std::endl;
    }
    else if (request->method == "DELETE")
    {
        std::cout << "delete method called"<< std::endl;
    }
    else
    {
        perror("unsupported method");
    }
}

Client_Socket::~Client_Socket()
{
    shutdown(client_socket_fd, SHUT_WR);
}
