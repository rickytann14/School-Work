#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

void student(int info);
void process(ifstream& in_stream, ofstream& out_stream);

int main()
{
	int x=1;

	char input_name[32], out_name[32];
	ifstream in_stream;//declaration of the stream of type input
	ofstream out_stream;//declaration of the stream of type output
	student(x);

	cout << "Enter name of input file containing list of popular names: ";
	cin >> input_name;

	in_stream.open(input_name);
	if(in_stream.fail())
	{
		cout <<"Input file opening failed.\n";
		exit(EXIT_FAILURE);//exit if cannot open file

	}

	cout << "Enter name of output file for formatted list of popular names: ";
	cin >> out_name;

	out_stream.open(out_name);
	if(out_stream.fail())
	{
		cout <<"Onput file opening failed.\n";
                exit(EXIT_FAILURE);//exit if cannot open file
	}

	process(in_stream, out_stream);

	in_stream.close();//close the file
	out_stream.close();//close the file

	return 0;
}

void student(int info)
{
	//Displace student information
        cout << "+--------------------------------------------------------+\n";
        cout << "|              Computer Science and Engineering          |\n";
        cout << "|               CSCE 1030 - Computer Science I           |\n";
        cout << "| Ricardo Alberto Garza rag0175 RicardoGarza3@my.unt.edu |\n";
        cout << "+--------------------------------------------------------+\n";

	return;
}

void process(ifstream& in_stream, ofstream& out_stream)
{
	int next, count = 0;
	char c;

	out_stream.width(4);
	out_stream.setf(ios::right);
	out_stream << "Rank";
	out_stream.put(' ');
	out_stream.width(12);
	out_stream.unsetf(ios::right);
	out_stream.setf(ios::left);
	out_stream << "Guys";
	out_stream.width(12);
        out_stream.setf(ios::left);
	out_stream << "Girls";
	out_stream << "\n" << endl;
	while(in_stream.get(c))//read all the numbers one-by-one to the end of the file
	{
		if(isdigit(c))
		{
			count++;
			out_stream.width(4);
			out_stream.setf(ios::right);
			out_stream << endl;
			out_stream.put(c);
			in_stream.get(c);
		}
                if(isalpha(c))
                {
                        out_stream.width(8);
                        out_stream.unsetf(ios::right);
                        out_stream.setf(ios::left);
			out_stream.put(' ');
                        out_stream.put(c);
                }
		if(isspace(c))
                {
                	out_stream << "-";
                }
	}
	return;
}
