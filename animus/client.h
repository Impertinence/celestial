#ifndef client_h
#define client_h

#include <string.h>
#include <cstring>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <strings.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

void error(std::string m)
{
    std::cout << "[ERR]: " << m << std::endl;
    exit(EXIT_FAILURE);
};

class CLIENT
{
    public:
        int listen_fd, send_port, recv_port;
        bool loop = false;
        struct sockaddr_in srv_addr;
        struct hostent *srv;

        CLIENT(int send_port, int recv_port)
        {
            this -> send_port = send_port;
            this -> recv_port = recv_port;

            listen_fd = socket(PF_INET, SOCK_STREAM, 0);

            if(listen_fd < 0)
            {
                error("TROUBLE OPENING SFD...");
            }
        };
};

#endif