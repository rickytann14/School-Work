#include "DFS.h"
#include "adjMatrix.h"

void DFS_path(int currentnode, int &propagationTime, vector< vector<int> > matrixinp, vector<int>& predecessor){
	if (predecessor[currentnode] == predecessor.size())
	{
		/*Change made here. Added arrow for path output, as well as a +1 to accomdate for the fact that the adjacency matrix
		node's values are 1 less than the actual nodes in the graph*/
		cout << currentnode + 1 << " -> ";
		return;
	}

	propagationTime += matrixinp[(predecessor[currentnode])][currentnode];

	/*Important change made here. The get_BFS_path recursive call will now additionally use the same adjacency
	matrix initially passed to it through matrixinp*/
	DFS_path(predecessor[currentnode], propagationTime , matrixinp, predecessor);
	/*Change made here. Added arrow for path output, as well as a +1 to accomdate for the fact that the adjacency matrix
	node's values are 1 less than the actual nodes in the graph*/
	cout << currentnode + 1 << " -> ";
}
//Depth-first search using a stack
void Depth_search(int first_num, int dest_num, vector< vector<int> > matrix) {			//DFS(startV)and endingV and matrix
	int currentV;
	int pro_time = 0;
	int adjv = 0;
	bool nodesearch = false;

	stack<int> temp;							//tempary stack
	vector<bool> visited(matrix.size(), false); //visited?
	vector<int> seen;						
	vector<int> adjNodes;
	vector<int> predecessor(matrix.size(), matrix.size());

	temp.push(first_num);					//Push startV to stack

	while (!temp.empty()) {					//while ( stack is not empty )

		currentV = temp.top();				// currentV = Pop stack
		visited[currentV] = true;			//"Visit" currentV
		temp.pop();							//Pop Stack

		if (currentV == dest_num) {
			cout << currentV << endl;
			nodesearch = true;
			break;
		}
		for (unsigned int i = 1; i < matrix.size(); i++)//Making ajenceny list for current node
		{
			for (unsigned int j = 1; j < matrix.size(); j++) {
				if (matrix[currentV][i] != 0 && visited[j] == true)
				{
					predecessor[i] = currentV;
					adjNodes.push_back(i);
					seen.push_back(i);
					visited[j] = false;
				}
			}
		}

		if (currentV != seen.back()) {	//  if ( currentV is not in seenSet )
			cout << currentV << endl;
			seen.push_back(currentV);		// Add currentV to seenSet
			
		}
		for (unsigned int i = 0; i < adjNodes.size(); i++) {		// for each vertex adjV adjacent to currentV
			/*for (int j = 0; j < matrix.size(); j++) {
				if (visited[i] == true) {
					adjv = matrix[0][j];
					temp.push(adjv);		// Push adjV to stack
				}
			}*/
			temp.push(adjNodes[i]);
		}
		adjNodes.clear();

		//From BFS file 
		if (nodesearch)
		{
			cout << "Path: ";
			DFS_path(currentV, pro_time, matrix, predecessor);
			//Change made here. These are used to delete the left over arrows from the path output
			//cout << deletearrows << deletearrows << deletearrows;
			cout << endl << "Propagation Time: " << pro_time << endl;
		}
		else
			/*Small change made here. A +1 was added to accomdate for the differences between the actual nodes
			and the nodes in the adjacency matrix*/
			cout << "No path exists between " << first_num << " and " << dest_num << endl;
	}
}