/*
Author: Ricardo Alberto Garza (RicardoGarza3@my.unt.edu)
Date: 11/10/2014
Purpose:Creating a database of grades*/
#include <stdio.h>

int Euid[10], euid2[10];
float hw1[6], hw2[6];
int ex1[5], ex2[5], ex3[5], ex4[5];

int read(int data);			/*Functions that reads in data*/
					/*Can only input up to 2 people*/
int menu(int mainmenu);			/*Gives you the main menu*/

int first(int opt1);			/*Fuction for student grade data*/

int second(int opt2);			/*Function for student grade average*/

int third(int op3);			/*Function for class average*/

int main(void)
{
	int n;
	                        /*display student information*/
	printf("+-------------------------------------------------------------------+\n");
	printf("|                 Computer Science and Engineering                  |\n");
	printf("|                  CSCE 1030 - Computer Science I                   |\n");
	printf("|   Ricardo Alberto Garza     rag0175    RicardoGarza3@my.unt.edu   |\n");
	printf("+-------------------------------------------------------------------+\n\n");
	read(n);/*Calls the read function*/
	menu(n);/*Calls the menu function*/
	return 0;
}
int read(int data)
{
	printf("Please enter the 2 EUID's: ");/*Prompts user for 2 IDs*/
	scanf("%d", Euid);
	scanf("%d", euid2);
	printf("Please enter Homework grade for first student: ");/*Prompts user for homework grade*/
	scanf("%f", hw1);
	printf("Please enter Homework grade for second student: ");
	scanf("%f", hw2);
	printf("Please enter the 2 test grades for first student: ");/*Prompts user for test grades*/
	scanf("%d%d", ex1, ex2);
	printf("Please enter the 2 test grades for second student: ");
	scanf("%d%d", ex3, ex4);

}
int menu(int mainmenu)
{
	int opt, f;
	do{
		printf("Please enter what information you want out of the database\n");
		printf("1. Student Grade Data\n2. Student Grade Average\n");/*Tells user what to input*/
		printf("3. Class Average for an Assignment\n4. Exit\n");
		scanf("%d", &opt);
		switch(opt)
		{
			case 1: printf("Please enter student EUID: \n");
				first(f);/*Calls teh function with student grade data*/
			break;
			case 2: printf("Please enter student EUID: \n");
				second(f);/*Calls the function with student grade average*/
			break;
			case 3: printf("Please enter the assignment Homework, Exam1, or Exam2: \n");
				third(f);/*Calls function with class average for assingments*/
			break;
			case 4:
			break;
			default: printf("Not a vaild option\n\n");
			break;
		}
	} while(opt !=4);/*Switch will run as long as you dont choose option 4*/
}
int first(int opt1)
{
	int i;
	scanf("%d", &i);
	if (i == *Euid)
	{
		printf("EUID: %d\n", *Euid);/*Prints out the value for Euid*/
		printf("Homwork: %.2f\nExam 1: %d\nExam 2: %d\n", *hw1, *ex1, *ex2);/*Prints out other values*/
	}
	if (i == *euid2)
	{
		printf("EUID: %d\nHomework: %.2f\n", *euid2, *hw2);/*Prints out Euid homework, and exam grades*/
		printf("Exam 1: %d\nExam 2: %d\n", *ex3, *ex4);
	}
	if (i != *Euid && i !=*euid2)/*If input doesnt equal values stored in Euid or euid2*/
	{
		printf("Not a Stored EUID");
	}
}
int second(int opt2)
{
	int i;
	double average;
	scanf("%d", &i);
	if (i == *Euid)
	{
		printf("EUID: %d\n", *Euid);			/*If i equals Euid then will print out average and*/
		average = (*hw1*0.5)+(*ex1*0.25)+(*ex2*0.25);   /*there letter grade according to their grade*/
		printf("Grade average: %.2f\n", average);
		if (average >= 89.5)
		{
			printf("Letter Grade: A\n");
		}
		if (average >= 79.5 && average <= 89.49)
		{
			printf("Letter Grade: B\n");
		}
		if(average >= 69.5 && average <= 79.49)
		{
			printf("Letter Grade: C\n");
		}
		if (average <= 69.49)
		{
			printf("Letter Grade: F\n");
		}
	}
	 if (i == *euid2)
	{
		printf("EUID: %d\n", *euid2); /*If i equals Euid then will print out average and*/
		average = (*hw2*0.5)+(*ex3*0.25)+(*ex4*0.25); /*there letter grade according to their grade*/
                printf("Grade average: %.2f\n", average);
                if (average >= 89.5)
                {
                        printf("Letter Grade: A\n");
                }
                if (average >= 79.5 && average <= 89.49)
                {
                        printf("Letter Grade: B\n");
                }
                if(average >= 69.5 && average <= 79.49)
                {
                        printf("Letter Grade: C\n");
                }
                if (average <= 69.49)
                {
                        printf("Letter Grade: F\n");
                }
	}
}
int third(int opt3)
{
	char i, str1[]="Homework", str2[]="Exam1", str3[]="Exam2";/*Defined strings*/
	double average;
	scanf("%c", &i);/*input*/
	if(i == *str1)/*If input equals first string*/
	{
		average = ((*hw1 + *hw2)/2);/*Equation*/
		printf("Homework Class Average: %.2f\n", average);
	}
	if (i == *str2)/*If input equals second string*/
	{
		average = ((*ex1 + *ex3)/2);/*Equation*/
		printf("Exam 1 Class Average: %.2f\n", average);
	}
	if (i == *str3)/*If input equals third string*/
	{
		average = ((*ex2 + *ex4)/2);/*Equation*/
                printf("Exam 2 Class Average: %.2f\n", average);
	}
	if(i != *str1 && i != *str2 && i != *str3);/*If input doesnt equal any strings do this*/
	{
		printf("Don't understand word please retype\n");
	}
	return 0;
}
