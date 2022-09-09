#include "flight.h"
#include "crews.h"
#include "crew.h"
#include "aircraft.h"
#include "aircrafts.h"

Crews lppl;//Crew collction object
Crew pers;//Crew entity object
Aircrafts lcraft;//Aircraft collection object
Aircraft craft;//Aircraft entity object

Flight::Flight(): crewid(){
	tailnum = "none";
	pilotid = 0;
	copilotid = 0;
	num_pass = 0;
	ECode = 0;
	SCode = 0;
	status = "none";
	stime = "none";
	etime = "none";
}

//Dont forget to check status
void Flight::addPilot() {
	int tempid, tempx;//Tempoary storage for ID and variable x

	tempx = lppl.searchCrew(tempx);//Goes to Crew Search fuction
									//Returns number entered in Search 
	if (lppl.gettype(tempx - 1) != "pilot" || lppl.gettype(tempx - 1) != "Pilot") {//Check to see if pilot
		cout << "Error!! Person is not pilot" << endl;
	}
	else {
		if (lppl.getStatus(tempx - 1) != "available" || lppl.getStatus(tempx - 1) != "Available") {//Check to see if crew member is available
			cout << "Pilot is " << lppl.getStatus(tempx - 1) << ". Try someone else" << endl;
		}
		else {
			tempid = lppl.getID(tempx - 1);//Grab Pilot Id 
			pilotid = tempid;//Store id
			cout << lppl.getName(tempx - 1) << " ID number added to flight plan." << endl << endl;
		}
	}
}

//Dont forget to check status
void Flight::addCoPilot(){
	int tempid, tempx;//Tempoary storage for ID and variable x

	tempx = lppl.searchCrew(tempx);//Goes to Crew Search fuction
								   //Returns number entered in Search
	if (lppl.gettype(tempx - 1) != "CoPilot" || lppl.gettype(tempx - 1) != "copilot") {
		cout << "Errpr !! Person is not Copilot" << endl;
	}
	else {
		if (lppl.getStatus(tempx - 1) != "available" || lppl.getStatus(tempx - 1) != "Available") {//Check to see if crew member is available
			cout << "CoPilot is " << lppl.getStatus(tempx - 1) << ". Try someone else" << endl;
		}
		else {
			tempid = lppl.getID(tempx - 1);//Grab Pilot Id 
			copilotid = tempid;//store CoPilot id
			cout << lppl.getName(tempx - 1) << " ID number added to flight plan." << endl << endl;
		}
	}
}

//Dont forget to check status
void Flight::addCrew(){
	int tempid, tempx;//Tempoary storage for ID and variable x

	tempx = lppl.searchCrew(tempx);//Goes to Crew Search fuction
								   //Returns number entered in Search
	for (int i = 0; i < 3; i++) {
		if (lppl.gettype(tempx - 1) != "Cabin" || lppl.gettype(tempx - 1) != "cabin") {//Check to see if cabin crew
			cout << "Error !! Person is not Cabin crew" << endl;
		}
		else {
			if (lppl.getStatus(tempx - 1) != "available" || lppl.getStatus(tempx - 1) != "Available") {//Check to see if crew member is available
				cout << "Cabin member is " << lppl.getStatus(tempx - 1) << ". Try someone else" << endl;
			}
			else {
				tempid = lppl.getID(tempx - 1);//Grab Cabin Crew Id 
				crewid.push_back(tempid);//Store 2 cabin crew id
				cout << lppl.getName(tempx - 1) << " ID number added to flight plan." << endl << endl;
			}
		}
		cout << "Enter another Cabin Crew Number: ";
		cin >> tempx;
		cout << endl;
	}

}

void Flight::addTail(){
	int tempid, tempx;//Tempoary storage for ID and variable x
	string tid;
	tempx = lcraft.searchCraft(tempx);//Goes to list of planes
									  //Returns number entered during search

	if (lcraft.getStatus(tempx - 1) != "in") {//check to see if plane is in
		cout << "Plane is " << lcraft.getStatus(tempx - 1) << endl;
	}
	else {
		tid = lcraft.getTail(tid,tempx - 1);
		tailnum = tid;
	}

}