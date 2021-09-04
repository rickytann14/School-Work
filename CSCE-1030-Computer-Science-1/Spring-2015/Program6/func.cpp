#include "prgm.h"

/*
 ============================================================================
 Function    : printStudentInfo
 Parameters  : nothing
 Return      : nothing
 Description : This function prints out student information
 ============================================================================
 */
void printStudentInfo()
{
	// display student information
	cout << "     +----------------------------------------------+" << endl;
	cout << "     |       Computer Science and Engineering       |" << endl;
	cout << "     |        CSCE 1030 - Computer Science I        |" << endl;
	cout << "     |   Student Name     EUID    euid@my.unt.edu   |" << endl;
	cout << "     +----------------------------------------------+" << endl;
	cout << endl;

	return;
}

/*
 ============================================================================
 Function    : printIntro
 Parameters  : integer for number of mines
 Return      : nothing
 Description : This function prints out game information, including number of
	           mines, size of board, and objective of the game
 ============================================================================
 */
void printIntro(int num_of_mines)
{
	cout << "----------------------------------------------------------" << endl;
	cout << "This computer program will randomly assign ";
	cout.width(2);
	cout << num_of_mines << " mines to the " << endl;
	cout << SIZE << " by " << SIZE << " board. Your objective will be to select ten squares" << endl;
	cout << "on the board that do not contain mines using the given in-" << endl;
	cout << "formation from the adjacent squares. The game is over when" << endl;
	cout << "you either select 10 squares without hitting a mine or you" << endl;
	cout << "select a square containing a mine.                        " << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << endl;

	return;
}

/*
 ============================================================================
 Function    : initBoard
 Parameters  : enum type for 2D game board array
 Return      : nothing
 Description : This function initializes the game board to its initial values
 ============================================================================
 */
void initBoard(Status board[][SIZE])
{
	// loop through rows
	for (int row = 0; row < SIZE; row++)
	{
		// loop through columns
		for (int col = 0; col < SIZE; col++)
		{
			// assign enum value for '*' to row-column position
			board[row][col] = INIT;
		}
	}
}

/*
 ============================================================================
 Function    : assignMine
 Parameters  : enum type for 2D game board array
 Return      : bool that indicates whether or not mine assignment successful
 Description : This function attempts to assign one single mine to a randomly
	           generated row-column position and returns true if the mine as-
	           signment was successful or false otherwise
 ============================================================================
 */
bool assignMine(Status board[][SIZE])
{
	int row = (rand() % SIZE);	// generate random row in board
	int col = (rand() % SIZE);	// generate random column in board

	// check if mine already present at random row-column position
	if (board[row][col] == INIT)
	{
		// no mine present, so assign mine to location
		board[row][col] = MINE;
		return true;
	}
	else
	{
		// mine already present at location, so just return false
		return false;
	}
}

/*
 ============================================================================
 Function    : dispBoard
 Parameters  : enum type for 2D game board array
 Return      : nothing
 Description : This function displays the game board to the screen
 ============================================================================
 */
void dispBoard(Status board[][SIZE], bool reveal)
{
	cout << "    0 1 2 3 4  " << endl;
	cout << "  +-----------+" << endl;

	// loop through to display row information
	for (int row = 0; row < SIZE; row++)
	{
		cout << " " << row << "|";
		// loop through to display column information
		for (int col = 0; col < SIZE; col++)
		{
			if(reveal == true)
			{
				// display board based on values contained
				if(board[row][col] == '@')
				{
					cout << " " << '*';
				}
				else
				{
					cout << " " << static_cast<char>(board[row][col]);
				}
			}
			else if(reveal != true)
			{
				cout << " " << static_cast<char>(board[row][col]);
			}
		}
		cout << " |" << endl;
	}

	cout << "  +-----------+" << endl;
}

bool check(Status board[][SIZE], Row_Column& Position)
{
	if((board[Position.row][Position.col]) != '@')
	{
		for(int i = Position.row - 1;i <= Position.row + 1; i++)
		{
			for(int j = Position.col - 1;j <= Position.col +1; j++)
			{
				if((i>=0 && i<SIZE) && (j>=0 && j<SIZE))
				{
					if(board[i][j]!= '@')
					{
						if(board[i][j] == '*')
						{
							board[i][j] = NUM;
						}
						else
						{
							board[i=i+1][j=j+1];
						}
					}
				}
			}
		}
		return false;
	}
	else if((board[Position.row][Position.col]) == '@')
	{
		cout << "Sorry, but you hit a mine. You lose" << endl;
		return true;
	}
}
