#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 5;	// number of rows and columns for square board

enum Status {INIT = '*', MINE = '@', NUM = '0'};// enum for game board type with supported values

//Struct for row column coordinates
struct Row_Column
{
	int row;
	int col;
};

// function prototypes
void printStudentInfo();
void printIntro(int num_of_mines);
void initBoard(Status board[][SIZE]);
bool assignMine(Status board[][SIZE]);
void dispBoard(Status board[][SIZE], bool reveal);
bool check(Status board[][SIZE], Row_Column& Position);
