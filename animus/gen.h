#include <iostream>
#include <ctime>
#include <chrono>
#include <sstream>

//Animus files
#include "misc_files/hashing.h"

using namespace std;

class GENERATE
{
    public:
        GENERATE()
        {

        };

        void gen_node() {
            //Get time hash 
            //why the fuck this so complicated lmfao
            time_t raw_time = chrono::system_clock::to_time_t(chrono::system_clock::now());
            stringstream time_container;
            time_container << raw_time;
            string time = time_container.str();

            //Gen unique node identifier
            string node_identifier = get_md5(time);


        };
};