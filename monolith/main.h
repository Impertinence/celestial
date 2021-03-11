#include <iostream>
#include <fstream>
#include <sstream>

#include "misc/picosha.h"

using namespace std;

string gen_identifier()
{
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

    //Return hash
    return identifier_hash;
}

namespace MONOLITH_DB 
{
    //Create database
    void create(string stor_dir)
    {
        
    };

    //Delete a database
    void del(string db_id)
    {

    };
};

namespace MONOLITH_SHARD
{
    //Create a shard
    void create(string db_id, string shard_id) 
    {

    };

    //Delete a shard
    void del(string db_id, string shard_id)
    {

    };
};