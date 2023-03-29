#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <memory>
#include "stos_tablica.hh"
#include "stackList.hh"
#include "socketConnection.hh"
#include "fileTransfer.hh"

using namespace std;

int main(int argc, char *argv[])
{
    int n = 5;
    // number of packets

    socketConnection Connection;
    Connection.fill_socket_connection();
    Connection.create_socket();

    int i = 0;
    char NazwaPliczku[] = "Pomiary.ods";
    int suma = 0;

    fileTransfer Transfer(n, NazwaPliczku); // const
    Transfer.fileOpen(NazwaPliczku); // const

    int j = 1;
    int rozmiarPakietu = 0;

    if (!Transfer.sendFrame(Connection)) // const
    {
        std::cout << "Correct send" << std::endl;
    };

    /* Divide into packets and send */

    Transfer.sendFileDifferent(Connection);
    return 0;
}
