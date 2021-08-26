/*
Name: Jacob Roquemore
Class: CSCE 2100.001
Email: JacobRoquemore@my.unt.edu

Outline: This is Jacob's contribution to both the file input into the graph representing a network, as well as the file output
of an adjacency matrix representing this graph.
*/
#include "adjMatrix.h"

#include <iostream>
#include <fstream>
#include <string>

#include <cstdlib>

#include <vector>


using namespace std;


//A default constructor that has the parameters for a starting node, a connected/end node, and the delay between the two nodes
//fstartnode stands for file startnode,  fendnode for file end node, etc.
nodepair::nodepair(int fstartnode, int fendnode, int fdelay)
{
        //Setting the values of one nodepair class equal to the passed parameter values
        startnode = fstartnode;
        endnode = fendnode;
        delay = fdelay;
}

//Functions to get a start node, end node (or the connected node), and their delay
int nodepair::getstartnode()
{
        return startnode;
}

int nodepair::getendnode()
{
        return endnode;
}

int nodepair::getdelay()
{
        return delay;
}

//A default constructor that has the parameters for the nodepairs and paths lists resulting from the file input
path::path(int fstartnode, int fendnode)
{
        //Setting the values of one path class equal to the passed parameter values
        startnode = fstartnode;
        endnode = fendnode;
}


//Functions that will return the start node, and the end node to find in a path
int path::getstartnode()
{
        return startnode;
}

int path::getendnode()
{
        return endnode;
}


//A default class that stores nothing in the node pairs and paths list
pairsandpaths::pairsandpaths()
{
        pairsresult.reserve(0);
        pathsresult.reserve(0);
}

//A default constructor that has the parameters for the nodepairs and paths lists resulting from the file input
pairsandpaths::pairsandpaths(vector <nodepair> inppairs, vector <path> inppaths)
{
        //Setting the values of the pairsandpaths class equal to the passed parameters
        pairsresult = inppairs;
        pathsresult = inppaths;
}


//Two functions that will return the pairs list and the paths lists
vector <nodepair> pairsandpaths::getpairs()
{
        return pairsresult;
}

vector <path> pairsandpaths::getpaths()
{
        return pathsresult;
}


//Creating a fileInput function that will return a pairs and paths class which contains the node pair list and path list.
/*The parameters passed to it are the number of nodes integer, which will be changed during the function's runtime, and the string
  representing the file name the user has inputted, or string inpfname*/
pairsandpaths fileInput(int &numnodes, string inpfname)
{
        //Creating an input file stream from the user's inputted file name and testing it
        ifstream inpfile;

        inpfile.open(inpfname.c_str());

        if(inpfile.fail())
        {
                cout << "Sorry this file name could not be found. Please enter a correct file name." << endl;
                exit(EXIT_FAILURE);
        }

        //First getting the number of nodes from the top of the file
        inpfile >> numnodes;

        //Making a list of node pairs as a vector
        vector <nodepair> nodepairinput;

        /*A boolean that will stop the loop that
          gathers node pairs and their propagation delay*/
        bool stoppoint = false;

        //Declaring and initizliating an integer to 0 represent the starting vertice in a graph
        int startnode = 0;

        //Declaring and initizliating an integer to 0 represent the connected vertice in a graph
        int endnode = 0;

        //Setting the propagation delay nmumber/ weight equal to 0
        int delay = 0;

        //Until the -1 sentinel value has been hit, this loop will cycle through the file
        while(!stoppoint)
        {
                //Reading in the first value and storing it as a number representing the starting vertice
                inpfile >> startnode;

                /*If the value that is first read in is the -1 sentinel value,
                  then the loop will break */
                if (startnode == -1)
                {
                        stoppoint = true;
                        break;
                }

                /*Reading in the second value on an individual line and
                  storing it as a number representing the connected vertice*/
                inpfile >> endnode;

                //Reading in the propagation delay value and storing it
                inpfile >> delay;

                //Creating an object of the nodepair class with the parameters for the start node, connected node, and propagation delay
                nodepair temp(startnode, endnode, delay);

                //Pushing back in the nodepairinput vector, that represents the list of nodepairs, the node pair from the temporary object
                nodepairinput.push_back(temp);
        }

        //Creating a vector representing the list of nodes that need to have a path found using either DFS or BFS
        vector <path> pathinput;

        //Until the end of the file is reached
        while(!inpfile.eof())
        {
                //Read in the numbers representing the starting position, and the position at the end of the path
                inpfile >> startnode;
                inpfile >> endnode;

                //Creating a temporary object of the path class and passing it the start node and end node parameters
                path temp(startnode, endnode);

                /*Pushing back in the pathinput vector, that represents the list of nodes to find a path for, the starting node and ending node
                  from the temporary object*/
                pathinput.push_back(temp);
        }

        //Remove if unnecessary
        /*
        vector <nodepair> usrnodepair = nodepairinput;

        vector<path> usrpath = pathinput;
        */

        //Creating an object that stores the list of nodepairs and the list of paths that need to be found
        pairsandpaths results(nodepairinput, pathinput);

        //Returning this object to a user
        return results;
}

vector <vector<int> > matriceCreationandOutput(vector <nodepair> nodepairinp, int numnodes)
{
        //A 2-dimensional vector of type int that will be the sorted adjacency matrix
        vector <vector<int> > adjmatrix(numnodes, vector<int>(numnodes));

        /*Resizing this vector to have outer indexes of the number of nodes in the graph,
          as well each of these outer indexes containing inner values up to the number of nodes in the graph, which each
          of these inner values initially being 0*/

        adjmatrix.resize(numnodes, vector<int>(numnodes,0));

        cout << "Adjacency Matrix: " << endl;

        cout << endl;
        //Outputting top row of visual representation of adjacency matrix
        //(A 0 will be outputted by this for loop as a separation between the far left column and the upper row)
        for(int i = 0; i <= numnodes; i++)
        {
                cout << (i) << '\t';
        }

        cout << endl;

        //Cycling through each ith index on the far left column of an adjacency matrix
        for(int i = 0; i < numnodes; i++)
        {
                //Then cycling through the list of node pairs
                for(int j = 0; j < nodepairinp.size(); j++)
                {
                        /*
                        If the starting node/ first node in the node pair list is equal to the ith index we are currently at on the far left column
                        (the +1 is added since we are working with vectors that always start at 0, so the 0th index is counted as 1 in node form,
                        and so and so forth for other nodes), then
                         */
                        if(nodepairinp[j].getstartnode() == (i+1))
                        {
                                /*At the ith position in the adjacency matrix represented by the far left column, and then
                                  at the position under the jth node on the top row of the adjacency matrix,we will store the
                                  propagation delay value*/
                                adjmatrix[i][nodepairinp[j].getendnode()-1] = nodepairinp[j].getdelay();
                                /*Since it is an undirected graph, we will do the same thing for the jth position
                                  in the far left column of the adjacencry matrix as
                                  well as the ith column/position in the top row of the adjacency matrix */
                                adjmatrix[nodepairinp[j].getendnode()-1][i] = nodepairinp[j].getdelay();
                        }
                }
        }


        //Cycles through the adjacency matrix
        for(int i = 0; i < numnodes; i++)
        {
                //Outputting on the far left column the ith node (it is +1 to follow the 1,2,3,4... setup of the nodes)
                cout << i+1 << '\t';

                /*Then cycling through all the indexes next to this ith node
                  under each column of the top row of the adjacency matrix,
                  we output the propagation value*/
                for(int j = 0; j < numnodes; j++)
                {
                        cout << adjmatrix[i][j] << '\t';
                }

                //Putting sufficient space between each row of the adjacency matrix
                cout << endl << endl;
        }

        //Returing the resulting adjacency matrix to the user
        return adjmatrix;
}
