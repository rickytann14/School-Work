#include "skiplist.h"
#include "node.h"

int main() {
	int value, choice;

	cout << "Type 1 to insert, 2 to delete , and 3 to search." << endl;
	cout << "Type 0 to quit the program" << endl;
	cin >> choice;
	while (choice != 0) {
		switch (choice) {
			case 1:
				cout << "insert" << endl;
				break;
			case 2:
				cout << "delete" << endl;
				break;
			case 3:
				cout << "search" << endl;
				break;
			default:
				cout << "Invaild choice pick a different number" << endl;
				cin >> choice;
		}
		cout << "Type 0 to quit now or number to contiune.";
		cin >> choice;
	}
	return 0;
}
