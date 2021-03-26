#include "SocketTCP.h"

int main(int argc, char* argv[])
{
    std::string ip = argv[2];
    int port = stoi(argv[1]);

    SocketTCP server = SocketTCP();
    server.Bind(ip);
    server.Listen(3);
    server.Accept();
    server.Receive();
    server.Send("messaggio ricevuto");
    server.Close();
    return 0;
}