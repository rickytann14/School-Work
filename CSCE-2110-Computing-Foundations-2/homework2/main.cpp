#include <iostream>
#include <fstream>
#include "InputOutput.h"
#include "HASH.h"

int main()
{
    vector<Operation> operations = getInput();
    for(int i = 0; i < operations.size(); i++)
    {
        if (operations[i].type == "INSERT")
        {
            HASH::INSERT(operations[i].data, operations[i].tableName);
        }
        else if (operations[i].type == "UPDATE")
        {
                HASH::UPDATE(operations[i].data, operations[i].tableName);
        }
        else if (operations[i].type == "DELETE")
        {
                HASH::DELETE(operations[i].data, operations[i].tableName);
        }
        else if (operations[i].type == "SELECT")
        {
                HASH::SELECT(operations[i].data, operations[i].tableName);
        }
        else if(operations[i].type == "WRITE")
        {
            HASH::WRITE();
        }
    }
    return 0;
}
