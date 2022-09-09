#include <iostream>
#include "HASH.h"

vector<HASH*> HASH::hashTables;

HASH::HASH(int size, vector<string>& _scheme, string _name, vector<int>& _template)
{
    keyTemplate = _template;
    name = _name;
    scheme = _scheme;
    table.resize(size);
    hashTables.push_back(this);
}

int HASH::hashFunction(string key)
{
    int hash = 0;
    for (int i = 0; i < key.size(); i++) {
        hash = hash + (int)key[i];
    }
    hash = hash % table.size();
    return hash;
}

bool HASH::INSERT(vector<string> data, string name)
{
    HASH* hash = HASH::getHashTable(name);
    data.push_back(hash->getKey(data));
    int bucket = hash->hashFunction(data.back());
    for(int i = 0; i < hash->table[bucket].size(); i++)
    {
        if(hash->table[bucket][i].back() == data.back())
        {
            cout << "An entry exists with key: " << data.back() << endl;
            return false;
        }
    }
    hash->table[bucket].push_back(data);
    return true;
}

void HASH::WRITE()
{
    for(int n = 0; n < hashTables.size(); n++)
    {
        ofstream outputFile(hashTables[n]->name + "New.txt");
        for(int i = 0; i < hashTables[n]->scheme.size(); i++)
        {
            outputFile << hashTables[n]->scheme[i] << "|";
        }
        outputFile << endl;
        for (int i = 0; i < hashTables[n]->table.size(); i++)
        {
            if (!hashTables[n]->table[i].empty())
            {
                for (int j = 0; j < hashTables[n]->table[i].size(); j++)
                {
                    if(!hashTables[n]->table[i][j].empty())
                    {
                        hashTables[n]->table[i][j].pop_back();
                    }
                    for (int k = 0; k < hashTables[n]->table[i][j].size(); k++)
                    {
                        outputFile << hashTables[n]->table[i][j][k] << "|";
                    }
                    outputFile << endl;
                }
            }
        }
        outputFile.close();
    }
}

HASH *HASH::getHashTable(string name)
{
    if(name == "pokemon")
    {
        return hashTables[0];
    }
    if(name == "trainers")
    {
        return hashTables[1];
    }
}

bool HASH::UPDATE(vector<string> data, string name)
{
    HASH* hash = HASH::getHashTable(name);
    data.push_back(hash->getKey(data));
    int bucket = hash->hashFunction(data.back());

    for(int i = 0; i < hash->table[bucket].size(); i++)
    {
        if(hash->table[bucket][i].back() == data.back())
        {
            hash->table[bucket][i] = data;
            return true;
        }
    }
    cout << "Entry not in table. Key: " << data.back() << endl;
    return false;
}

bool HASH::DELETE(vector<string> data, string name)
{
    HASH* hash = HASH::getHashTable(name);
    vector<location> result = HASH::SEARCH(data, hash);
    bool entryExists = false;
    for(int i = 0; i < result.size(); i++)
    {
        hash->table[result[i].i][result[i].j].clear();
        entryExists = true;
    }
    if(entryExists)
        return true;
    else
    {
        cout << "No rows match DELETE query" << endl;
        return false;
    }
}

bool HASH::SELECT(vector<string> data, string name)
{
    HASH* hash = HASH::getHashTable(name);
    vector<location> result = HASH::SEARCH(data, hash);
    bool entryExists = false;
    for(int i = 0; i < result.size(); i++)
    {
        for(int k = 0; k < hash->table[result[i].i][result[i].j].size() -1; k++)
            cout << hash->table[result[i].i][result[i].j][k] << "|";
        entryExists = true;
    }
    if(entryExists)
        return true;
    else
    {
        cout << "No rows match SELECT query" << endl;
        return false;
    }
}

string HASH::getKey(vector<string> data)
{
    string keyString;
    for(int i = 0; i < keyTemplate.size(); i++)
    {
        keyString += data[keyTemplate[i]];
    }
    return keyString;
}

vector<location> HASH::SEARCH(vector<string> data, HASH *hash)
{
    vector<location> result;
    for(int i = 0; i < hash->table.size(); i++)
    {
        for(int j = 0; j < hash->table[i].size(); j++)
        {
            if(compareElements(data, hash->table[i][j]))
            {
                location x(i,j);
                result.push_back(x);
            }
        }
    }
    return result;
}

bool HASH::compareElements(vector<string> input, vector<string> tableValue)
{
    for(int i = 0; i < input.size(); i++)
    {
        if(tableValue.empty())
            return false;
        if(input[i].empty())
            return false;
        if(input[i] == "*")
            continue;
        else if(input[i] != tableValue[i])
        {
            return false;
        }
    }
    return true;
}
