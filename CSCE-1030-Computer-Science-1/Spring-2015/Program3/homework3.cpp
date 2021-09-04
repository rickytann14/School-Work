#include <iostream>
using namespace std;

int integer_check(int odd);          //Checks to see if vaild
int sum(int add_num);		     //Gets the sum
void diamond(int odd, char symbol);  //Function for drawing the function

int main()
{
	//Displace student information
        cout << "+--------------------------------------------------------+\n";
        cout << "|              Computer Science and Engineering          |\n";
        cout << "|               CSCE 1030 - Computer Science I           |\n";
        cout << "| Ricardo Alberto Garza rag0175 RicardoGarza3@my.unt.edu |\n";
        cout << "+--------------------------------------------------------+\n";

	int odd_num, checked;
	int addition;
	char symbol;

	cout << "Please enter a odd number between 1 and 19: ";
	cin >> odd_num;

	//calls function to see if number is valid
	checked = integer_check(odd_num);
	cout << "You entered the number " << checked << endl;

	//calls function to add up all the numbers
	addition = sum(odd_num);
	cout << "The sum of the integers from 1 to " << checked << " is "
		<< addition << endl;

	//Promps for a character
	cout << "Please enter a printable character: ";
	cin >> symbol;

	diamond(odd_num, symbol);
	return 0;
}

//Function for find out if vaild number
int integer_check(int odd)
{
	//checks to see if between 1 and 19
	if((odd >= 1) && (odd <= 19))
	{
		//checks to see if it is an odd number
		while (odd%2 == 0)
		{
			cout << "Invalid Entry - Please enter an ODD number "
				<<"in range 1 to 19: ";
			cin >> odd;
		}
	}
	else
	{
		cout << "Invalid Entry - Please enter a number between 1 and 19: ";
		cin >> odd;
	}
	return odd;
}

int sum(int add)
{
	int i = 1;
	int result;

	//Formula for finding out the sum of all the numbers up to tha number entered
	result = (add * (add + i) /2) - (i * (i-i)/2);

	return result;
}

void diamond(int odd, char symbol)
{
	//Counters
	int i,j,k;

	//Determines the number of rows on top part of diamond
	for(i = 0; i <= (odd-i)+1; i++)
	{
		//Determines amount of blank space
		for(j = odd-i; j >= 1; j--)
		{
			cout << " ";
		}
		//Determines amount of characters to be printed
		for(k = 1; k <= (2*i-1); k++)
		{
			cout << symbol;
		}
		cout << endl;
	}
	//Determines the number of rows on bottom part of diamond
	for(i=(odd-i)+1; i>=1; i--)
	{
		 //Determines amount of blank space on bottom part
		for(j=1; j<=odd-i; j++)
		{
			cout << " ";
		}
		//Determines amount of characters to be printed on bottom part
		 for(k = 1; k <= (2*i-1); k++)
                {
                        cout << symbol;
                }
		cout << endl;
	}
	//Does not return anything
	return ;
}
