#include <iostream>
#include "stos_tablica.hh"
#include "stackList.hh"
#include "socketConnection.hh"

using namespace std;

int main(int argc, char *argv[])
{
    char send[] = "Collere";
    int socketDescriptor;
    socketConnection serverConn;

    serverConn.fill_socket_connection();
    socketDescriptor = serverConn.create_socket();
    serverConn.server_read(send);

    cout << send << endl;

    return 0;
}