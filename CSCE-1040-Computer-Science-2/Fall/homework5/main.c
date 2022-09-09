#include "prgm.h"

int main()
{
	members madd, mdelete;
	books badd;
	int x;
	do
	{
		printmenu();
		cin >> x;
		switch(x)
		{	
			case 0:
				break;
			case 1:
				madd.add_member();
				break;
			case 2:
				mdelete.delete_member();
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				void add_book();
				break;
			case 6:
				void remove_book();
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			case 11:
				savefile();
				break;
			case 12:
				break;
			default:
				cout << "Incorrect choice try again\n";
				break;
			cin >> x;
		}
	}while(x != 0);

	return 0;
}
