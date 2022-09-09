#include "prgm.h"

int main(void)
{
	students loser;
	courses hell;
	grades life;
	int choice;
	loser.student_count=0;
	hell.course_count=0;
	life.grade_count=0;

	do{//Will repeat the menu in till you hit 0

		//Menu
		printf("\n\n\nPlease enter one of the following options\n");
		printf("1. Add a new course\n2. Add a new student\n3. Add a student to course\n");
		printf("4. Add grades for student in a course\n5. Print a list of all the grades for a student in a course\n");
		printf("6. Print a list of all students in a course\n7. Compute the average for a student in a course\n");
		printf("8. Print a list of all courses\n9. Print a list of all students\n");
		printf("10. Compute the average for a course\n11. Store Grade book(to a disk file)\n");
		printf("12. Load Grade book (from a disk file)\n0. Quit\n");

		scanf("%d%*c", &choice);

		switch(choice)
		{
			case 1:
				printf("Case 1 works\n");
				(addcourse(&hell));
				break;
			case 2:
				printf("Case 2 works\n");
				(addstudent(&loser));
				break;
			case 3:
				printf("Case 3 works\n");
				break;
			case 4:
				printf("Case 4 works\n");
				(addgrades(&life, &loser, &hell));
				break;
			case 5:
				printf("Case 5 works\n");
				break;
			case 6:
				printf("Case 6 works\n");
				break;
			case 7:
				printf("Case 7 works\n");
				break;
			case 8:
				printf("Case 8 works\n");
				printcourses(&hell);
				break;
			case 9:
				printf("Case 9 works\n");
				printstudents(&loser);
				break;
			case 10:
				printf("Case 10 works\n");
				break;
			case 11:
				printf("Case 11 works\n");
				break;
			case 12:
				printf("Case 12 works\n");
				break;
			default:
				while(choice>12)
				{
					printf("Incorrect choice please enter a vaild number:");
				}
				break;
		}
	}while(choice!=0);
	return 0;
}

