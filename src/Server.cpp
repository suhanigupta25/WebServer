#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include "Server.h"
#include "RequestParser.h"

        Server::Server(int port){
            socket_fd=socket(AF_INET, SOCK_STREAM, 0);
            if (socket_fd<0){
                std::cerr <<"socket not available";
            }
            server_addr.sin_family=AF_INET;
            server_addr.sin_port=htons(port);
            server_addr.sin_addr.s_addr=INADDR_ANY;
        }
        void Server::start(){
            if(bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))<0){
                perror("bind");
            }
            else{
                std::cout <<"server started on port "<<ntohs(server_addr.sin_port)<<std::endl;
            }
            if(listen(socket_fd, 10)<0){
                perror("listen");
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
                    ssize_t bytes_received=recv(client_socket, buffer, sizeof(buffer), 0);
                    
                    std::string raw_request(buffer, bytes_received);
                    Request req;
                    auto request = req.parse(raw_request);

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
                }
            }
        }
        Server::~Server(){
            close(socket_fd);
        }