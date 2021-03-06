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
#include <time.h>

using namespace std;

string version_number = "1.0.1";

class ANIMUS_CLI {
    public:
        ANIMUS_CLI(int p) 
        {
            //Print Opening Banner
            cout << "=======================\n";
            cout << "CELESTIAL VERSION " << version_number << "\n";
            cout << "=======================";
        };

        void init() {

        }
};

#endif