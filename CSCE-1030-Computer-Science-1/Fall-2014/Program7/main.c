#include "prgm.h"


int main(void)
{
	int n, i;
	char *row;
	int *column;
	int **board;
	int validLoc = 0;	/* boolean indicating whether or not valid location found to assign ship */
	personal();
	intro(n);

	board = calloc(SIZE, sizeof(int *));/*makes room in memory*/
	for (i = 0; i < SIZE; i++)
	{
		board[i] = calloc(SIZE, sizeof(int));
	}
	/* repeatedly attempt to assign battleship until successful */
        while (!validLoc)
        {
               validLoc = ships(board, 4);
        }

        validLoc = 0;	/* re-initialize valid location to false for aircraft carrier */

	  /* repeatedly attempt to assign aircraft carrier until successful */
        while (!validLoc)
        {
                validLoc = ships(board, 5);
        }

	showBoard(board);
	giveShot(column, row);

	return 0;
}
