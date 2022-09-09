#include "aircraft.h"
#include "aircrafts.h"
#include "crew.h"
#include "crews.h"
#include "flight.h"
#include "flights.h"


int main() {
	int choice;
	int pholder = 0;

	Aircrafts pcollect;//Aircraft collection object
	Crews mcollect;//Crew collection object
	Flights fcollect;//Flight collection object

	cout << "----------------------------------------------------" << endl;
	cout << "-Author: Ricardo A Garza (ricardogarza3@my.unt.edu)-" << endl;
	cout << "-Date: 11/12/2017                                  -" << endl;
	cout << "-Insturctor: David Keethly                         -" << endl;
	cout << "-Course: CSCE 1040 Fall 2017                       -" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << endl;

	do{//Menu
		cout << "Please enter one of the following options:" << endl;
		cout << "1. Add Plane" << endl;
		cout << "2. Search for Plane" << endl;
		cout << "3. Edit a plane" << endl;
		cout << "4. Delete plane" << endl;
		cout << "5. Add Crew Member" << endl;
		cout << "6. Search for Crew Member" << endl;
		cout << "7. Edit Crew Member" << endl;
		cout << "8. Delete Crew Member" << endl;
		cout << "9. Add flight" << endl;

		cout << "0. Quit" << endl;

		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 0:
			break;
		case 1:
			pcollect.addCraft();
			break;
		case 2:
			pcollect.searchCraft(pholder);
			break;
		case 3:
			pcollect.editCraft();
			break;
		case 4:
			pcollect.deleteCraft();
			break;
		case 5:
			mcollect.addCrew();
			break;
		case 6:
			mcollect.searchCrew(pholder);
			break;
		case 7:
			mcollect.editCrew();
			break;
		case 8:
			mcollect.deleteCrew();
			break;
		case 9:
			fcollect.addflight();
		
		default:
			if(choice < 0 || choice > 10){ 
				cout << " Entered wrong choice please try again" << endl << endl; 
			}
			else {
				cout << "Error!! Try again:" << endl << endl;
			}
			break;

		}


	} while (choice != 0);
	return 0;
}
