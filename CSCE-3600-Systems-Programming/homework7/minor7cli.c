/* Minor 7 Client */
/*
Author: Ricardo Garza (RicardoGarza3@my.unt.edu)
EUID: 10967208
Date: 11/21/2018
Purpose: write a complete C program that will support a client/server model
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	int sockfd, portno, n;
	int cli_counter = 0;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	char buffer[256];

	if (argc < 3)
	{
		fprintf(stderr,"usage %s hostname port\n", argv[0]);
		exit(0);
	}

	portno = atoi(argv[2]);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0) 
	{
		error("ERROR opening socket");
	}

	server = gethostbyname(argv[1]);

	if (server == NULL)
	{
		fprintf(stderr,"ERROR, no such host\n");
		exit(EXIT_FAILURE);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(portno);

	if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
	{
		error("ERROR connecting");
	}
	while(cli_counter < 20){
		
		bzero(buffer,256);
		fgets(buffer,255,stdin);
		n = write(sockfd,buffer,strlen(buffer));

		if (n < 0) 
		{
			error("ERROR writing to socket");
		}

		bzero(buffer,256);
		n = read(sockfd,buffer,255);

		if (n < 0) 
		{
			error("ERROR reading from socket");
		}

		printf("%s\n",buffer);
	}
		close(sockfd);

	return 0;
}
