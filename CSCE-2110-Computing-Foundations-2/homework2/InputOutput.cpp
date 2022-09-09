#include "InputOutput.h"
#include "HASH.h"

vector<Operation> getInput()
{
    vector<Operation> listOfOperations;
    string fileName;
    string line;
    fstream inputFile;
    cout << "Enter the name of the input file: " << endl;
    cin >> fileName;
    inputFile.open(fileName);
    while (!inputFile.is_open())
    {
        cout << "File not found. Please try again: " << endl;
        cin >> fileName;
        inputFile.open(fileName);
    }
    getline(inputFile, line);
    do
    {
        getTableInput(line.substr(0, line.find(' ')));
        getline(inputFile, line);
    } while (!line.empty());
    while (getline(inputFile, line))
    {
        size_t endPos = line.find(')');
        size_t startPos = line.find('(');
        Operation operation;
        operation.type = line.substr(0,line.find('('));
        if(operation.type == "WRITE")
        {
            listOfOperations.push_back(operation);
            break;
        }
        operation.data = stringDelimiter(line.substr(startPos+2, endPos -2 - startPos), '|');
        operation.tableName = line.substr(endPos + 2, string::npos);
        operation.tableName.pop_back();
        listOfOperations.push_back(operation);
    }
    return listOfOperations;
}

void getTableInput(const string & fileName)
{
    fstream inputFile;
    vector<string> key;
    vector<int> keyTemplate;
    vector<string> scheme;
    string line;
    inputFile.open(fileName);
    if(inputFile.is_open())
    {
        getline(inputFile, line);
        key = stringDelimiter(line, ',');
        getline(inputFile, line);
        scheme = stringDelimiter(line, ',');
        for(int i = 0; i < scheme.size(); i++)
        {
            for(int j = 0; j < key.size(); j++)
            {
                if(scheme[i] == key[j])
                {
                    keyTemplate.push_back(i);
                }
            }
        }
        new HASH(9, scheme, fileName.substr(0,fileName.length()-4), keyTemplate);
        while (getline(inputFile, line))
        {
            HASH::INSERT(stringDelimiter(line, '|'), fileName.substr(0,fileName.length()-4));
        }
    } else
    {
        cout << "first file could not be opened " << fileName << endl;
    }
}

vector<string> stringDelimiter(const string & line, char delimiter)
{
    size_t startPos = 0, endPos = 0;
    vector<string> delimitedString;
    do
    {
        endPos = line.find(delimiter, endPos);
        delimitedString.push_back(line.substr(startPos, endPos-startPos));
        startPos = ++endPos;
    }while(startPos != 0);
    return delimitedString;
}
