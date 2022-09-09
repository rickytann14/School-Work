/// \file main.cpp

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ecompiler.h"
#include "expressiontree.h"
#include "defines.h"

CExpression g_cExpression; ///< Arithmetic expression.

/// \brief Main.
/// \param argc Argument count
/// \param argv Arguments.
/// \return 0 for success, 1 for failure.

int main(){
  const int BUFSIZE = 64; //buffer size
  char buffer[BUFSIZE]; //character buffer
  bool finished = false; //true when user input is finished

  while(!finished){ //process an arithmetic expression
    printf("Arithmetic Expression: "); //prompt user
    char c = getchar(); //preload first character

    //read a line of text into buffer
    int i = 0;
    while(c != '\n' && i<BUFSIZE){ //while not end of line
      buffer[i++] = c; //store current character
      c = getchar(); //get next character
    } //while

    if(i < BUFSIZE){ //string fits into buffer
      buffer[i] = '\0'; //null at end of string

      //exit if the user types "q" or "quit" or a blank line
      if(i>0 && strcmp(buffer, "quit") != 0 && strcmp(buffer, "q") != 0){
        bool error = g_cExpression.parse(buffer); //parse the infix arithmetic expression

        if(!error){ //success
          char s[BUFSIZE]; //string for prefix and postfix expression

          if(g_cExpression.infix(s, BUFSIZE))
            printf("Buffer Overflow: Fully parenthesized arithmetic expression too long.\n");
          else printf("Infix: %s\n", s);

          if(g_cExpression.prefix(s, BUFSIZE))
            printf("Buffer Overflow: Prefix arithmetic expression too long.\n");
          else printf("Prefix: %s\n", s);

          if(g_cExpression.postfix(s, BUFSIZE))
            printf("Buffer Overflow: Postfix arithmetic expression too long.\n");
          else printf("Postfix: %s\n", s);    

          printf("\n");
        } //if
      } //if
      else finished = true; //exit on error
    } //if

    else{ //buffer overflow
      printf("Buffer Overflow: Input arithmetic expression too long.\n");   
      while(c != '\n')c = getchar(); //flush input       
    } //else
  } //while

  return 0;
}
