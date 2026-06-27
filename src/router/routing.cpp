#include "routing.h"

void Router::addGET(const std::string& path,Handler handler){
    auto it=getRoutes.find(request.path);
    getRoutes[path]=handler;
}