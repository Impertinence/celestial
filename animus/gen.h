#include <iostream>
#include <ctime>
#include <chrono>
#include <sstream>

//Animus files
#include "misc_files/hashing/picoSHA.h"


using namespace std;

namespace GENERATE
{
    void gen_node() {
        //Get time hash 
        //why the fuck this so complicated lmfao
        time_t raw_time = chrono::system_clock::to_time_t(chrono::system_clock::now());
        stringstream time_container;
        time_container << raw_time;
        string time = time_container.str();

        //Get hash
        vector<unsigned char> hash(picosha2::k_digest_size);
        picosha2::hash256(time.begin(), time.end(), hash.begin(), hash.end());
        string identifier_hash = picosha2::bytes_to_hex_string(hash.begin(), hash.end());

        //Generate a key
    };
};