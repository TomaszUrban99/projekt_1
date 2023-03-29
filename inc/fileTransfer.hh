#ifndef FILE_TRANSFER_HH
#define FILE_TRANSFER_HH

#include <iostream>
#include <fstream>

#include "stackList.hh"
#include "socketConnection.hh"

constexpr int OPEN_FAILED = 1;
constexpr int INCORRECT_NUMBER_PACKETS = 2;
constexpr int SIZE_FAULT_SEND = 3;

constexpr int CORRECT_SENT_FILE_SIZE = 10;
constexpr int CORRECT_SENT_PACKET_NUMBER = 12;

class fileTransfer
{
    int _fileSize = 0;
    int _numberPacket = 0;
    int _packetSize = 0;
    int _lastPacketSize = 0;
    char *_fileName;
    std::fstream _inputFile;
    stackList<char *> _listaPakietow;

public:
    fileTransfer(int numerOfPacket, char fileName[])
    {
        _fileName = fileName;
        /*inputFile.open(fileName, std::ifstream::binary);*/
        _numberPacket = numerOfPacket;
    }

    /*
        Access methods

        Only get methods returning the value not reference.
        Attributes are modified only by methods determinePacketSize()
        and fileOpen().
    */

    int getFileSize() { return _fileSize; }
    int getNumberPacket() { return _numberPacket; }
    int getPacketSize() { return _packetSize; }
    int getLastPacketSize() { return _lastPacketSize; }
    char *getFileName() { return _fileName; }

    /*!
       \brief  determinePacketSize()- method for counting the
       size of packets needed to send a file

       Functioning:

       \par At the base of size of the file (_fileSize) and given
       numbers of packets (_numberPacket) method counts the size
       of each packet. The last packet is smaller than the previous
       ones (_packetSize - _fileSize&_numberPacket).

       Modified fields:

         _packetSize
        _lastPacketSize

        \retval
    */
    int determinePacketSize();

    /*!
        \brief fileOpen(char *fileName)- method for opening
        the stream to the input file

        \par char* fileName- array with the name of file
        to which the stream should be opened
    */
    void fileOpen(char *fileName);

    int readFile(char packet[], int packetNumber);

    int sendFrame(socketConnection &Connection);

    void sendFile(socketConnection &Connection);

    void sendFileDifferent(socketConnection &Connection);
};

#endif