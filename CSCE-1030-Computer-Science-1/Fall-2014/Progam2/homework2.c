/*
Author: Ricardo Garza (RicardoGarza3@my.unt.edu)
Date: 9/25/2014
Purpose: Make a calculator that will do addition,
         multiplication and square roots.*/
#include <stdio.h>
#include <math.h>

int main(void)
{
 int number;                                /*Declartion*/
 float final, first, second;                /*Declaration*/
  printf("\nSelect a number\n");            /*propmt for user input*/
  printf("1 Addition\n2 Multiplication\n"); /*user choices*/
  printf("3 Square Root\n4 Exit\n");        /*User choices*/
  scanf("%d", &number);                     /*User input*/
  if (number == 1)
  {
	printf("Enter 2 numbers:\n");       /*Tells user how many*/
	scanf("%f%f", &first, &second);     /*Reads input*/
	final = first + second;             /*Equation*/
 	printf("%.3lf\n", final);           /*Prints result*/
  }
  if (number == 2)
  {
	printf("Enter 2 numbers:\n");
	scanf("%f%f", &first, &second);
	final = first * second;
	printf("%.3lf\n", final);
  }
  if (number == 3)
  {
	printf("Enter 1 number\n");
	scanf("%f", &first);
	final = sqrt(first);
	printf("%.3lf\n", final);
  }
  if (number == 4)                           /*when entered will terminate*/

 return 0;
}
