#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include "Server.cpp"

int main(){
    Server server(8080);
    server.start();
    
    return 0;
}
