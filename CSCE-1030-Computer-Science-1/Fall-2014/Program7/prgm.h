#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

void personal(void);
void intro (int message);
void showBoard(int **board);/*will display the board*/
void printGridRow (int i);
int ships(int **board, int shipType);/*should display boats*/
int giveShot(int *column, char *row);/*Function for shooting*/
