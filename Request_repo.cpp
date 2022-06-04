#include "RequestRepository.h"


RequestRepository::RequestRepository(std::string method, std::string url, std::string path,std::string version, std::string body):method{},url{}, path{}, version{}, body{}   {}
RequestRepository::RequestRepository(std::string method, std::string url, std::string path,std::string version, std::string body):method{method},url{url}, path{path}, version{version}, body{body}{}

 std::string RequestRepository::getMethod(){return method;}
 std::string RequestRepository::getPath(){return path;}
std::map<std::string, std::string> RequestRepository::getHeaders(){return headers;}

void parse(RequestRepository& reqObj,const std::string& req, ssize_t receivedBytes){
    int index = 0;
    std::string method = reqObj.getMethod();
    std::string path = reqObj.getPath();
    std::map<std::string, std::string> headers = reqObj.getHeaders();
    while (method[method.size() - 1] != ' ' && index < receivedBytes){
        method.push_back(req[index]);
        ++index;
    }
    while (path[path.size() - 1] != ' ' && index < receivedBytes){
        path.push_back(req[index]);
        ++index;
    }

    while (index < receivedBytes){
        std::string key;
        std::string value;
        if (req[index] == '\n'){
            ++index;
            break;
        }
    }
}
