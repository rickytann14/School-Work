/*
Author: Ricardo A Garza (RicardoGarza3@my.unt.edu)
Date: 09/19/2015
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

class library{
	public:
		int booknum;
		int membernum;
};
class items{
	char num[10]; //book number
	char name[50]; //book title
	public:
		void add();
		void remove();
		void info();
};
class books : public items
{
	public:
		books();
		books(add(), remove(), info());
};
class dvd : public items
{
	public:
		dvd();
		dvd(add, remove, info);
};
class Reference : public items
{
	public:
		Reference();
		Reference(add, remove, info);
};
class members{
	char member_id[10]; //member number
	char member_name[50]; //name
	char memberbookcheck[5];
	int counter;
	public:
		void add_member();
		void delete_member();
		void member_info();
		char *Id_number()
		{
			return member_id;
		}
};
class book: public books{
	public:
		void save_books();
		void load_books();
};
class member: public members{
	public:
		void save_books();
		void load_books();
};
void printmenu();
void savefile();
