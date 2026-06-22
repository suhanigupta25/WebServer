#include <ranges>
#include <memory>
#include "RequestParser.h"

static std::shared_ptr<Request> parse(const std::string &requestLine)
    {
        auto request = std::make_shared<Request>();
        int i = 0;
        for (auto part : requestLine | std::views::split(' '))
        {
            std::string word(part.begin(), part.end());
            if (i == 0)
                request->method = word;
            else if (i == 1)
                request->path = word;
            else if (i == 2)
                request->version = word;
            i++;
        }
        return request;
    }

