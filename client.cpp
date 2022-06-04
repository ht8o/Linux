#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <cerrno>


int main(int argc, char** argv){
 int port = 9090;
 if(argc > 1){
  port = atoi(argv[1]);
 }
 int serverFd = socket(AF_INET, SOCK_STREAM, 0);
 if(serverFd < 0){
  std::cerr << "socket error" << std::endl;
  exit(errno);
 }
 sockaddr_in address; 
 address.sin_family = AF_INET;
 address.sin_port = htons(9090);

 address.sin_addr.s_addr = htonl (INADDR_ANY);
 int bound = bind(serverFd, (const struct sockaddr*) &address, sizeof(address));
 
 if(bound < 0){
  std::cerr << "is not given port" << std::endl;
  exit(errno);
 }
 int listening = listen(serverFd, 1024);
 if(listening < 0){
  std::cerr << "Is not listening" << std::endl;
  exit(errno);
 }
 return 0;
}
