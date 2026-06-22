#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include "Server.h"
#include "RequestParser.cpp"

class Server{
    public: 
        Server(int port){
            socket_fd=socket(AF_INET, SOCK_STREAM, 0);
            if (socket_fd<0){
                std::cerr <<"socket not available";
            }
            server_addr.sin_family=AF_INET;
            server_addr.sin_port=htons(port);
            server_addr.sin_addr.s_addr=INADDR_ANY;
        }
        void start(int port){
            if(bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))<0){
                std::cerr <<"bind failed";
            }
            else{
                std::cout <<"server started on port "<<ntohs(server_addr.sin_port)<<std::endl;
            }
            if(listen(socket_fd, 10)<0){
                std::cerr <<"listen failed";
            }
            else{
                std::cout <<"listening for connections..."<<std::endl;
            }
            while(true){
                int client_socket=accept(socket_fd, NULL, NULL);
                if(client_socket<0){
                    std::cerr <<"accept failed";
                }
                else{
                    std::cout <<"client connected"<<std::endl;
                    char buffer[1024];
                    memset(buffer, 0, sizeof(buffer));
                    recv(client_socket, buffer, sizeof(buffer), 0);
                    auto request=Request::parse(std::string(buffer));                    
                    if (request->method=="GET"){
                        std::cout<<"get method called";
                    }
                    else if (request->method=="POST"){
                        std::cout<<"post method called";
                    }
                    else if (request->method=="PUT"){
                        std::cout<<"put methof called";
                    }
                    else if (request->method=="DELETE"){
                        std::cout<<"delete method called";
                    }
                    else{
                        std::cerr <<"unsupported method";
                    }
                    shutdown(client_socket, SHUT_WR);
                    close(client_socket);
                }
            }
        }

};
