#ifndef server_h
#define server_h

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//Animus dependencies
#include "client.h"

using namespace std;

static int conn_fd;
static int MAX_THREADS = 500;

void *task_manager(void *dummyPt) {
    cout << "[THREAD - " << pthread_self() << "]: NODE CONNECTED...";
            
    char test[300];
    bzero(test, 301);
    bool loop = false;

    while(!loop)
    {
        bzero(test, 301);
        read(conn_fd, test, 300);

        cout << "[THREAD - " << pthread_self() << "]: " << test;
    }
}

class SERVER
{
    public:
        int pid, srv_port, send_port, listen_fd;
        socklen_t cli_addr_len; 
        bool loop = false;
        struct sockaddr_in srv_addr, cli_addr;

        pthread_t thread[500];

        //Server initialization
        SERVER(int send_port, int recv_port) 
        {
            this -> srv_port = recv_port;
            this -> send_port = send_port;

            CLIENT a_client();

            listen_fd = socket(AF_INET, SOCK_STREAM, 0);

            bzero((char*) &srv_addr, sizeof(srv_addr));
            srv_addr.sin_family = AF_INET;
            srv_addr.sin_addr.s_addr = INADDR_ANY;
            srv_addr.sin_port = htons(srv_port);

            //Check listen sfd
            if(listen_fd < 0)
                error("[ERR] TROUBLE ESTABLISHING SFD...", false);

            if(bind(listen_fd, (struct sockaddr *) &srv_addr, sizeof(srv_addr)) < 0)
                error("[ERR] TROUBLE BINDING SFD...", false);

            listen(listen_fd, 5);

            cli_addr_len = sizeof(cli_addr);
            int num_thread = 0;

            //Accept connection and create new thread for tasks
            while(num_thread < MAX_THREADS) {
                cout << "[CELESTIAL]" << endl;

                conn_fd = accept(listen_fd, (struct sockaddr *) &cli_addr, &cli_addr_len);

                if(conn_fd < 0) {
                    error("[ERR] TROUBLE ACCEPTING: ", false);
                }

                pthread_create(&thread[num_thread], NULL, *task_manager, NULL);
                num_thread++;
            }

            for(int i = 0; i < MAX_THREADS; i++) {
                pthread_join(thread[i], NULL);
            }
        };

        //Error message
        void error(string m, bool exit_status) 
        {
            cout << m;
            if(exit_status)
                exit(EXIT_FAILURE);
        };
};

#endif