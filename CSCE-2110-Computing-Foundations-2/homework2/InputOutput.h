#ifndef inputOutput_H
#define inputOutput_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
struct Operation
{
    string type;
    vector<string> data;
    string tableName;
};

void getTableInput(const string&);
vector<string> stringDelimiter(const string &, char);
vector<Operation> getInput();
#endif