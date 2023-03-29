#include "socketConnection.hh"

socketConnection &socketConnection::fill_socket_connection()
{
    if ((socket_descriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket() failed");
        exit(SOCKET_CREATION_FAILED);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORTNUMBER);
    address_len = sizeof(address);

    if (bind(socket_descriptor,
             (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind() failed");
        exit(BIND_FAILED);
    }

    if (listen(socket_descriptor, ALLOWED_REPETITIONS) < 0)
    {
        perror("listen() failed");
        exit(LISTEN_FAILED);
    }

    return *this;
}

int socketConnection::create_socket()
{
    int new_socket = accept(socket_descriptor,
                            (struct sockaddr *)&address, (socklen_t *)&address_len);

    if (new_socket < 0)
    {
        perror("accept() failed");
        exit(ACCEPT_FAILED);
    }

    socket_descriptor = new_socket;

    return new_socket;
}

int socketConnection::server_read(char server_buffer[])
{
    return read(socket_descriptor, server_buffer, 1000);
}

int socketConnection::server_send(char character_to_send[], int buflen)
{
    int bytesSend = 0;

    bytesSend = send(socket_descriptor, character_to_send,
                     buflen, 0);

    if (bytesSend < 0)
    {
        perror("Send failed()");
        exit(SEND_FAILED);
    }

    return bytesSend;
}

void socketConnection::server_send_number(int number_to_send)
{
    int convertedNumber = htonl(number_to_send);

    if (send(socket_descriptor, &convertedNumber,
             sizeof(convertedNumber), 0) < 1)
    {
        perror("Send failed()");
        exit(SEND_FAILED);
    }
}