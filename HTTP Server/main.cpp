#include <errno.h>
#include <event.h>
#include <evhttp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include <iostream>

const short SERVER_BACKLOG = 128;
const short BUF_LEN = 26;
const char RESPONCE[BUF_LEN] = "<H1>Hello there</H1><BR/>";
const char * SERVER_NAME = "Simple HTTP Server";

void on_request(struct evhttp_request *, void *);

int main(int argc, char **argv)
{
if (argc < 3) {
std::cout << "Start as:" << std::endl
<< argv[0] << "host_address port" << std::endl;
return 1;
}

int server_sock = socket(AF_INET, SOCK_STREAM, 0);
if (server_sock == -1) {
std::cout << "Error socket(): " << strerror(errno) << std::endl;
return 1;
}

u_short port = atol(argv[2]);
const char * host = argv[1];
sockaddr_insa;
int on = 1;
sa.sin_family = AF_INET;
sa.sin_port = htons(port);
sa.sin_addr.s_addr = inet_addr(host);

if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1) {
std::cout << "Error setsockopt(): " << strerror(errno) << std::endl;
return 1;
}
if (bind(server_sock, (const sockaddr*)&sa, sizeof(sa)) == -1) {
std::cout << "Error bind(): " << strerror(errno) << " on: " << host << ":" << port << std::endl;
return 1;
}
if (listen(server_sock, SERVER_BACKLOG) == -1) {
std::cout << "Error listen(): " << strerror(errno) << std::endl;
return 1;
}
