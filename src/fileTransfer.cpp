#include "fileTransfer.hh"

int fileTransfer::determinePacketSize()
{

    if (_numberPacket > 0)
    {
        if (_numberPacket != 1)

        {
            /* Determine the modulo from size of file and number of packets */
            int tmpModulo = _fileSize % (_numberPacket - 1);

            /* Determine the size of packets */
            _packetSize = _fileSize / (_numberPacket - 1);

            /* Determine the size of last packet */
            _lastPacketSize = tmpModulo;
        }
        else
        {
            _packetSize = _fileSize;
            _lastPacketSize = _fileSize;
        }

        return 0;
    }

    return -1;
}

/*
    Open the file. Determine the size of input file and every packet.
*/
void fileTransfer::fileOpen(char *fileName)
{
    _inputFile.open(fileName, std::ifstream::binary | std::ifstream::in);

    if (!_inputFile.is_open())
    {
        perror("Failed to open the file");
        exit(OPEN_FAILED);
    }

    /* Determine the size of file */
    _inputFile.seekg(0, _inputFile.end);
    _fileSize = _inputFile.tellg();

    /* Determine the size of packets */
    if (determinePacketSize() < 0)
    {
        perror("Incorrect number of packets to be sent");
        exit(INCORRECT_NUMBER_PACKETS);
    }

    _inputFile.seekg(0, _inputFile.beg);
}

int fileTransfer::readFile(char packet[], int packetNumber)
{
    /*
        Check the packet number. Size of packet array depends on
        the number of packet. If the given packetNumber is bigger
        than _packetNumber or smaller than one, than function gives
        an notification and returns -1
    */
    if (packetNumber < 1) // 3
    {
        perror("Incorrect packet number");
        return -1;
    }
    if (packetNumber < _numberPacket) // 3 + 3 + (n/_numberPacket + 32)
    {
        _inputFile.read(packet, _packetSize);

        _listaPakietow.push(packet, packetNumber, _packetSize); // 32
    }
    else if (packetNumber == _numberPacket)
    {
        _inputFile.read(packet, _lastPacketSize);
        _listaPakietow.push(packet, packetNumber, _lastPacketSize);
    }
    else
    {
        perror("Incorrect packet number");
        return -1;
    }

    /* Checkt the _inputFile flag */
    if (_inputFile.fail())
    {
        perror("Failed to read a packet");
        exit(INCORRECT_NUMBER_PACKETS);
    }

    return 0;
}

int fileTransfer::sendFrame(socketConnection &Connection)
{

    /****************** Send file size *******************/

    int answer_number = 0;

    Connection.server_send_number(_fileSize);

    /* Check the correctness of file size transmission */
    read(Connection.get_socket_descriptor(), &answer_number,
         sizeof(answer_number));

    std::cout << "Odpowiedz numeru: " << htonl(answer_number) << std::endl;

    if (htonl(answer_number) != CORRECT_SENT_FILE_SIZE)
    {
        perror("Faile to send file size");
        exit(CORRECT_SENT_FILE_SIZE);
    }
    /* *************************************************** */

    /* *********** Send the number of packets ************ */

    Connection.server_send_number(_numberPacket);

    read(Connection.get_socket_descriptor(), &answer_number,
         sizeof(answer_number));

    if (htonl(answer_number) != CORRECT_SENT_PACKET_NUMBER)
    {
        perror("Failed to send number of packets ");
        exit(CORRECT_SENT_PACKET_NUMBER);
    }

    /* ***************************************************** */

    /* *********** Send size of each packet **************** */

    /* ************** Normal size of packet **************** */
    Connection.server_send_number(_packetSize);

    /* ************** Size of last packet ****************** */
    Connection.server_send_number(_lastPacketSize);

    /* ***************************************************** */

    read(Connection.get_socket_descriptor(), &answer_number,
         sizeof(answer_number));

    if (htonl(answer_number) != _fileSize)
    {
        perror("Faile to send file size 2");
        exit(CORRECT_SENT_FILE_SIZE);
    }
    return 0;
}

void fileTransfer::sendFile(socketConnection &Connection)
{
    int suma = 0;
    int j = 1;
    int bytes_sent;
    int rozmiarPakietu;

    while (j <= _numberPacket)
    {
        bytes_sent = 0;
        // numerek = numerpakietu[j];

        if (j != _numberPacket)
            rozmiarPakietu = _packetSize;
        else
            rozmiarPakietu = _lastPacketSize;

        char *pakiet = new char[rozmiarPakietu];

        /*
            Read characters to packet. Amount of characters
            determined by size of packet.
         */
        readFile(pakiet, j);

        /* Send packet number */
        Connection.server_send_number(j);

        while (bytes_sent < rozmiarPakietu)
        {
            bytes_sent = Connection.server_send(pakiet, rozmiarPakietu - bytes_sent);
            pakiet = pakiet + bytes_sent;
        }

        j++;

        suma += bytes_sent;
        pakiet = pakiet - bytes_sent;
        delete[] pakiet;
    }

    if (suma != _fileSize)
    {
        perror("Send fault()");
        exit(SIZE_FAULT_SEND);
    }
}

void fileTransfer::sendFileDifferent(socketConnection &Connection) // 30n
{
    int suma = 0;
    int j = 1;
    int bytes_sent;
    int rozmiarPakietu;

    while (j <= _numberPacket) // 3 * (n/_numberPacket + 45) * _numberPacket = 3n + 135
    {
        if (j != _numberPacket)
            rozmiarPakietu = _packetSize;
        else
            rozmiarPakietu = _lastPacketSize;

        char *pakiet = new char[rozmiarPakietu];

        /*
            Read characters to packet. Amount of characters
            determined by size of packet.
         */
        readFile(pakiet, j); // n/_numberPacket + 45
        j++;                 // 3
    }

    j = 1;                                                                // 3
    std::shared_ptr<stackNode<char *>> tmpPtr = _listaPakietow.getHead(); // 5

    while (j <= _numberPacket) // 27n
    {
        rozmiarPakietu = tmpPtr->getNodeSize(); // 6
        char *pakiet = tmpPtr->getElement();    // 6
        bytes_sent = 0;                         // 3

        /* Send packet number */
        Connection.server_send_number(tmpPtr->getNodeNumber()); // const

        while (bytes_sent < rozmiarPakietu) // n/_numberPacket * 3
        {
            bytes_sent = Connection.server_send(pakiet, rozmiarPakietu - bytes_sent);
            pakiet = pakiet + bytes_sent; // 5
        }

        j++; // 3

        suma += bytes_sent;           // n/_numberPacket  * 3;
        pakiet = pakiet - bytes_sent; // n/_numberPacket * 4
        tmpPtr = tmpPtr->getNext();   // 5
        delete[] pakiet;              // n/_numberPacket *2
    }

    if (suma != _fileSize) // 3
    {
        perror("Send fault()");
        exit(SIZE_FAULT_SEND);
    }
}