#include "prgm.h"

int main()
{
	int    num_of_mines, count;	// number of mines entered by user

	count = 1;
	Status board[SIZE][SIZE];	// game board implemented as enum type

	Row_Column coordinate;

	srand(time(0));		// seed random number generator

	printStudentInfo();	// call function to display student info

	cout << "           Welcome to Minesweeper!             " << endl << endl;

	// prompt for and read in number of mines between 5 and 10, inclusively
	// re-prompted if invalid number entered
	do
	{
		cout << "Enter number of mines to place on board (5 - 10): ";
		cin  >> num_of_mines;
	} while ((num_of_mines < 5) || (num_of_mines > 10));

	cout << endl;

	printIntro(num_of_mines);	// call function to print game information

	cout << "Initializing board...";
	initBoard(board);	// call function to initialize board

	cout << "assigning mines...";

	// loop to assign correct number of mines
	for (int i = 0; i < num_of_mines; i++)
	{
		// loop until assign mine
		while (!assignMine(board))
		{
			// nothing to do here, just make sure it assigns a mine
		}
	}

	cout << "now let's begin..." << endl << endl;;

	dispBoard(board, check);	// call function to display initial game board

	while(count <= 10)
	{

		cout << "Enter position for move #" << count <<" (row[0-4] col[0-4]): ";

		cin >> coordinate.row >> coordinate.col;

		check(board, coordinate);

		dispBoard(board, check);
		count++;
	}
	return 0;
}
