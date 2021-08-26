#include "adjMatrix.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;
//Change made here. Added a matrix parameter
void get_BFS_Path(int currentNode, vector<int> &predecessor, int &propagationTime, vector<vector<int> > matrixinp)
{
    if(predecessor[currentNode]==predecessor.size())
    {
        cout << currentNode + 1;
        return;
    }
    propagationTime+=matrixinp[(predecessor[currentNode])][currentNode];
    get_BFS_Path(predecessor[currentNode], predecessor, propagationTime, matrixinp);
    cout << " -> " << currentNode + 1 ;
}

//Change made here. Made parameters for the adjacency matrix and for the paths to find
void BFS(vector<vector<int> > adjacencymatrix, vector <path> pathstofind)
{
    //Small change made by jacob here. Made the matrix from the original file equal to the adjacency matrix
    vector<vector<int> > matrix = adjacencymatrix;

    bool nodeFound = false;
    int currentNode = 0;
    int previousNode = 0;
    int propagationTime = 0;
    int sourceNode = 0;
    int destinationNode = 0;
    vector<int> queue;

    vector<int> predecessor(matrix.size(),matrix.size());
    vector<bool> explored(matrix.size(),false);

    /*Change made here. Simply moved content from original file into a for loop*/
      for(int i = 0; i < pathstofind.size(); i++)
      {
              /*Change made here.
                Cleared the all of the lists except for the adjacency matrix after each run*/
              queue.clear();
              predecessor.clear();
              explored.clear();

              /*This will reset the propagationTime and the nodeFound
                boolean value after each run has finished*/
              propagationTime = 0;
              nodeFound = false;

              /*Change made here.
                Resizing the predecessor and explored vectors since they were cleared at the top*/
              predecessor.resize(matrix.size(),matrix.size());
              explored.resize(matrix.size(),false);

              /*Change made here. Made the sourceNode and destinationNode integers that were originally parameters for the function call now equal
                to whatever source node and destination node is in the paths list. Also, a -1 value was added to accomdate
                for the differences between the actual nodes, and how the nodes are represented in the adjacencymatrix*/
              sourceNode = (pathstofind[i].getstartnode())-1;
              destinationNode = (pathstofind[i].getendnode())-1;

              queue.push_back(sourceNode);
              explored[sourceNode] = true;

              while(queue.size()!=0)
              {
                  currentNode = queue.front();
                  queue.erase(queue.begin());
                  if(currentNode == (destinationNode))
                  {
                      nodeFound = true;
                      break;
                  }
                  for(int i = 0; i < matrix.size(); i++)
                  {
                      if((matrix[currentNode][i] != 0) && !explored[i])
                      {
                          queue.push_back(i);
                          explored[i] = true;
                          predecessor[i] = currentNode;
                      }
                  }
              }

              if(nodeFound)
              {
                  cout << "Path: ";
                  get_BFS_Path(currentNode,predecessor,propagationTime,matrix);
                  cout << endl << "Propagation Time: " << propagationTime << endl;
              }
              else
                  cout << "No path exists between " << sourceNode+1 << " and " << destinationNode+1 << endl;
      }
}
