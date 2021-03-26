#include "SocketTCP.h"
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    string ip = argv[2];
    int port = stoi(argv[1]);

    SocketTCP client = SocketTCP();
    client.Connect(ip, port);
    client.Send("ciao");
    client.Receive();
    client.Close();

    return 0;
}