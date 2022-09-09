/*Author: Ricardo A Garza (RicardoGarza3@my.unt.edu)
Date:2/22/2016
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void move(int i, int j, int k, int n); //Function for moving

ofstream text; //
int main()
{
	int n;
	cin >> n;
	text.open("output.txt");//opens a file called output
	move(0,2,1,n);//calls the function
	text.close();//closes file
	return 0;
}

void move(int i, int j, int k, int n)//from towers of hanoi notes
{
	if(text.fail())
	{
		cout <<"Onput file opening failed.\n";
                exit(EXIT_FAILURE);//exit if cannot open file
	}
	if(n>0)
	{
		move(i,k,j,n-1);//first to second 
		text << i << " -> "<< j << endl;//first to last
		move(k,i,j,n-1);// second to first
		move(i,j,k,n-2);//first to last
		move(j,i,k,n-1);//last to first
	} //if
} //move

