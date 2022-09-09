/*
Author: Ricardo Garza (ricardoGarza3@my.unt.edu)
EUID: 10967208
Date: 11/29/2018
Purpose: write a complete C program that will support a client/server model
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>
#include <assert.h>

#define SOCKETNAME  "selectServerSocket"

void* clientHandler(void* args);

struct threadArgs
{
	int *fd;
	int *counter;
	int clientNumber;
};

/* Error Checking Messages */
void error(const char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	int svrfd, clifd, portno, n1, n2, maxfd, clilen;
	int cli_counter = 0;
	struct sockaddr_in serv_addr, serv_addr2, cli_addr;
	struct hostent *server, *server_ip;

	char buffer[256];
	
	char *threadArgs[2];
		threadArgs[0] = argv[3];
		threadArgs[1] = "1180";
		
	fd_set fds;
	
	if (argc < 4){
		fprintf(stderr,"usage: %s <svr_host> <svr_port> <rem_ipaddr>\n", argv[0]);
		exit(0);
	}
	
	/* Getting port number */
	/* Socket using TCP */
	portno = atoi(argv[2]);
	svrfd = socket(AF_INET, SOCK_STREAM, 0);
	
	/* Error checking the opening socket */
	if (svrfd < 0){
		error("ERROR opening socket");
	}
	
	/* Set the sever host name */
	server = gethostbyname(argv[1]);

	/* Error Check the name entered Correctly */
	if (server == NULL){
		fprintf(stderr,"ERROR, no such host\n");
		exit(EXIT_FAILURE);
	}
	
	/* No idea but it is needed */
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(portno);
	
	
	
	/* Error check connection */
	if (connect(svrfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0){
		error("ERROR connecting");
	}
	else
	{
		printf("Connected\n");
	}
	
	while(1)
	{
		//clear out buffer so no garbage gets passed by mistake
		bzero(buffer, sizeof(buffer));
	
		//recieve command from server
		recv(svrfd, buffer, sizeof(buffer), 0);
		
		if(strcmp("Enter Client Data", buffer) == 0){
			//process command and take appropriate action
		
			//if command is to enter a total
			//print command to screen to prompt user
			//for input and send input to server
			printf("%s: ", buffer);
			bzero(buffer, sizeof(buffer));
			scanf("%s", buffer);
			cli_counter += atoi(buffer);
			send(svrfd, buffer, sizeof(buffer), 0);
			recv(svrfd, buffer, sizeof(buffer), 0);
			printf("SERVER Total: %s\n", buffer);
		}
		
		//printf("buffer: %s\n", buffer);
		if(strncmp("SERVER Message", buffer, 14) == 0)
		{
			close(svrfd);
			svrfd = socket(AF_INET, SOCK_STREAM, 0);
	
			/* Error checking the opening socket */
			if (svrfd < 0){
				error("ERROR opening socket");
			}
			
			char* c = &buffer[21];
			//printf("c: %s\n", c);
			portno = atoi(c);
			printf("portno: %d\n", portno);
			serv_addr.sin_port = htons(portno);
			server_ip = gethostbyname(argv[3]);
			memcpy(&serv_addr.sin_addr, server->h_addr, server->h_length);
			
			if(connect(svrfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
			{
				error("ERROR connecting the tmpserver...");
			}
		}
		
		if(atoi(buffer) > 1024 && atoi(buffer) < 49151)
		{
			int ns = 0, ns2 = 0;								/* Socket Connection for 2 connections */
			int len_sock, s, n;							/* Length of socket_addr and the listen sockets */
			int maxfd;									/* descriptors up to maxfd-1 polled*/
			int nread;									/* # chars on read()*/
			int nready;									/* # descriptors ready. */
			int portno = atoi(buffer);									/* Port Number for sever */
			int clientCounter[2];
				clientCounter[0] = 0;
				clientCounter[1] = 0;
	
			struct sockaddr_in serv_addr, cli_addr;
			//struct sockaddr_un name;					/* For Unix? */
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
			serv_addr.sin_family = AF_INET;
			serv_addr.sin_addr.s_addr = INADDR_ANY;
			serv_addr.sin_port = htons(portno);
	
			/* No idea what this does someone explain */
			//name.sun_family = AF_INET;
			//strcpy(name.sun_path, SOCKETNAME);
			//len_sock = sizeof(name.sun_family) + strlen(name.sun_path);
	
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
			while(1){
		
			//printf("cli 1: %d\nclid2: %d\n", ns, ns2);
			/* Accept a connection.*/
			if(ns == 0){
			
				if ((ns = accept(s, (struct sockaddr *) &cli_addr, &clilen)) < 0)
				{
					perror("accept");
					exit(1);
				}
				printf("Client 1 Data: Connection Accepted\n");
				//if statement makes sure that a thread isnt created were there is
				//already a thread
				//if(tid[0] == 0)
			
				//creates thread and sends file descriptor to the thread
				args[0].fd = &ns;
				args[0].counter = &clientCounter[0];
				args[0].clientNumber = 1;
				pthread_create(&tid[0], NULL, clientHandler, (void*)&args[0]);	     
			
			}	
			/* Accept another connection. */
			if(ns2 == 0)
			{
				if ((ns2 = accept(s, (struct sockaddr *) &cli_addr, &clilen)) < 0)
				{
					perror("accept");
					exit(1);
				}
				printf("Client 2 Data: Connection Accepted\n");
				//if(tid[1] == 0)
				{
					args[1].fd = &ns2;
					args[1].counter = &clientCounter[1];
					args[1].clientNumber = 2;
					pthread_create(&tid[1], NULL, clientHandler, (void*)&args[1]);
				}
			}
	
			sleep(2);
			printf("client1 total: %d\n", clientCounter[0]);
			//pthread_join(tid[0], (void**)&ns);
			printf("client2 total: %d\n", clientCounter[1]);
			//pthread_join(tid[1], (void**)&ns2);
	
		}
		/* printf("buffer: %s\n", buffer);
		if(strncmp("SERVER Message", buffer, 14) == 0)
		{
			char* c = &buffer[16];
			printf("c: %s", c);
			portno = atoi(c);
			printf("portno: %d\n", portno);
		}*/
		sleep(2);
	}
		sleep(2);
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
			printf("Disconnecting from SERVER...\n");
			exit(0);
			break;
		}
		*pCounter += atoi(buffer);
		sprintf(buffer, "%d", *pCounter);
		send(*clifd, buffer, sizeof(buffer), 0);
		printf("%s\n", buffer);
	}
	pthread_exit(0);
}


