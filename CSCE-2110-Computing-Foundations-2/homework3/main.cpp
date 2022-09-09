#include <iostream>
#include <vector>
#include "InputOutput.h"
int main()
{
    string source;
    string destination;
    vector<string> dictionary;
    vector<vector<int> > adjacencyList;
    dictionary = getInput();
    adjacencyList = buildAdjacencyList(dictionary);
    cout << "Enter source word: " << endl;
    cin >> source;
    cout << "Enter destination word:" << endl;
    cin >> destination;
    BFS(adjacencyList, source, destination, dictionary);
    cout << endl;
    return 0;
}
