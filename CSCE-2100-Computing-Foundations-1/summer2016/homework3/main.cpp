#include "Node.h"
#include "BST.h"
#include <iostream>

using namespace std;

int main(void){
	int val, choice;
	Node nptr;
	bst bptr;
	cout << "Pick option" << endl;
	cout << "1. Add number to tree" << endl << "2. Search tree" << endl << "3. Delete tree" << endl;
	cout << "4. to quit" << endl;

	cin >> choice;
	while (choice != 4) {
		switch (choice) {
		case 1:
			cin >> val;
			bptr.insert(val);
			cin >> choice;
			break;
		case 2:
			cin >> val;
			bptr.find(val);
			cin >> choice;
			break;
		case 3:
			cin >> val;
			bptr.remove(val);
			cin >> choice;
			break;
		default :
			cout << "Incorrect choice please try again: ";
			cin >> choice;
			break;
		}
	}
}
