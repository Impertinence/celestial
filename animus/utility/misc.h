#include <iostream>    
#include <cstring>      
#include <errno.h>      
#include <sys/socket.h>
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <unistd.h>  

using namespace std;

void error(string m)
{
    cout << "[ERR]: " << m << endl;
    exit(EXIT_FAILURE);
};

class MISC
{
    public:
        //Get Local IP of machine
        string getLocalIP() 
        {
            int sock = socket(PF_INET, SOCK_DGRAM, 0);
            struct sockaddr_in loopback;

            if(sock < 0) {
                error("TROUBLE CREATING SOCKET");
            }

            memset(&loopback, 0, sizeof(loopback));
            loopback.sin_family = AF_INET;
            loopback.sin_addr.s_addr = 1337;
            loopback.sin_port = htons(9);

            
        };
        
        //Get Public IP of machine
        string getPublicIP() 
        {
            
        };
};