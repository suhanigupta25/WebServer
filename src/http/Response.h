#ifndef REUQEST_H
#define REQUEST_H
#include <string>

class Response{
    public:
        int status;
        std::string body;

        std::string serialize();
        send(client,res.serialize().c_str);
};

#endif