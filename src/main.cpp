#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include "Server.cpp"

int main(){
    Server(8080);
    return 0;
}
