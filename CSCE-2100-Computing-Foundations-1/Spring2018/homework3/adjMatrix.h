#ifndef adjMatrix_h
#define adjMatrix_h

/*
Name: Jacob Roquemore
Class: CSCE 2100.001
Email: JacobRoquemore@my.unt.edu

Outline: This is Jacob's contribution to both the file input from a file representing the graph of a network, as well as the file output
of an adjacency matrix representing this graph.
*/

#include <vector>
#include <string>

using namespace std;

//Creating a nodepair class that represents the connection between a starting node, an ending node, and the delay
class nodepair
{
private:
        int startnode;
        int endnode;
        int delay;

public:
        /*A default constructor that has the parameters for a starting node, a connected/end node, and the propagation
          delay between the two nodes*/
        //fstartnode stands for file startnode,  fendnode for file end node, etc.
        nodepair(int fstartnode, int fendnode, int fdelay);
        //Functions to get a start node, end node (or the connected node), and their delay
        int getstartnode();
        int getendnode();
        int getdelay();
};

//Creating a path class that represents a starting node, and the node that needs to be found from a path between the two
class path
{
private:
        int startnode;
        int endnode;
public:
        //Creating a default constructor that has a start node, and endnode to find as parameters
        path(int fstartnode, int fendnode);

        //Functions that will return the start node, and the end node to find in a path
        int getstartnode();
        int getendnode();
};

//Creating a class called pairs and paths that will store the node pair list and paths list from the file input
class pairsandpaths
{
private:
        //Lists to store
        vector <nodepair> pairsresult;
        vector <path> pathsresult;
public:
        //A default class that stores nothing in the node pair and path lists
        pairsandpaths();
        //A default constructor that has the parameters for the nodepair and path lists resulting from the file input
        pairsandpaths(vector <nodepair> inppairs, vector <path> inppaths);

        //Two functions that will return the pairs list and the paths lists
        vector <nodepair> getpairs();
        vector <path> getpaths();
};

//Creating a fileInput function that will return a pairs and paths class which contains the node pair list and path list
pairsandpaths fileInput(int &numnodes, string inpfname);

//Creating a function that will return the sorted adjacency matrix. The parameters is the nodepair list and the number of nodes in the graph
vector <vector<int> > matriceCreationandOutput(vector <nodepair> nodepairinp, int numnodes);


#endif
