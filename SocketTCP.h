#ifndef SOCKETTCP_H
#define SOCKETTCP_H
//ho utilizzato define per segnare che la classe l'ho inclusa
#include <iostream>
#include <string>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 128

class SocketTCP {

private:
    //socket
    int sockfd;
    //gestione
    int port;
    char buffer[MAX_BUFFER_SIZE];

public:
    SocketTCP();
    void Bind(int port);
    void Listen(int queue_size);
    void Accept();
    void Connect(std::string ip, int port);
    void Send(std::string msg);
    std::string Receive();
    void Close();
};

#endif