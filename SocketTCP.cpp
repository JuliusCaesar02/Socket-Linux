#include "SocketTCP.h"

SocketTCP::SocketTCP() {
    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
}


void SocketTCP::Bind(int port) {
    //bind
    //metto qua poichè non posso metterlo nel private della classe .h
    struct sockaddr_in address;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    address.sin_family = AF_INET;
    int tmp = bind(sockfd, (struct sockaddr)&address, sizeof(address));
    if (tmp < 0)
        throw std::runtime_error("Cannot bind!");
}
void SocketTCP::Listen(int queue_size) {
    //listen
    int tmp = listen(sockfd, queue_size);
    if (tmp < 0)
        throw std::runtime_error("Cannot listen!");
}
void SocketTCP::Accept() {
    //accept
    / int new_sockfd = sockfd;
    int tmp = accept(new_sockfd, (struct sockaddr)&address, sizeof(address));
    if (tmp < 0)
        throw std::runtime_error("Cannot accept!"); /
        struct sockaddr_in address;
    socklen_t address_len;
    int new_sockfd = accept(this->sockfd, (struct sockaddr*)&address, &address_len);
    if (new_sockfd < 0)
        throw std::runtime_error("Cannot accept!");


}

void SocketTCP::Connect(std::string ip, int port) {
    //connect
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;

    //int inet_pton(AF_INET, server_ip.c_str(), &address.sin_addr.s_addr);
    //unsigned char sin_family: AF_INET per IPV4
    //unsigned char sin_port
    //unsigned char sin_addr: ANADDR ANY
//int tmp = connect(sockfd, const struct sockaddr address, socklen_t address_len);
    int tmp = connect(sockfd, (struct sockaddr)&address, sizeof(address));
    if (tmp < 0)
        throw std::runtime_error("Cannot connect!");
}

void SocketTCP::Send(std::string msg) {
    //send
    int tmp = send(sockfd, msg.c_str(), msg.length(), 0);    //c_str() è usato solo per la lettura
    if (tmp < 0)
        throw std::runtime_error("Cannot send!");
}
std::string SocketTCP::Receive() {
    //receive
    int tmp = read(sockfd, this->buffer, sizeof(this->buffer));

    std::string msg_ricevuto(buffer);

    if (tmp < 0)
        throw std::runtime_error("Cannot read!");

    return "msg_ricevuto";
}
void SocketTCP::Close() {
    //close 
    int tmp = close(sockfd);
    if (tmp < 0)
        throw std::runtime_error("Cannot close!");
}