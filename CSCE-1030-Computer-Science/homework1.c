/* Purpose is to input numbers and get max height and time  before,
it hits the ground
Purpose: To find the effect of gravity on an object
Author: Ricardo A Garza*/
#include <stdio.h>
#include <math.h> /* including the math libaray*/

int main()
{
	float height, velocity, max, time;
/*Will display name, email, euid*/
	printf("\nName:Ricardo A. Garza\nEUID:rag0175");
	printf("\nEmail:RicardoGarza3@my.unt.edu");
	printf("\nCourse Number: CSCE1030 Section: 001");
	printf("\nProgram Number: 1\n");

	/*tells user to input numbers*/
	printf("\nEnter intial height of s0 in feet:\n ");
	scanf("%f", &height);/*prompting user for input in height*/

	/*tells user to input numbers*/
	printf("\nEnter intial velocity of v0 in feet/sec:\n");
	scanf("%f", &velocity);/*promptin user for input in velocity*/

/*Equation for max height*/
	max = (((-velocity) * (velocity)) + (4 * (-16* height))) / (4 * -16);
/*Equation for time when height is zero*/
	time = ((-velocity) - sqrt((-velocity * (-velocity)) - (4 * (-16) * height))) / (2 * (-16));

	printf("\nThe projectile will hit the ground in %f seconds.\n", time);
	printf("\nTHe projectile max height is %f feet.\n", max);

	return 0;
}
