/*
Author: Ricardo Garza (RicardoGarza3@my.unt.edu)
Date: 10/12/2014
Purpose: Is to simulate purchasing an item from a store*/

#include <stdio.h>
#define TAX_RATE      .0825
#define SHIPPING_COST 25.00

int main(void)
{
	int choice, buy, stop;                                   /*Declartions*/
	float total, chair, file, desk, book;
	float stuff, sum = 0;
	printf("Hello Welcome to our store.\n");                /*Welcome Message and options*/
	printf("Enter the number corresponding to the product");
	printf(" you want to buy:\n");
	printf("1: Office Chairs $59.99 each\n");
	printf("2: File Cabinets $29.99 each\n3: Desks         $99.99 each\n");
	printf("4: Bookcases     $44.99 each\n5: Checkout\n");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:                                             /*Ask for user input*/
			printf("Enter the amount of chairs that you want to buy. ");
			scanf("%d", &buy);                          /*After input does the math to*/
			stop = buy;                                 /*figuer out the cost.*/
			for(stuff = 1; stuff <= stop; stuff++)
			{
				chair = buy * 59.99;
				continue;                           /*Jumps to the other case and repeats*/
			}

		case 2:
			printf("Enter the amount File Cabinets that you want to buy. ");
			scanf("%d", &buy);
			stop = buy;
                        for(stuff = 1; stuff <= stop; stuff++)
                        {
                                file = (buy * 29.99) + chair;
				continue;
                        }
		case 3:
			printf("Enter the amount of Desks that you want to buy. ");
			scanf("%d", &buy);
			stop = buy;
                        for(stuff = 1; stuff <= stop; stuff++)
                        {
                                desk = (buy * 99.99) + file;
				continue;
                        }
		case 4:
			printf("Enter the amount of Bookcases that you want to buy. ");
			scanf("%d", &buy);
			stop = buy;
                        for(stuff = 1; stuff <= stop; stuff++)
                        {
                                sum = (buy * 49.99) + desk;
                        }
		break;
		case 5:
		break;
		default:
		printf("Not an option please pick a differnt number!");
	}
	if (choice == 5)
	{
		printf("Total Cost is $0.\n"); /*when you choose checkout without buying*/
	}
	if (sum >= 500)                        /*add the discount when over $500*/
        {
        	sum = sum * .9;                /*Also adds tax and shipping*/
		total = TAX_RATE * sum;
                sum = total + SHIPPING_COST + sum;

                printf("Total Cost is going to be %.2f.\n", sum);
        }
        else
        {
                total = TAX_RATE * sum;       /*only adds the tax and shipping*/
                sum = total + SHIPPING_COST + sum;
		printf("Total Cost is going to be $%.2f.\n", sum);
        }
	return 0;
}
