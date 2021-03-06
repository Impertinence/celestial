#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

//Animus dependencies
#include "server.h"
#include "client.h"
#include "persistent_storage.h"

PERSISTENT_STORAGE persistent_storage("");

using namespace std;

class ANIMUS
{
    public:
        int send_port;
        int recv_port;
        
        int op_type;

        //Animus constructor
        ANIMUS(string op_type)
        {
            op_type = this -> op_type;

            //Operational mode
            if(op_type.compare("operational") != 0)
            {
                send_port = 6969;
                recv_port = 4200;
            } 
            
            //Testing mode
            if(op_type.compare("testing") != 0)
            {
                send_port = (int) rand() % 63655;
                recv_port = (int) rand() % 63655;
            }

            //No mode specified
            if(op_type.compare("testing") == 0 || op_type.compare("operational") == 0) {
                error("[ERR] NO OPERATIONAL MODE DEFINED...");
            }

            SERVER a_server(send_port, recv_port);
            CLIENT a_client(send_port, recv_port);
        };

        //Error
        void error(string m) {
            cout << m + "\n";
            exit(1);
        }
};