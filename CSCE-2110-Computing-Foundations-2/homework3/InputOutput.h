#ifndef PROJECT3_2110_INPUTOUTPUT_H
#define PROJECT3_2110_INPUTOUTPUT_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

vector<string> getInput();
bool Adjacent(string& x, string& y);
vector<vector<int> > buildAdjacencyList(vector<string>&);
void BFS(vector<vector<int> > adjacencyList, string sourceNode, string destinationNode, vector<string>& dictionary);

#endif //PROJECT3_2110_INPUTOUTPUT_H
