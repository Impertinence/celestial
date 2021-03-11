#ifndef client_h
#define client_h

#include <string>
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
    std::cout << "[ERR] >> " << m << std::endl;
};

class CLIENT
{
    public:
        int listen_fd, srv_port;
        bool loop = false;
        struct sockaddr_in srv_addr;
        struct hostent *srv;

        CLIENT(int srv_port, char* srv_ip)
        {
            this -> srv_port = srv_port;

            listen_fd = socket(AF_INET, SOCK_STREAM, 0);

            if(listen_fd < 0)
            {
                error("TROUBLE OPENING SFD...");
                exit(EXIT_FAILURE);
            }

            srv = gethostbyname(srv_ip);

            if(srv == NULL)
            {
                error("TROUBLE CONNECTING TO HOST...");
                exit(EXIT_FAILURE);
            }

            bzero((char *) &srv_addr, sizeof(srv_addr));
            srv_addr.sin_family = AF_INET;

            // std::memmove((char *) srv -> h_addr, (char *) &srv_addr.sin_addr.s_addr, (char *) srv -> h_length);
            std::memmove((char *) srv -> h_addr, (char *) &srv_addr.sin_addr.s_addr, srv -> h_length);

            srv_addr.sin_port = htons(srv_port);

            int checker = connect(listen_fd, (struct sockaddr *) &srv_addr, sizeof(srv_addr));

            //Connection checker
            if(checker < 0)
            {
                error("TROUBLE CONNECTING TO HOST...");
                exit(EXIT_FAILURE);
            }

            for(;;)
            {
                char s[300];
                std::cout << "[ENTER MESSAGE] >> ";
                bzero(s, 301);
                std::cin.getline(s, 300);

                write(listen_fd, s, strlen(s));
            }
        };
};

#endif