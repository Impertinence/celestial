#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string gen_identifier()
{
    //Get time hash 
    //why the fuck this so complicated lmfao
    time_t raw_time = chrono::system_clock::to_time_t(chrono::system_clock::now());
    stringstream time_container;
    time_container << raw_time;
    string time = time_container.str();

    //Gen unique identifier and return
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