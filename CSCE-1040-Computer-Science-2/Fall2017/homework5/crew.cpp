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

pilot::pilot(){
	fhours = 0;
	rating = "none";
}

copilot::copilot(){
	fhours = 0;
	rating = "none";
}

cabin::cabin(){
	post = "none";
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

void copilot::addrate(string rat){
	rating = rat;
}

void copilot::addhours(int hrs){
	fhours = hrs;
}

string copilot::getrate() const {
	return rating;
}

int copilot::getHr() const {
	return fhours;
}

void pilot::addrate(string rat){
	rating = rat;
}

void pilot::addhours(int thr){
	fhours = thr;
}

string pilot::getrate() const{
	return rating;
}

int pilot::getHr() const {
	return fhours;
}

void cabin::addcpost(string pos){
	post = pos;
}

string cabin::getPost() const{
	return post;
}

void pilot::print() const{
	cout << "Flight Hours as Pilot: " << getHr() << endl;
	cout << "Rating: " << getrate() << endl;
}

void copilot::print() const{
	cout << "Flight Hours as CoPilot: " << getHr() << endl;
	cout << "Rating: " << getrate() << endl;
}

void cabin::print() const{
	cout << "Cabin crew Postion: " << getPost() << endl;
}