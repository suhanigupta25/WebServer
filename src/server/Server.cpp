#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include "Server.h"
#include "RequestParser.h"
#include "Client_Socket.h"

        Server::Server(int port){
            socket_fd=socket(AF_INET, SOCK_STREAM, 0);
            if (socket_fd<0){
                perror("socket not available");
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
                int client_socket_fd=accept(socket_fd, NULL, NULL);
                if(client_socket_fd<0){
                    std::cerr <<"client accept failed";
                }
                else{
                    Client_Socket::Client_Socket_Formation(int client_socket_fd);      
                    std::cout <<"client connected"<<std::endl;                                  
                }
            }
        }
        Server::~Server(){
            close(socket_fd);
        }