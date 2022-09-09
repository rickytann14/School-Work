/*
Author: Ricardo Garza (RicardoGarza3@my.unt.edu)
EUID: 10967208
Date: 10/19/2018
Purpose: write a complete C program that will act as a simple command-line interpreter
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*function prototype for parsing the command*/
void parse(char *input, char **cmd); 

int main(){
	char *cmd[64];
	char quit[] = "quit";
	char input[64];
	char *exe;
	int i;


	while (1){
		/*display prompt*/
		printf("minor5>");

		/*Read input*/
		gets(input);

		/*Checks to see if you want to quit*/
		if( strcmp (input,quit) == 0 ){
			exit(1);
		}

		/*calls parse function and passes by refence*/
		parse(input, cmd);


		if(fork() == 0){
			/*child*/
			execvp(*cmd, cmd);
			printf("execlp failed\n");
			exit(1);
		}
		else if(fork() > 0){
			/*parent*/
			sleep(1);
			wait( (int *)0);
			printf("\n");
		}
		else{
		/*	perror("fork");*/
			exit(1);
		}
	}/*while*/
}/*main*/

/*parse funtion*/
void parse(char *input, char **cmd){
	/*while not the end of input command*/
	while(*input != '\0'){
		while(*input == ' ' || *input == '\n'){
			*input++ = '\0';
		}
		*cmd++ = input;
		while (*input != '\0' && *input != ' ' && *input != '\n'){
			input++;
		}
	}
	/*end of list*/
	*cmd = '\0';

}
