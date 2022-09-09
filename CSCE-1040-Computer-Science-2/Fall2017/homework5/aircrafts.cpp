#include <iostream>
#include <string>
#include <vector>
#include "aircrafts.h"
#include "aircraft.h"
using namespace std;

Aircraft ride;

Aircrafts::Aircrafts(){
	air_count = 0;
}

int Aircrafts::upcount(){
	air_count++;
	return 0;
}

int Aircrafts::getcount() const{
	return air_count;
}

int Aircrafts::downcount(){
	air_count--;
	return 0;
}

string Aircrafts::getStatus(int temp){
	return (plane.at(temp)).getStatus();
}

string Aircrafts::getTail(string temp, int tx){
	temp = (plane.at(tx)).getTailNum();
	return temp;
}

void Aircrafts::addCraft(){
	string brand, type, comp, tail;
	int seats, far;

	cout << "Enter the Model:";
	getline(cin, brand);
	ride.addModel(brand);
	cin.ignore();


	cout << "Enter the Make:";
	getline(cin, type);
	ride.addMake(type);
	cin.ignore();

	cout << "Enter Status (out, in, repair):";
	getline(cin, comp);
	ride.addstatus(comp);
	cin.ignore();

	cout << "Enter the Tail Number:";
	cin >> tail;
	ride.addtail(tail);

	cout << "Enter number of Seats:";
	cin >> seats;
	ride.addseat(seats);

	cout << "Enter the Plane's Range:";
	cin >> far;
	ride.addrange(far);

	upcount();
	plane.push_back(ride);

	cout << endl << endl;
	
}

int Aircrafts::searchCraft(int x){
	int pnum;
	cout << "Current size of list of planes is: " << air_count << endl << endl;//Tells you size of list
	//cout << "Enter Plane number to search :"; 
	//cin >> pnum;

	for (int i = 0; i < air_count; i++) {//Prints a list of all the planes avaiable
		if (air_count == 0) {
			cout << "No planes available" << endl;
			return 0;
		}
		else{
			cout << "Plane number: " << i+1 << " - Tail number: " << (plane.at(i)).getTailNum() << endl;
			cout << endl;

			cout << "Enter Plane number you want to find: ";
			cin >> pnum;
			//call print function for single plane
			print(pnum);

			return pnum;
		}

	}
}

void Aircrafts::print(int num) {

	if (num < 0 || num > air_count) {
		cout << "ERROR" << endl;
	}
	else {//Prints out details of plane
		cout << "Plane Model: " << (plane.at(num - 1)).getModel() << endl;
		cout << "Plane Make: " << (plane.at(num - 1)).getMake() << endl;
		cout << "Plane Tail Number: " << (plane.at(num - 1)).getTailNum() << endl;
		cout << "Plane range: " << (plane.at(num - 1)).getRange() << endl;
		cout << "Plane seat numbers: " << (plane.at(num - 1)).getSeatNum() << endl;
		cout << "Plane status: " << (plane.at(num - 1)).getStatus() << endl;
		cout << endl;
	}
}


void Aircrafts::editCraft(){
	int ed, x, snum;
	string mak, brand, stat;

	if (air_count == 0) {
		cout << "No planes available" << endl;
	}
	else {
		x = searchCraft(x);
		cout << "Which do you wish to edit" << endl;
		cout << "1. Make" << endl << "2. Model" << endl << "3. Seat Numbers" << endl;
		cout << "4. status" << endl;
		cin >> ed;

		switch (ed) {
		case 1:
			cin.ignore();
			cout << "Enter new make:";
			getline(cin, mak);
			(plane.at(x - 1)).addMake(mak);
			cout << endl << endl;
			break;
		case 2:
			cin.ignore();
			cout << "Enter new model:";
			getline(cin, brand);
			(plane.at(x - 1)).addModel(brand);
			cout << endl << endl;
			break;
		case 3:
			cout << "Enter seat numbers:";
			cin >> snum;
			(plane.at(x - 1)).addseat(snum);
			cout << endl << endl;
			break;

		case 4:
			cin.ignore();
			cout << "Enter status:";
			getline(cin, stat);
			(plane.at(x - 1)).addstatus(stat);
			cout << endl << endl;
			break;
		default:
			cout << "Error! Please try again:";
			cin >> ed;
			cout << endl << endl;
			break;
		}
	}
}

void Aircrafts::deleteCraft(){
	int del;
	
	//cout << "Which plane do you wish to delete: ";
	if (air_count == 0) {
		cout << "Nothing to delete" << endl << endl;
	}
	else {
		del = searchCraft(del);
		plane.erase(plane.begin() + (del - 1));
		downcount();
	}

}
