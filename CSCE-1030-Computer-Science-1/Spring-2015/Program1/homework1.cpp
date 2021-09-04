/*
Author: Ricardo A. Garza (RicardoGarza3@my.unt.edu)
Date:2/09/2015
Instructor: Mark Thomspon
Purpose: To find the volume of the cone and the surface area.
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	//initializing variables and pi and one third
	double volume, area, length;
	double radius, height, pi, one_third;
	string name;

	pi = 3.141592653589793;
	one_third = 1.0/3.0;


	//Displace student information
	cout << "+--------------------------------------------------------+\n";
	cout << "|              Computer Science and Engineering          |\n";
	cout << "|               CSCE 1030 - Computer Science I           |\n";
	cout << "| Ricardo Alberto Garza rag0175 RicardoGarza3@my.unt.edu |\n";
	cout << "+--------------------------------------------------------+\n";

	cout << "\nPlease enter your name: ";
	cin >> name;
	cout << "\nHello, "<< name <<"! Welcome to CSCE 1030!\n";

	//Prompt for intial radius
	cout << "\nPlease enter the radius of the cone: ";
	cin >> radius;

	//Prompt for intial height
	cout << "\nPlease enter the height of the cone: ";
	cin >> height;

	//Sets the decimals places to 8
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(8);

	//Calculate the volume
	volume = (one_third)* pi * pow(radius, 2) * height;

	//Calculate the length to find the surface area
	length = sqrt(pow(radius, 2) + pow(height, 2));

	//Calculate the surface area
	area = (pi * pow(radius, 2)) + (pi) * radius * length;

	//Outputs the volume and surface area
	cout << "The volume of the cone is "<< volume << endl;
	cout << "The surface area of the cone is "<< area << endl;

	return 0;
}
