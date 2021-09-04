
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10

void personal(int info);

void intro (int message);

void showBoard(char**);/*will display the board*/

void ships(char**);/*should display boats*/

int main(void)
{
	int n, i;
	char **board;
	personal(n);
	intro(n);

	srand(time(NULL));

	board = calloc(SIZE, sizeof(char*));/*makes room in memory*/
	for (i = 0; i < SIZE; i++)
	{
		board[i] = calloc(SIZE, sizeof(char));
	}

	ships(board);
	showBoard(board);
	return 0;
}

void personal (int info)
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
	char choice[10];
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
void showBoard(char **board)/*Displays the 10x10 board*/
{
	int r, c;
	char word;
	printf("  1 2 3 4 5 6 7 8 9 10\n"); /*Will display the number of colums*/
	for(r=0; r<10; r++)
	{
		word = 65;
		printf("%c|\n", (word+r));
		for(c=0; c<10; c++)/*Will display the rows*/
        	{				/*will also display the letters.*/
                	board[r][c]=-1;
        	}
	}

}

void ships(char **board)
{
	int i, j, k, l;
	srand(time(NULL));

	i= rand()%SIZE;
	j=rand()%SIZE;

	board[i][j]='B';
	board[i][j-1]='B';
	board[i][j-2]='B';
	board[i][j-3]='B';

	k=rand()%SIZE;/*Check to see if the battleship shows up on the board
			before going on*/
	j=rand()%SIZE;/*Finish the airship*/

	/*board[i][j]='B')//*Have to check every A to make sure it doesnt overlap*/

}


