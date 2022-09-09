#include "prgm.h"

void printmenu()
{
	cout << "1. Add patron\n" << "2. Remove patron\n";
	cout << "3. Print list of all patrons\n";
	cout << "4. Print list of patrons with fines" << endl;
	cout << "5. Add book" << "6. Remove Book" << "7. Record lost book"<< endl;
	cout << "8. Checked out books" << "9. Checked in books" << endl;
	cout << "10. Print out overdue books\n" << "11. Save file\n" << "12. Load\n";
	cout << "Press 0 to quit" << endl;
}

void  books :: add_book()
{
	cout << "Enter Book Name: ";
	cin >> bookname;
	cout << "Enter Book ID: ";
	cin >> booknum;
}

void members :: add_member()
{
	cout << "Enter member ID: ";
	cin >> member_id;
	cout << "Enter name of Member: ";
	cin >> member_name;
	counter = 0;
//	memberbookcheck[0] = '/0';
}
void savefile()
{
	ofstream ou_s;
	ifstream in_s;
	books bk; //calling class books
	members mem; //callint class members
	int more; //add more books
	ou_s.open("books.txt");
	if(ou_s.fail())
	{
		cout <<"Onput file opening failed.\n";
                exit(EXIT_FAILURE);//exit if cannot open file

	}
	do
	{
		bk.add_book();
		ou_s.write((char *)&bk,sizeof(members));
		cout << "Enter 1 to add more books: ";
		cin >> more;
	}while(more == 1);
	ou_s.close();


	ou_s.open("members.txt");
        if(ou_s.fail())
        {
                cout <<"Onput file opening failed.\n";
                exit(EXIT_FAILURE);//exit if cannot open file

        }
        do
        {
                mem.add_member();
                ou_s.write((char *)&mem,sizeof(members));
                cout << "Enter 1 to add more members: ";
                cin >> more;
        }while(more == 1);
        ou_s.close();
}

void members :: delete_member()
{
	ofstream on_s, on_s2;
	ifstream in_s;
	members mem;

	char id[20];
	int flag = 0;

	cout << "Enter Name of Member to Delete: ";
	cin >> id;

	in_s.open("members.txt");
	if(in_s.fail())
	{
		cout << "Input file opening failed.\n";
		exit(EXIT_FAILURE);//exit if cannot open file
	}
	on_s.open("temp.txt");
	if(on_s.fail())
	{
		cout << "Input file opening failed.\n";
                exit(EXIT_FAILURE);//exit if cannot open file
	}
	in_s.seekg(0,ios::beg);
	while(in_s.read((char*)&mem, sizeof(members)))
	{
		if(strcmp(mem.Id_number(),id) !=0)
		{
			on_s.write((char*)&mem, sizeof(members));
		}
		else
		{
			flag =1;
		}
	}
	on_s.close();
	in_s.close();
	remove("members.txt");
	rename("temp.txt", "members.txt");





}
