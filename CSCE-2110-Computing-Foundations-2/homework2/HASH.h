#ifndef HASH_H
#define HASH_H
#include <vector>
#include <string>
#include <fstream>

using namespace std;
struct location{
    int i = 0;
    int j = 0;
    location(int _i, int _j)
    {
        i = _i;
        j = _j;
    }
};
class HASH
{
    vector<vector<vector<string> > > table;
    vector<string> scheme;
    vector<int> keyTemplate;
    static vector<HASH*> hashTables;
    int size;
    string name;
    int hashFunction(string key);
    string getKey(vector<string>);

public:
    HASH(int size, vector<string>& _scheme, string _name, vector<int>& _template);
    static HASH* getHashTable(string);
    static bool compareElements(vector<string>, vector<string>);
    static vector<location> SEARCH(vector<string>, HASH *);
    static bool INSERT(vector<string>, string);
    static bool UPDATE(vector<string>, string);
    static bool DELETE(vector<string>, string);
    static bool SELECT(vector<string>, string);
    static void WRITE();
};
#endif