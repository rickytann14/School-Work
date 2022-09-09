#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string substring(string subs) {
	string temp;
	string::iterator it;
	temp = subs;

	for (unsigned int i = 0; i < temp.length(); i++) {
		if (temp[i] == ':') {
			temp.erase(temp.begin(), temp.end() - (temp.length() - i) + 1);
		}
		if (temp[i] == ',') {
			temp.erase(temp.begin() + i);
			temp.insert(temp.begin() + i, ' ');
		}
	}
//	cout << temp << endl;
	return temp;
}

int main() {
	int asci;//temp
	
	vector<int> uniset, subs1, subs2;			//binary variables
	string per1, per2, vect0;					//text variables
	string textfile, uni, sstring1, sstring2;	//substring variables	
	ifstream infile;							//stream
	char c, ftxt[32];

	//Ask for file name
	cout << "Please enter the name of the text file." << endl;
	cin >> ftxt;

	//open file and check if it exist
	infile.open(ftxt);
	if (infile.fail())
	{
		cout << "Input file opening failed. Going to exit program." << endl;
		exit(EXIT_FAILURE);//exit if cannot open file

	}

	//read in full txt file
	//Read first line of list and store as its own set and keep going
	cin.ignore();
	getline(infile, vect0);
	getline(infile, per1);
	getline(infile, per2);
	/*while (infile.get(c)) {
		//imyfile.get(c);
		textfile += c;
	}*/
	cout << vect0 << endl;
	cout << per1 << endl;
	cout << per2 << endl;
	
	//Making substrings
//	cout << endl << "this is the temp strings" << endl;
	uni = substring(vect0);	
	sstring1 = substring(per1);
	sstring2 = substring(per2);
//	cout << vect0 << endl << endl;

	cout << "These are substrings" << endl;
	cout << uni << endl;
	cout << sstring1 << endl;
	cout << sstring2 << endl;

	infile.close();
	return 0;
}
