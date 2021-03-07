#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

//Animus dependencies
#include "server.h"
#include "gen.h"

//Shard
#include "../monolith/main.h"

using namespace std;

class ANIMUS
{
    public:
        int recv_port;
        int op_type;

        //Animus constructor
        ANIMUS(string op_type)
        {
            op_type = this -> op_type;

            //Operational mode
            if(op_type.compare("operational") != 0)
            {
                recv_port = 4200;
            } 
            
            //Testing mode
            if(op_type.compare("testing") != 0)
            {
                recv_port = (int) rand() % 63655;
            }

            //No mode specified
            if(op_type.compare("testing") == 0 || op_type.compare("operational") == 0) {
                error("NO OPERATIONAL MODE DEFINED...");
            }

            //Check if node identifiers already initialized

            SERVER a_server(recv_port);
        };

        //Error
        void error(string m) {
            cout << "[ERR]: >> " << m << "\n";
            exit(1);
        }
};