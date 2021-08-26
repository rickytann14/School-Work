//Header file made for Jorge's BFS by Jacob
#ifndef bfs_h
#define bfs_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

#include "adjMatrix.h"

using namespace std;

void BFS(vector<vector<int> > adjacencymatrix, vector <path> pathstofind);

void get_BFS_Path(int currentNode, vector<int> &predecessor, int &propagationTime, vector<vector<int> > matrixinp);

#endif
