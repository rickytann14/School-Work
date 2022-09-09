/*
Author: Ricardo Garza (RicardoGarza3@my.unt.edu)
EUID: 10967208
Date: 11/29/2018
Purpose: write a complete C program that will support a client/server model
*/
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h> 
#include <sys/wait.h>
#include <sys/un.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <netinet/in.h>
#include <time.h>
#include <pthread.h>

#define SOCKETNAME  "selectServerSocket"

void* clientHandler(void* args);

struct threadArgs
{
	int *fd;
	int *counter;
	int clientNumber;
};

int main (int argc, char *argv[]){
	int ns = 0, ns2 = 0;								/* Socket Connection for 2 connections */
	int len_sock, s, n;							/* Length of socket_addr and the listen sockets */
	int maxfd;									/* descriptors up to maxfd-1 polled*/
	int nread;									/* # chars on read()*/
	int nready;									/* # descriptors ready. */
	int portno;									/* Port Number for sever */
	int clientCounter[2];
		clientCounter[0] = 0;
		clientCounter[1] = 0;
	struct sockaddr_in serv_addr, cli_addr;
	struct sockaddr_un name;					/* For Unix? */
	socklen_t clilen;
	char buf[1024], buffer[256];		        /* Buffer for messages to others. */
	char msg[1024];
	
	pthread_t tid[2];
		tid[0] = 0;
		tid[1] = 0;
	struct threadArgs args[2];	
	/* Remove any previous socket.
	don't know if needed but keeping it */
	unlink(SOCKETNAME);
	
	/* Checking to make sure we have the correct number
			Of command line arguments*/
	if (argc < 2){
		fprintf(stderr,"ERROR, No port provided\n");
		exit(1);
	}
	
	/* Creating Sockets */
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	
	/* Creating the address of the server. 
	and whatever else this does */

	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	
	/* No idea what this does someone explain */
	name.sun_family = AF_INET;
	strcpy(name.sun_path, SOCKETNAME);
	len_sock = sizeof(name.sun_family) + strlen(name.sun_path);
	
	/* Bind the socket to the address.*/
	if (bind(s, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
		error("ERROR on binding");
	}
	
	/* Listen for connections. */
	if (listen(s, 3) < 0){
		perror( "listen");
		exit(1);
	}
	clilen = sizeof(cli_addr);
	while(1)
	{
		//printf("cli 1: %d\nclid2: %d\n", ns, ns2);
		/* Accept a connection.*/
		if(ns == 0)
		{
			if ((ns = accept(s, (struct sockaddr *) &cli_addr, &clilen)) < 0)
			{
				perror("accept");
				exit(1);
			}
			printf("Client 1 Accepted\n");
			//if statement makes sure that a thread isnt created were there is
			//already a thread
			//if(tid[0] == 0)
			{
				//creates thread and sends file descriptor to the thread
				args[0].fd = &ns;
				args[0].counter = &clientCounter[0];
				args[0].clientNumber = 1;
				pthread_create(&tid[0], NULL, clientHandler, (void*)&args[0]);	     
			}
		}	
		/* Accept another connection. */
		if(ns2 == 0)
		{
			if ((ns2 = accept(s, (struct sockaddr *) &cli_addr, &clilen)) < 0)
			{
				perror("accept");
				exit(1);
			}
			printf("Client 2 Accepted\n");
			//if(tid[1] == 0)
			{
				args[1].fd = &ns2;
				args[1].counter = &clientCounter[1];
				args[1].clientNumber = 2;
				pthread_create(&tid[1], NULL, clientHandler, (void*)&args[1]);
			}
		}
	
	sleep(2);
	
	if(clientCounter[0] > 1024 && clientCounter[0] < 49151)
	{
		sprintf(buffer, "SERVER Message: PORT %d", clientCounter[0]);
		send(ns2, buffer, sizeof(buffer), 0);
		close(ns2);
	}
	//pthread_join(tid[0], (void**)&ns);
	
	if(clientCounter[1] > 1024 && clientCounter[1] < 49151)
	{
		sprintf(buffer, "SERVER Message: PORT %d", clientCounter[1]);
		send(ns, buffer, sizeof(buffer), 0);
		close(ns);
	}
	//pthread_join(tid[1], (void**)&ns2);
	
	}
	return 0;
}

void *clientHandler(void* args)
{
	struct threadArgs *arguments =  args;
	int *clifd = (int*) arguments->fd;
	int *pCounter = (int*) arguments->counter;
	char buffer[256];
		bzero(buffer, sizeof(buffer));
	printf("Client Handler Assigned\n");
	while(1)
	{
		sprintf(buffer, "Enter Client Data"); 
		send(*clifd, buffer, sizeof(buffer), 0);
		recv(*clifd, buffer, sizeof(buffer), 0);
		if(strcmp("0", buffer) == 0)
		{
			*clifd = 0;
			close(*clifd);
			break;
		}
		*pCounter += atoi(buffer);
		printf("Client %d: %6s - Total: %2d\n", (int) arguments->clientNumber, buffer, *pCounter);
		sprintf(buffer, "%d", *pCounter);
		send(*clifd, buffer, sizeof(buffer), 0);
		printf("%s\n", buffer);
	}
	pthread_exit(0);
}






