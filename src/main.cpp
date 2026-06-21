#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include "server.h"

int main(){
    start_server(8080);
    return 0;
}
