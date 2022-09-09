#include <iostream>
#include <string>
#include <vector>
#include "crews.h"
#include "crew.h"
using namespace std;

Crew person;
Crews::Crews():ppl(){
	crew_count = 0;
}

int Crews::upcount(){
	crew_count++;
	return 0;
}

int Crews::downcount(){
	crew_count--;
	return 0;
}

int Crews::getcount() const{
	return crew_count;
}

string Crews::gettype(int temp){
	return (ppl.at(temp)).getType();
}

int Crews::getID(int temp){
	return (ppl.at(temp)).getID();
}

string Crews::getName(int temp){
	return (ppl.at(temp)).getCName();
}

string Crews::getStatus(int temp){
	return (ppl.at(temp)).getStatus();
}

void Crews::addCrew(){
	string name, postion, avail;
	int num;

	cin.ignore();
	cout << "Enter name: ";
	getline(cin, name);
	person.addCName(name);

	cout << "Enter what type of postion they hold(Pilot, CoPilot, Cabin): ";
	getline(cin, postion);
	person.addType(postion);

	cout << "Enter status(avaiable, sick, on leave): ";
	getline(cin, avail);
	person.addStatus(avail);

	cout << "Enter ID number: ";
	cin >> num;
	person.addIDnum(num);

	upcount();
	ppl.push_back(person);
	cout << endl << endl;
}

int Crews::searchCrew(int temp){
	int tempcnum;

	cout << "Current size of list of crew is: " << crew_count << endl << endl;

	for (int i = 0; i < crew_count; i++) {//Prints a list of all avaliable crew
		if (crew_count == 0) {
			cout << "Error!! No Crew Members!!" << endl;
			return 0;
		}
		else {
			cout << "Member Number: " << i + 1 << " Crew Name: " << (ppl.at(i)).getCName() << endl << endl;
			cout << "Enter the Crew Member Number you want to find: " << endl;
			cin >> tempcnum;

			print(tempcnum);

			return tempcnum;
		}
	}
}

void Crews::print(int temp2){
	if (temp2 < 0 || temp2 > crew_count) {
		cout << "Error!! Member doesn't exist" << endl;
	}
	else {
		cout << "Crew Name: " << (ppl.at(temp2 - 1)).getCName() << endl;
		cout << "Crew ID: " << (ppl.at(temp2 - 1)).getID() << endl;
		cout << "Crew Position: " << (ppl.at(temp2 - 1)).getType() << endl;
		cout << "Crew Status (sick, leave, in): " << (ppl.at(temp2 - 1)).getStatus() << endl;
		cout << endl;
	}
}

void Crews::editCrew(){
	int temid, tempx, opt;
	string temname, temstat, temtype;

	if (crew_count == 0) {
		cout << "Error!! No Crew Members!!" << endl;
	}
	else {
		tempx = searchCrew(tempx);

		cout << "Which one do you wish to edit: " << endl;
		cout << "1. Name" << endl << "2. Type" << endl << "3. Status" << endl;
		cin >> opt;

		switch (opt) {
		case 1:
			cin.ignore();
			cout << "Enter new Name: ";
			getline(cin, temname);
			(ppl.at(tempx - 1)).addCName(temname);
			break;
		case 2:
			cin.ignore();
			cout << "Enter new Type(Pilot, Co-pilot, Attendent): ";
			getline(cin, temtype);
			(ppl.at(tempx - 1)).addType(temtype);
			break;
		case 3:
			cin.ignore();
			cout << "Enter new Status:";
			getline(cin, temstat);
			(ppl.at(tempx - 1)).addStatus(temstat);
			break;
		default:
			cout << "Error!! Please try again: ";
			cin >> opt;
			break;
		}
	}
}

void Crews::deleteCrew(){
	int tdel;

	if (crew_count == 0) {
		cout << "Nothing to delete!!" << endl << endl;
	}
	else {
		tdel = searchCrew(tdel);
		ppl.erase(ppl.begin() + (tdel - 1));
		downcount();
	}
}