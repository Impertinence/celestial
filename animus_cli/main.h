#ifndef main_h
#define main_h

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

using namespace std;

class ANIMUS_CLI {
    public:
        string op_mode;

        ANIMUS_CLI() 
        {
            //Open configuration file
            FILE * conf = fopen("config.aconf", "r");
        };
};

#endif