/*
 ============================================================================
 Name        : home4.c
 Author      : Ricardo A. Garza
 Version     :
 Copyright   : 2014
 Description : Store Front in C, Ansi-style. This program simulates using the
               CLI (command line interface) to purchase selected items from a
               storefront, including subtotals, tax, and shipping.
 ============================================================================
 */

#include <stdio.h>
#include <math.h>

#define CHAIR_PRICE    59.99    /* chair price             */
#define CABINET_PRICE  29.99    /* cabinet price           */
#define DESK_PRICE     99.99    /* desk price              */
#define BOOKCASE_PRICE 44.99    /* bookcase price          */
#define TAX_RATE        0.0825  /* tax rate of 8.25 %      */
#define SHIPPING_COST  25.00    /* shipping cost of $25.00 */

 int i;                        /* loop counter to calculate item subtotal */
  int numItems;                 /* number of particular items ordered      */
  float chairSubtotal    = 0.0; /* cumulative subtotal for office chairs   */
  float cabinetSubtotal  = 0.0; /* cumulative subtotal for file cabinets   */
  float deskSubtotal     = 0.0; /* cumulative subtotal for desks           */
  float bookcaseSubtotal = 0.0; /* cumulative subtotal for bookcases       */
  float currentSubtotal  = 0.0; /* cumulative subtotal for overall items   */

void welcomemessage(int message);/*Prints out the welcome message*/

int mainmenu (int menu);             /*Prints out the main menu and has the switch statement*/

int userchoice1 (int choicenumber1); /*{Function: userchoice*/
int userchoice2 (int choicenumber2); /*Parameter: a ineteger repsenting the number chosen in the switch*/
int userchoice3 (int choicenumber3); /*Return: a integer after the the user chooses a number*/
int userchoice4 (int choicenumber4); /*Description: These 4 functions each calcuate the subtotal}*/

int totalresult (int total);

int discounttotal (int discount);

int main(void)
{
	int n;
	welcomemessage(n);
	mainmenu(n);
	totalresult(n);
	discounttotal(n);
}

void welcomemessage(int message)
{
  /* display student information                                           */
  printf("+--------------------------------------------------------------+\n");
  printf("|                Computer Science and Engineering              |\n");
  printf("|                 CSCE 1030 - Computer Science I               |\n");
  printf("|   Ricardo A. Garza     rag0175    RicardoGarza3@my.unt.edu   |\n");
  printf("+--------------------------------------------------------------+\n\n");

  /* welcoming message for our storefront                                  */
  printf("    Welcome to the CSCE 1030 StoreFront!\n\n");

}

int mainmenu (int menu)
{
	  int (n);
	  int userSelection; /* item selection from user: 1 - 5         */
	  /* do-while loop to display main menu and prompt for user input          */
	  do {
	    printf("Enter the number corresponding to the product you wish to purchase:\n");
	    printf("1:  Office Chairs   $59.99 each\n");
	    printf("2:  File Cabinets   $29.99 each\n");
	    printf("3:  Desks           $99.99 each\n");
	    printf("4:  Bookcases       $44.99 each\n");
	    printf("5:  Checkout                   \n");
	    printf("User Selection: ");
	    scanf("%d", &userSelection);
	    getchar();
	    switch (userSelection)
	    {
		case 1:
		userchoice1(n);
		break;
		case 2:
		userchoice2(n);
		break;
		case 3:
		userchoice3(n);
		break;
		case 4:
		userchoice4(n);
		break;
		case 5:
		break;
		default:
		printf("Error: Invalid user selection. Please enter value between 1 and 5, inclusively.\n");
	    }
	   } while (userSelection != 5);
}

int userchoice1 (int choicenumber1)
{
              /* Office Chairs */
              printf("Enter the number of OFFICE CHAIRS you would like to order: ");
              scanf("%d", &numItems);
              getchar();
              currentSubtotal -= chairSubtotal; /* needed in case duplicate */
              if (numItems >= 0)
              {
                for (i = 0; i < numItems; i++)
                {
                 chairSubtotal += CHAIR_PRICE;
                }
                currentSubtotal += chairSubtotal;
                printf("\nYou ordered %d OFFICE CHAIRS at %.2f each. You current subtotal is: %.2f\n\n",
                           numItems, CHAIR_PRICE, currentSubtotal);
              }
              else /* (numItems < 0) */
              {
                printf("Error: Invalid number of items selected. Current subtotal remains %f\n",
                           currentSubtotal);
              }
	return currentSubtotal;
}

int userchoice2 (int choicenumber2)
{
		 /* File Cabinets */
              printf("Enter the number of FILE CABINETS you would like to order: ");
              scanf("%d", &numItems);
              getchar();
              currentSubtotal -= cabinetSubtotal; /* needed in case duplicate */
              if (numItems >= 0)
              {
                for (i = 0; i < numItems; i++)
                {
                  cabinetSubtotal += CABINET_PRICE;
                }
                currentSubtotal += cabinetSubtotal;
                printf("\nYou ordered %d FILE CABINETS at %.2f each. You current subtotal is: %.2f\n\n",
                           numItems, CABINET_PRICE, currentSubtotal);
              }
              else /* (numItems < 0) */
              {
                printf("Error: Invalid number of items selected. Current subtotal remains %f\n",
                           currentSubtotal);
              }
	return currentSubtotal;
}

int userchoice3 (int choicenumber3)
{
		/* Desks */
              printf("Enter the number of DESKS you would like to order: ");
              scanf("%d", &numItems);
              getchar();
              currentSubtotal -= deskSubtotal; /* needed in case duplicate */
              if (numItems >= 0)
              {
                for (i = 0; i < numItems; i++)
                {
                  deskSubtotal += DESK_PRICE;
                }
                currentSubtotal += deskSubtotal;
                printf("\nYou ordered %d DESKS at %.2f each. You current subtotal is: %.2f\n\n",
                           numItems, DESK_PRICE, currentSubtotal);
              }
              else /* (numItems < 0) */
              {
                printf("Error: Invalid number of items selected. Current subtotal remains %f\n",
                           currentSubtotal);
              }
	return currentSubtotal;
}

int userchoice4 (int choicenumber4)
{
		/* Bookcases */
              printf("Enter the number of BOOKCASES you would like to order: ");
              scanf("%d", &numItems);
              getchar();
              currentSubtotal -= bookcaseSubtotal; /* needed in case duplicate */
              if (numItems >= 0)
              {
                for (i = 0; i < numItems; i++)
                {
                  bookcaseSubtotal += BOOKCASE_PRICE;
                }
                currentSubtotal += bookcaseSubtotal;
                printf("\nYou ordered %d BOOKCASES at %.2f each. You current subtotal is: %.2f\n\n",
                           numItems, BOOKCASE_PRICE, currentSubtotal);
              }
              else /* (numItems < 0) */
              {
                printf("Error: Invalid number of items selected. Current subtotal remains %f\n",
                           currentSubtotal);
              }
	return currentSubtotal;
}

int totalresult (int total)
{
  int n;
  if (currentSubtotal > 0)
  {
    printf("Thank you. We do appreciate your business!\n");
    printf("------------------------------------------\n");
    printf("              ORDER SUMMARY:\n");
    printf("------------------------------------------\n");
    printf("DESCRIPTION    PRICE       QTY       PRICE\n");
    printf("------------------------------------------\n");
    printf("OFFICE CHAIR  $%.2f     %3d     $%8.2f \n", CHAIR_PRICE, (int) ((chairSubtotal+1)/CHAIR_PRICE), chairSubtotal);
    printf("FILE CABINET  $%.2f     %3d     $%8.2f \n", CABINET_PRICE, (int) ((cabinetSubtotal+1)/CABINET_PRICE), cabinetSubtotal);
    printf("DESK          $%.2f     %3d     $%8.2f \n", DESK_PRICE, (int) ((deskSubtotal+1)/DESK_PRICE), deskSubtotal);
    printf("BOOKCASE      $%.2f     %3d     $%8.2f \n", BOOKCASE_PRICE, (int) ((bookcaseSubtotal+1)/BOOKCASE_PRICE), bookcaseSubtotal);
    printf("------------------------------------------\n");
    discounttotal(n);
  }
  else /* no items ordered, so do not charge tax and shipping */
  {
    printf("------------------------------------------\n");
    printf("No items ordered.  Please come again soon!\n");
  }

  return 0;
}

int discounttotal (int discount)
{
    /* check if need apply discount for orders over $500                   */
    if (currentSubtotal > 500)
    {
      printf("Subtotal                         $%8.2f \n", currentSubtotal);
      float discount = currentSubtotal * 0.10; /* 10% discount applied before tax and shipping */
      printf("10%% Discount (> $500)          - $%8.2f \n", discount);
      printf("------------------------------------------\n");
      printf("Subtotal with 10%% Discount       $%8.2f \n", currentSubtotal -= discount);
    }
    else
    {
      printf("Subtotal                         $%8.2f \n", currentSubtotal);
    }

    printf("Sales Tax                        $%8.2f \n", currentSubtotal * TAX_RATE);
    printf("Shipping Cost                    $%8.2f \n", SHIPPING_COST);
    printf("------------------------------------------\n");
    printf("TOTAL                            $%8.2f \n", (currentSubtotal * (TAX_RATE + 1.0)) + SHIPPING_COST);


}
