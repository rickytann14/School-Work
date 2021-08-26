/*Names of group members: Jacob Roquemore, Jorge , Ricardo Garza, Jorge Martinez.
Work from each member:
Jacob: File Input, Adjacency Matrix, Adjacency Matrix Output, makefile, main.cpp used to call functions
Jorge: BFS and BFS Output
Ricardo: DFS and DFS output

Description of program: A program that is used to first read in from an input file a number of nodes in a graph,
the connections between nodes in a list of nodepairs, and lastly the paths to find between two nodes. Then the program
will form a two-dimensional sorted adjacency matrix from the information gathered from the file, and then DFS and BFS searches
will be used to see if there is a path from a list of one node to another node.
*/
#include "adjMatrix.h"
#include "bfs.h"
#include "DFS.h"

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
        /*Creating a vector representing the list of nodepairs, or the list of a starting node
          and it's connected node, and the delay between the nodepairs*/
        vector <nodepair> nodepairs;

        /*Creating a vector representing a list of the supposed paths with
          a starting part of the path, and the ending part of the path*/
        vector <path> paths;

        //Creating a class that will later receive a returned nodepair vector and path vector from the file input
        pairsandpaths fileresults;

        //Prompting for and receiving input for the filename
        string filename;

        cout << "What is the name of the file you are testing? Please enter it exactly as it appears" << endl;

        cin >> filename;

        //Setting the number of nodes to initially be 0. Will change
        int numgraphnodes = 0;

        //Setting the pairsandpaths class equal to the returned pairsandpath result returned from fileInput
        fileresults = fileInput(numgraphnodes, filename);

        //Setting the nodepairs list equal to the result from the pairsandpaths class
        nodepairs = fileresults.getpairs();

        //Setting the paths list equal to the result from the pairsandpaths class
        paths = fileresults.getpaths();

        //Creaing a 2-dimensional sorted adjacency matrix that initially has nothing in it
        vector<vector<int> > sortedadjmatrix;

        //Setting the blank 2-dimensional matrix equal to the result from the matriceCreationandOutput class
        sortedadjmatrix = matriceCreationandOutput(nodepairs,numgraphnodes);

      // Calling the BFS function
      BFS(sortedadjmatrix, paths);
      cout << endl;
      for(int i = 0; i < paths.size(); i++)
      {
        Depth_search(paths[i].getstartnode(),paths[i].getendnode(),sortedadjmatrix);
      }
        return 0;
}
