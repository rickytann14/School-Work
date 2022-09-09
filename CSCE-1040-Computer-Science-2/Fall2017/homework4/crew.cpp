#include <iostream>
#include <string>
#include "crew.h"
using namespace std;

Crew::Crew(){
	cname = "none";
	cstatus = "none";
	ctype = "none";
	cid = 0;
}

void Crew::addCName(string nam){
	cname = nam;
}

void Crew::addType(string ty) {
	ctype = ty;
}

void Crew::addStatus(string stat) {
	cstatus = stat;
}

void Crew::addIDnum(int id){
	cid = id;
}

string Crew::getCName() const{
	return cname;
}

int Crew::getID() const{
	return cid;
}

string Crew::getType() const{
	return ctype;
}

string Crew::getStatus() const{
	return cstatus;
}