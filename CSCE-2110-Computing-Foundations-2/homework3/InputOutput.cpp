#include "InputOutput.h"

vector<string> getInput()
{
    vector<string> dictionary;
    dictionary.reserve(60000);
    string filename;
    fstream inputFile;
    string line;
    int count = 0;
    cout << "Enter file name: " << endl;
    cin >> filename;
    inputFile.open(filename);
    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            // double check with cse machines *************************************************************************
            line.pop_back();
            dictionary.push_back(line);
            count++;
        }
    } else
    {
        cout << "File not found. Closing program." << endl;
        exit(EXIT_FAILURE);
    }
    return dictionary;
}

bool Adjacent(string& x, string& y)
{
    int count = 0;
    int n = x.length();

    for (int i = 0; i < n; i++){
        if (x[i] != y[i]) count++;
        if (count > 1) return false;
    }
    return count == 1;
}

vector<vector<int> > buildAdjacencyList(vector<string>& dictionary)
{
    vector<vector<int> > adjacencyList;
    adjacencyList.resize(dictionary.size());
    cout << "Building adjacency list..." << endl;
    cout << setprecision(2);
    cout << fixed;
    for(int i = 0; i < dictionary.size(); i++)
    {
        adjacencyList[i].push_back(i);
    }
    for(int i = 0; i < dictionary.size(); i++)
    {
        for(int j = i+1; j < dictionary.size(); j++)
        {
            if(dictionary[adjacencyList[i][0]].length() == dictionary[j].length())
            {
                if(Adjacent(dictionary[adjacencyList[i][0]], dictionary[j]))
                {
                    adjacencyList[i].push_back(j);
                    adjacencyList[j].push_back(i);
                }
            }
        }
        cout.flush();
        cout << '\r' << (float(i) / dictionary.size()) * 100 << '%';
    }
    cout << endl << "Adjacency list complete. " << endl;
    return adjacencyList;
}
void get_BFS_Path(int currentNode, vector<int> &predecessor,  vector<vector<int> > &matrixinp, vector<string>& dictionary)
{
    //Exit condition if current node's predecessor is predecessor.size() (not a valid node)
    if(predecessor[currentNode]== -1)
    {
        cout << dictionary[currentNode];
        return;
    }
    //Increment the time of propagation by the endge between the current node and its predecessor
    //Recursive call to output the parent node before the successor
    get_BFS_Path(predecessor[currentNode], predecessor, matrixinp, dictionary);
    cout << " -> " << dictionary[currentNode];
}

void BFS(vector<vector<int> > adjacencyList, string stringSourceNode, string stringDestinationNode, vector<string>& dictionary)
{
    int sourceNode;
    int destinationNode;
    int wordInDictionary = 0;
    for(int i = 0; i < dictionary.size(); i++)
    {
        if(stringSourceNode == dictionary[i])
        {
            sourceNode = i;
            wordInDictionary++;
        }
        if(stringDestinationNode == dictionary[i])
        {
            destinationNode = i;
            wordInDictionary++;
        }
    }
    if(wordInDictionary < 2)
    {
        cout << "Word not in dictionary." << endl;
        exit(EXIT_FAILURE);
    }

    bool nodeFound = false;
    int currentNode = 0;
    //Stores the nodes to be traversed
    vector<int> queue;
    //Keeps track of each nodes parent node
    vector<int> predecessor(adjacencyList.size(), -1);
    //Keeps track of wether a node has been visited or not
    vector<bool> explored(adjacencyList.size(),false);
    //Adds the source node to the queue and marks it as explored
    queue.push_back(sourceNode);
    explored[sourceNode] = true;
    //Traverses the graph while there are nodes in the queue
    while(queue.size()!=0)
    {
        // Gets the first node from the queue and deletes it
        currentNode = queue.front();
        queue.erase(queue.begin());
        //Check if destination node is reached
        if(currentNode == destinationNode)
        {
            nodeFound = true;
            break;
        }
        //Gets adjecent nodes that are not explored and adds them to the queue
        //Marks them as explored and sets the current node as its predecessor
        for(int i = 0; i < adjacencyList[currentNode].size(); i++)
        {
            if(!explored[adjacencyList[currentNode][i]])
            {
                queue.push_back(adjacencyList[currentNode][i]);
                explored[adjacencyList[currentNode][i]] = true;
                predecessor[adjacencyList[currentNode][i]] = currentNode;
            }
        }
    }
    //Outputs the path and propagation time if the node is found
    if(nodeFound)
    {
        cout << "Path: ";
        get_BFS_Path(currentNode,predecessor,adjacencyList, dictionary);
    }
        //Notifies that no path exists if the node is not found
    else
        cout << "No path exists between " << dictionary[sourceNode] << " and " << dictionary[destinationNode] << endl;
}
