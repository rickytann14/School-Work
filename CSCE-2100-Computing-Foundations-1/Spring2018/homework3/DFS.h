#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include "adjMatrix.h"

using namespace std;

void Depth_search(int first_num, int dest_num, vector<vector<int> > matrix);

void DFS_path(int currentnode, int &propagationTime, vector<vector<int> >matrixinp, vector<int> &predecessor);
