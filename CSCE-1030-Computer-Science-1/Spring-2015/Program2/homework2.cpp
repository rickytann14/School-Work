#include <iostream>

using namespace std;

int main()
{
	//Displace student information
        cout << "+--------------------------------------------------------+\n";
        cout << "|              Computer Science and Engineering          |\n";
        cout << "|               CSCE 1030 - Computer Science I           |\n";
        cout << "| Ricardo Alberto Garza rag0175 RicardoGarza3@my.unt.edu |\n";
        cout << "+--------------------------------------------------------+\n";

	//declareing varibles
	char ops;
	int first, second, result;

	//prompt user for number
	cout << "Please enter a number between -10 and 10: ";
	cin >> first;

	//check to see if it is between -10 and 10
	while((first < -10) || (first > 10))
	{
		//tell user to enter number within range
		cout << "Not within range enter a different number: ";
		cin >> first;
	}
	cout << "You entered " << first << endl;

	//Prompt and read in second number
	cout << "Please enter any other number: ";
	cin >> second;
	cout << "You entered " << second << endl;

	//Prompt and read in the arithemtic operation
	cout << "Please enter an +, -, / or * to perform operation: ";
	cin >> ops;
	cout << "You entered " << ops << endl;

	switch(ops)
	{
		case '+':
			result = first + second;
			cout << "Integer Addition: "<< first << " + "
				<< second << " = " << result << endl;
			break;
		case '-':
			result = first - second;
			cout << "Integer Subtraction: "<< first << " - "
                               << second << " = " << result << endl;
			break;
		case '*':
			result = first * second;
			cout << "Integer Mulitplication: "<< first << " * "
                               << second << " = " << result << endl;
			break;
		case '/':
			if(second == 0)
			{
				cout << "Can not divide by zero.\n";
			}
			else
			{
				result = first / second;
				cout << "Integer Divison: "<< first << " / "
					<< second << " = " << result << endl;
			}
			break;
		default:
			cout << "Enter a different opteration.\n";
	}
	return 0;
}
