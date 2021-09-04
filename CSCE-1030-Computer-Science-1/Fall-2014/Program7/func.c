#include "prgm.h"

void personal (void)
{
                         /*display student information*/
        printf("+-------------------------------------------------------------------+\n");
        printf("|                 Computer Science and Engineering                  |\n");
        printf("|                  CSCE 1030 - Computer Science I                   |\n");
        printf("|   Ricardo Alberto Garza     rag0175    RicardoGarza3@my.unt.edu   |\n");
        printf("+-------------------------------------------------------------------+\n\n");
}

void intro (int message)            /*The welcome message*/
{
	char choice[10]=" ";
	printf("                     Welcome to Battleship!!              \n ");
	printf("Enter difficulty level of game (easy, normal, hard): ");
	scanf("%s", choice);
	printf("\n");
	if (strcmp(choice, "easy") == 0)
	{
		printf("+------------------------------------------------------------+\n");
		printf("| The computer program will randomly assigns an aircraft car-|\n");
		printf("| rier and a battleship, that are oriented either vertically |\n");
		printf("| or horizontally, to the board. You will have 30 chances to |\n");
		printf("| sink both the computer's aircraft carrier and battleship!! |\n");
		printf("| You'll play on a 10 x 10 board, where the aircraft carrier |\n");
		printf("| will have a length of 5x units and the battleship will have|\n");
		printf("| a length of 4 units.                                       |\n");
		printf("+------------------------------------------------------------+\n");

		printf("Initializing board... now let's begin!\n\n\n");
	}
	if (strcmp(choice, "normal") == 0)
        {
                printf("+------------------------------------------------------------+\n");
                printf("| The computer program will randomly assigns an aircraft car-|\n");
                printf("| rier and a battleship, that are oriented either vertically |\n");
                printf("| or horizontally, to the board. You will have 25 chances to |\n");
                printf("| sink both the computer's aircraft carrier and battleship!! |\n");
                printf("| You'll play on a 10 x 10 board, where the aircraft carrier |\n");
                printf("| will have a length of 5 units and the battleship will have |\n");
                printf("| a length of 4 units.                                       |\n");
                printf("+------------------------------------------------------------+\n");

		printf("Initializing board... now let's begin!\n\n\n");
        }
	if (strcmp(choice, "hard") == 0)
        {
                printf("+------------------------------------------------------------+\n");
                printf("| The computer program will randomly assigns an aircraft car-|\n");
                printf("| rier and a battleship, that are oriented either vertically |\n");
                printf("| or horizontally, to the board. You will have 20 chances to |\n");
                printf("| sink both the computer's aircraft carrier and battleship!! |\n");
                printf("| You'll play on a 10 x 10 board, where the aircraft carrier |\n");
                printf("| will have a length of 5 units and the battleship will have |\n");
                printf("| a length of 4 units.                                       |\n");
                printf("+------------------------------------------------------------+\n");

		printf("Initializing board... now let's begin!\n\n\n");
        }
}
void showBoard(int **board)/*Displays the 10x10 board*/
{
	int i;
	int j;
	printf("   1 2 3 4 5 6 7 8 9 10\n"); /*Will display the number of colums*/
	printf("  +---------------------+\n");
	for(i=0; i<SIZE; i++)
	{
               	printGridRow(i);

		for(j=0; j<SIZE; j++)
		{
			switch (board[i][j])
			{
			case 0:/*print black space for open location*/
				printf("  ");
				break;
			case 4:/*Battleship*/
				printf("  ");
				break;
			case 5:/*Aircraft carrier*/
				printf("  ");
				break;
			default:
				printf("Unknown value for board[%d][%d] : %d. Terminating program.\n", i, j, board[i][j]);
				exit(1);
			}
		}
		printf("|\n");
	}
	printf("  +---------------------+\n");

}

int ships(int **board, int shipType)
{
        int valid = 0;  /* use 0 for false (not assigned); otherwise 1 means assigned successfully */
        int i;		/* index used in loop counter as row */
	int j;		/* index used in loop counter as column */
        int vertical;	/* randomly generated ship orientation */
        int shipRowPos;	/* randomly generated row position of ship */
        int shipColPos;	/* randomly generated column position of ship */

        srand(time(NULL));

        vertical   = rand() % 2;	/* randomly generated ship orientation: 1 = vertical, 0 = horizontal */

        shipRowPos = rand() % 10;	/* randomly generated ship row position */ 
        shipColPos = rand() % 10;	/* randomly generated ship column position */

        if (vertical) /* vertical orientation */
        {
		    /* check to see if vertical ship can be placed on board at this location */
                if ((shipRowPos + shipType) < SIZE)
                {
                        /* need check if ship already in this position first */
                        for (i = shipRowPos; i < (shipRowPos + shipType); i++)
                        {
                                if (board[i][shipColPos] != 0)
                                {
                                        /* ship already here, return valid = 0 */
                                        return valid;
                                }
                        }

                        /* ship able to fit vertically on board */
                        valid = 1;

                        /* need assign ship's position on board */
                        for (i = shipRowPos; i < (shipRowPos + shipType); i++)
                        {
                                board[i][shipColPos] = shipType;
                        }
                }
        }
        else /* horizontal orientation */
        {
		    /* check to see if horizontal ship can be placed on board at this location */
                if ((shipColPos + shipType) < SIZE)
                {
                        /* need check if ship already in this position first */
                        for (j = shipColPos; j < (shipColPos + shipType); j++)
                        {
                                if (board[shipRowPos][j] != 0)
                                {
                                        /* ship already here */
                                        return valid;
                                }
                        }

                        /* ship able to fit vertically on board */
                        valid = 1;

                        /* need assign ship's position on board */
                        for (j = shipColPos; j < (shipColPos + shipType); j++)
                        {
                                board[shipRowPos][j] = shipType;
                        }
                }
        }

        return valid;
}


void printGridRow(int i)
{
	  /* based on row integer passed, print out corresponding row letter of board */
        switch (i)
        {
        case 0: printf("A | ");
                break;
        case 1: printf("B | ");
                break;
        case 2: printf("C | ");
                break;
        case 3: printf("D | ");
                break;
        case 4: printf("E | ");
                break;
        case 5: printf("F | ");
                break;
        case 6: printf("G | ");
                break;
        case 7: printf("H | ");
                break;
        case 8: printf("I | ");
                break;
        case 9: printf("J | ");
                break;
        default:printf("Unknown grid row value: %d. Program terminating.\n", i);
                exit(1);
        }
}
/**/
int giveShot(int *column, char *row)
{
	printf("Pick a space to shoot!!\n");
	printf("Row: ");
	scanf("%c", &row[0]);
	row[0]--;

	printf("Column: ");
	scanf("%d", &column[1]);
	column[1]--;
}

