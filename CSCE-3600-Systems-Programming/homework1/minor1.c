/*
Author: Ricardo Garza (RicardoGarza3@my.unt.edu)
EUID: 10967208
Date: 9/05/2018
Purpose: write a complete C program that will prompt the user to enter an ASCII printable character
*/
/*#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS*/

#include <stdio.h>

void dec_to_bin(int dec_num);

int main(void) {

	char ascii_char;
	int binarynum[10];
	int dec_num;

	/*Enter ASCII Character*/
	printf("Enter an ASCII Character: ");
	scanf("%c", &ascii_char);

	/*Print out decimal, hex, and oct*/
	printf("\nThe ASCII value of %c is:\n", ascii_char);
	printf("dec -- %d\n", ascii_char);
	printf("hex -- %x\n", ascii_char);
	printf("oct -- %o\n", ascii_char);

	/*Converts char to dec*/
	dec_num = ascii_char;
	dec_to_bin(dec_num);

	printf("\n");
	return 0;
}

void dec_to_bin(int dec_num) {
	int binarynum[8] = { 0,0,0,0,0,0,0,0 };
	int i = 0;
	int j = 0;

	while (dec_num > 0) {
		binarynum[i] = dec_num % 2;
		dec_num /= 2;
		i++;
	}

	printf("bin -- ");
	for (j = i; j >= 0; j--) {
		printf("%d", binarynum[j]);
	}
}

/*#endif*/
