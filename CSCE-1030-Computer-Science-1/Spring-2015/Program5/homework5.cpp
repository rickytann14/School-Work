#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int NROW = 5;//Number of rows
const int NCOL = 5;//Number of colums

enum Mines{sym1='*', sym2='@'};
void student(int info);//Display student info
void intro(int bomb); //Dispaly introduction message
void initialize(Mines board[][NCOL], int NROW, int bomb);//initialize board and pirnt
void printGridRow(int i); //Print out the rows
void display(Mines board[][NCOL]);//will display the board
bool assign(Mines board[][NCOL], int NROW);//assing mines to board

int main()
{
	Mines board[NROW][NCOL];
	int x=1, mines;
	student(x);//Call student infor function

	cout << "Enter number of mines to place on board (5 - 10): ";
	cin >> mines;

	while((mines < 5) || (mines > 10))
	{// check to see number is between 5 and 10
		cout << "Incorrect number try again: ";
		cin >> mines;
	}
	srand(time(0));

	//Call introduction message function
	intro(mines);
	//Call the board and initialize it
	initialize(board, NROW, mines);
	//Display the board with all the bombs
	display(board);
	return 0;
}

/*
============================================================================
Function : printStudInfo
Description : This function prints the student header information.
============================================================================
*/
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

/*
============================================================================
Function : printIntro
Parameters : integer representing number mines they want on the field
Return : none
Description : This function prints an introductory message to the user, and
gives details about the game including the number of mines they will have on
field.
============================================================================
*/
void intro(int bomb)
{
	cout << "----------------------------------------------------------\n";
	cout << "This computer program will randomly assign " << bomb << " mines to the\n";
	cout << "5 by 5 board. Your objective will be to select ten squares\n";
	cout << "on the board that do not contain mines using the given in-\n";
	cout << "formation from the adjacent squares. The game is over when\n";
	cout << "you either select 10 squares without hitting a mine or you\n";
	cout << "select a square containing a mine.\n";
	cout << "----------------------------------------------------------\n";

	return;
}

/*
============================================================================
Function : printGridRow
Parameters : integer that is the number of rows on the board
Return : none
Description : This function prints the corresponding number for the row.
============================================================================
*/
void printGridRow(int i)
{
	/* based on row integer passed, print out corresponding row letter of board */
	switch (i)
	{
		case 0: cout << "0| ";
		break;
		case 1: cout << "1| ";
		break;
		case 2: cout << "2| ";
		break;
		case 3: cout << "3| ";
		break;
		case 4: cout << "4| ";
		break;
		default: cout << "Unknown grid row value: "<< i << ". Program terminating.\n";
		exit(1);
	}
}

/*
============================================================================
Function : initialize
Parameters : going to pass the array, size, and number of mines
Return : none
Description : This function makes the array and sets them equal to an *
		then calls the function assign.
============================================================================
*/

void initialize(Mines board[][NCOL], int NROW, int bomb)
{
	int count = 1;
	for(int i=0; i < NROW; i++)
	{//for rows
		for(int j=0; j < NCOL; j++)
		{//for columns
			board[i][j] = sym1;//assigns * to location
		}
	}
	while(count <= bomb)
	{//will run the assign function only as many times as needed to place all bombs
		assign(board, NROW);
		count++;
	}
	return;
}

/*
============================================================================
Function : assign
Parameters : going to pass the array, and size
Return : none
Description : This function assigns the mines to random location.
============================================================================
*/
bool assign(Mines board[][NCOL], int NROW)
{
	int i = (rand()%NROW), j = (rand()%NCOL);

	while(board[i][j] != true)
	{
		if(board[i][j] != sym2)
		{//if there isnt a mine will assign mine
			board[i][j] = sym2;
			return true;
		}
		else if(board[i][j] == sym2)
       		{//if there is a mine return false
			i = (rand()%NROW), j = (rand()%NCOL);
		}
	}

}
/*
============================================================================
Function : display
Parameters : going to pass the array
Return : none
Description : This function prints the grid.
============================================================================
*/
void display(Mines board[][NCOL])
{
	cout << "   0 1 2 3 4 \n";
        cout << " +-----------+\n";
        for(int i=0; i < NROW; i++)
        {
                printGridRow(i);
                for(int j=0; j < NCOL; j++)
                {
                        cout << static_cast<char>(board[i][j]) << ' ';
                }
                cout << "|";
                cout << endl;
        }
        cout << " +-----------+\n";
        return;
}
