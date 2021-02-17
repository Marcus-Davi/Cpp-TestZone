#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{

    map<string, int> o_map;

    o_map.insert(pair<string, int>("Sarah", 10));
    
    o_map.insert(make_pair<string, int>("Felipe", 24));

    o_map.insert(make_pair<string, int>("Abel", 10));
    o_map.insert(make_pair<string, int>("Abel", 15));

    o_map.insert(make_pair<string, int>("Marcus", 28));

    o_map["Davi"] = 50;
    o_map["Davi"] = 30;

    o_map.insert(make_pair<string, int>("Davi", 15));

    unordered_map<string, int> u_map;

    u_map.insert(pair<string, int>("Sarah", 10));
    
    u_map.insert(make_pair<string, int>("Felipe", 24));

    u_map.insert(make_pair<string, int>("Abel", 10));
    u_map.insert(make_pair<string, int>("Abel", 15));

    
    u_map["Davi"] = 2;
    u_map["Davi"] = 5;

    // u_map.insert(make_pair<string, int>("Marcus", 28));
    

    // u_map["Forte"]  = 313;
    u_map.insert(make_pair<string, int>("Forte", 313));

u_map["Marcus"] = 22;

    for (auto it : o_map)
    {
        cout << it.first << "," << it.second << endl;
    }
    cout << endl << "UMAP" << endl << endl;
    for (auto it = u_map.begin(); it!= u_map.end(); ++it)
    {
        cout << it->first << "," << it->second << endl;
    }

    return 0;
}