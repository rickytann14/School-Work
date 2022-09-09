#include <iostream>
#include <string>
#include <vector>
#include "crews.h"
#include "crew.h"
using namespace std;

Crew person;
pilot pi;
copilot copi;
cabin stff;

Crews::Crews():ppl(){
	crew_count = 0;
	pilot_count = 0;
	cabin_count = 0;
	copi_count = 0;
}

int Crews::upcount(){
	crew_count++;
	return 0;
}

void Crews::pup(){
	pilot_count++;
}

void Crews::copup() {
	copi_count++;
}

void Crews::caup() {
	cabin_count++;
}

int Crews::downcount(){
	crew_count--;
	return 0;
}

void Crews::pdown() {
	pilot_count--;
}

void Crews::copdown() {
	copi_count--;
}

void Crews::cadown() {
	cabin_count--;
}

int Crews::getcount() const{
	return crew_count;
}

string Crews::gettype(int temp){
	return (ppl.at(temp+1)).getType();
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
	string name, postion, avail, cpost;
	string post1 = "Pilot";
	string post2 = "CoPilot";
	string post3 = "Cabin";
	int num, fhours;

	cin.ignore();
	cout << "Enter what type of postion they hold(Pilot, CoPilot, Cabin): ";
	getline(cin, postion);
	person.addType(postion);

	if(postion == post1){
		cout << "Enter name: ";
		getline(cin, name);
		person.addCName(name);

		cout << "Enter status(avaiable, sick, on leave): ";
		getline(cin, avail);
		person.addStatus(avail);

		cout << "Enter ID number: ";
		cin >> num;
		person.addIDnum(num);

		cout << "Enter number of flight hours: ";
		cin >> fhours;
		pi.addhours(fhours);

		upcount();
		pup();
		lead.push_back(pi);
		ppl.push_back(person);
		cout << endl << endl;
	}
	else if (postion == post2) {
		cout << "Enter name: ";
		getline(cin, name);
		person.addCName(name);

		cout << "Enter status(avaiable, sick, on leave): ";
		getline(cin, avail);
		person.addStatus(avail);

		cout << "Enter ID number: ";
		cin >> num;
		person.addIDnum(num);

		cout << "Enter number of flght hours: ";
		cin >> fhours;
		copi.addhours(fhours);

		upcount();
		copup();
		flow.push_back(copi);
		ppl.push_back(person);
		cout << endl << endl;
	}
	else if (postion == post3) {
		cout << "Enter name: ";
		getline(cin, name);
		person.addCName(name);

		cout << "Enter status(avaiable, sick, on leave): ";
		getline(cin, avail);
		person.addStatus(avail);

		cout << "Enter Cabin crew postion: ";
		getline(cin, cpost);
		stff.addcpost(cpost);

		cout << "Enter ID number: ";
		cin >> num;
		person.addIDnum(num);

		upcount();
		caup();
		noth.push_back(stff);
		ppl.push_back(person);
		cout << endl << endl;
	}
	else { cout << "NO Postion exist try again or watch Caps!!" << endl; }
}

int Crews::searchCrew(int temp) {
	int tempcnum;

	cout << "Current size of list of crew is: " << crew_count << endl << endl;

	if (crew_count == 0) {
		return 0;
	}
	else {
		for (int i = 0; i < crew_count; i++) {//Prints a list of all avaliable crew with name
			cout << "Member Number: " << i + 1 << " Crew Name: " << (ppl.at(i)).getCName() << endl << endl;
		}

		cout << "Enter the Crew Member Number you want to find: " << endl;
		cin >> tempcnum;//vector[num +1]

		print(tempcnum);//Print from List Class
						//Print from Dervied Classes
		if ((ppl.at(tempcnum - 1)).getType() == "Pilot") {//Is it a pilot?
			for (int i = 0; i < pilot_count; i++) {
				if ((lead.at(i)).getID() == (ppl.at(tempcnum - 1)).getID()) {//Check to see if same person
					(lead.at(i)).print();//Print out rest of data
				}
				else { cout << "Nothing!! Did not work" << endl; }
			}
		}
		else if ((ppl.at(tempcnum - 1)).getType() == "CoPilot") {
			copi.print();
		}
		else if ((ppl.at(tempcnum - 1)).getType() == "Cabin") {
			stff.print();
		}
		return tempcnum;//Return the number entered to find 
						//is vector pos +1
	}
}

void Crews::print(int temp2){
	//Temp2 is vector[pos + 1]
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