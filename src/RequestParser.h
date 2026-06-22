#ifndef REQUESTPARSER_H
#define REQUESTPARSER_H
#include <string>
#include <memory>

struct Request{
    std::string method;
    std::string path;
    std::string version;

    static std::shared_ptr<Request> parse(std::string &requestLine);

};

#endif