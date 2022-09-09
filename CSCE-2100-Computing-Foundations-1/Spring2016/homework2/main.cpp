/*Author: Ricardo A Garza (RicardoGarza3@my.unt.edu)
Date:3/10/2016
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void printtable(int a, int b, string str1, string str2);//output table
void gridrow(int row, string str1);


int main()
{
	int n, m;		//for lists length
	string list1;		//first list
	string list2;		//second list

	cout << ">";
	cin >> list1;		//read in list 1
	cout << ">";
	cin >> list2;		//read in list 2

	//finds length of both list
	n = list1.length();
	m = list2.length();

	//calls function that outputs table
	printtable(n,m,list1,list2);

	return 0;
}


void printtable(int a, int b, string str1, string str2)
{
	//2D array
	int L[a+1][b+1];

	//output file
	ofstream ou_s;
	//opens file called output
	ou_s.open("output.txt");

	if(ou_s.fail())
	{
		cout <<"Onput file opening failed.\n";
                exit(EXIT_FAILURE);//exit if cannot open file
	}
	//from  chapter 6 in the book
	for(int j=0; j<=b;j++)
	{
		L[0][j] = 0;
	}
	for(int i = 1; i<=a; i++)
	{
		L[i][0] = 0;
		for(int j=1; j<=b;j++)
		{
			if(str1[i-1] != str2[j-1])
			{
				if(L[i-1][j] >= L[i][j-1])
				{
				
					L[i][j] = L[i-1][j];
					
				}
				else
				{
					L[i][j] = L[i][j-1];
				}
			}
			else if( str1[i-1] == str2[j-1])
			{
				L[i][j] = 1 + L[i-1][j-1];
			}
		}

	}

	//Make the top border(numbers)
	for(int i=0; i<=(b); i++)
	{
		ou_s << "\t" << i;
	}
	ou_s << endl;

	//Make the top letter border
	ou_s << "\t";

	for(int i = 0; i<(b); i++)
	{
		ou_s << "\t" << str2[i];
	}
	ou_s << endl;

	//Rest of table
	for(int i=0; i<(a+1); i++)
	{
		//Make leftmost border(numbers)
		ou_s << i;
		if(i == 0)
		{
			//puts a blank space next to zero
			for(int j=0; j<=(b);j++)
			{
				ou_s << "\t" <<L[0][j];
			}
		}
		
		
		else if( i >= 1)
		{	//Print out left string border
			ou_s << str1[i-1];
		
			//Prints out table
			for(int j=0; j<=(b); j++)
			{
				ou_s << "\t" << L[i][j];
			}
		}
		ou_s << endl;				
	}
	ou_s.close();//closes file

	//couters
	int lenth;
	int num1 = a, num2 = b;
	//Strings with lcs
	int arr = L[a][b];
	char lcs[arr+1];
	lcs[arr] = '\0';

	while(num1 > 0 && num2 > 0)
	{	//checks to see if strings are equal
		if(str1[num1-1] == str2[num2-1])
		{
			lcs[arr-1]  = str1[num1-1];
			num1--;
			num2--;
			arr--;
		}//checks if first string is bigger
		else if(L[num1-1][num2] > L[num1][num2-1])
		{
			num1--;
		}
		else//does other wise
		{
			num2--;
		}
//	length = lcs.length();
	}

	cout << "Longest common substring has a lenth of "/* << length <<*/ ":" << lcs<< endl; 
}



