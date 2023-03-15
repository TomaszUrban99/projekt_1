#ifndef SOCKET_CONNECTION_HH
#define SOCKET_CONNECTION_HH

/* Libraries for socket operation */

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>

constexpr int PORTNUMBER = 8080;
constexpr int ALLOWED_REPETITIONS = 10;

constexpr int SOCKET_CREATION_FAILED = 1;
constexpr int BIND_FAILED = 2;
constexpr int LISTEN_FAILED = 3;
constexpr int ACCEPT_FAILED = 4;

class socketConnection
{
    struct sockaddr_in address;
    int socket_descriptor;
    int address_len;

public:
    socketConnection &fill_socket_connection();
    int create_socket();
    int server_read(char server_buffer[]);
    int server_send(char *character_to_send[]);
};

#endif