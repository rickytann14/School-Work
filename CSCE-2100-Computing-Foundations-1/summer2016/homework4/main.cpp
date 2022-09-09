#include <iostream>
#include "heap.h"
#include "node.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include "process.h"

using namespace std;

int main(void) {
	int prio = 0, run = 0;
	string name;

	ifstream in_stream;
	ofstream out_stream;

//	cout << "Please enter file name: ";
//	cin >> name;

	in_stream.open("input.txt");
	if (in_stream.fail()) {
		cout << "Input file opening failed!! ending program" << endl;
		exit(1);
	}

	while ((prio != EOF) || (run != EOF)){
		in_stream >> prio >> run;
	}
	in_stream.close();

}
