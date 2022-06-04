#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <cerrno>
#include <unistd.h>


int main(int argc, char** argv){
 
 if(argc < 3){
  std::cerr << "eroor:arguments" << std::endl;
  exit(1);
 }
 
 char* hostStr = argv[1];
 int port = atoi(argv[2]);
 sockaddr_in address; 
 address.sin_port = htons(port);
 address.sin_addr.s_addr = inet_addr(hostStr);
  
 int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  
 int connected = connect(serverSocket, (const sockaddr*) &address, sizeof(address));
  
 if(connected < 0){
  std::cerr << "Error: remote host " << std::endl;
  exit(errno);
 }
  
 if(sentBytes < 0){
  std::cerr << "Server: Error " << strerror(errno) << std::endl;
  exit(errno);
 }
  
 int result;
 ssize_t receivedBytes = recv(serverSocket, &result, sizeof(result), 0);
 if(receivedBytes < 0){
 std::cerr << "Error server" << std::endl;
 exit(errno);
        }
 
 close(serverSocket);
 return 0;
}
