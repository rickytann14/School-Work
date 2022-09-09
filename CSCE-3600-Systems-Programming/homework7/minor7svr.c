/*
Author: Ricardo Garza (RicardoGarza3@my.unt.edu)
EUID: 10967208
Date: 11/21/2018
Purpose: write a complete C program that will support a client/server model
*/
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h> 
#include <sys/un.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <netinet/in.h>
#include <time.h>

#define SOCKETNAME  "selectServerSocket"

int
main(int argc, char *argv[])
{
        char buf[1024], buffer[256];		        /* Buffer for messages to others. */
		char msg[1024];
        int s, n;                       /* Listen socket */
		int i, j, sold_counter = 0;						/* Counter variables for the loop */
        int ns;                         /* Socket for first connection. */
        int ns2;                        /* Socket for second connection. */
        int len;                        /* len of sockaddr */   
        int maxfd;                      /* descriptors up to maxfd-1 polled*/
        int nread;                      /* # chars on read()*/
        int nready;                     /* # descriptors ready. */
		int portno;
        struct sockaddr_un name;
		struct sockaddr_in serv_addr, cli_addr;
		socklen_t clilen;
        fd_set fds;                     /* Set of file descriptors to poll*/
		int data_table[20];
		char *avail_table[20];
		srand (time(NULL));				/* initialize random seed: */

		/* Making Array for Database table */
		for( i = 0; i < 20; i++){
			data_table[i] = rand() % 90000 + 9999;
		}
		
		for(i = 0; i < 20; i++){
			avail_table[i] = "AVAIL";
		}
		
		/* Checking table: */
		
		
		
        /* Remove any previous socket.*/
        unlink(SOCKETNAME);
		
		/* Checking to make sure we have the correct number
			Of command line arguments*/
		if (argc < 2){
		fprintf(stderr,"ERROR, no port provided\n");
		exit(1);
		}

		printf("[Sever]: Database Table:\n");
		printf("------------------------\n");
		
		for(i = 0; i < 20; i++){
			printf("[Tkt# %2d] %d : %s\n", i, data_table[i], avail_table[i]);
		}
        /* Create the socket. */

        if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
        	perror("socket");
        	exit(EXIT_FAILURE);
         }

        /* Create the address of the server.*/

		bzero((char *) &serv_addr, sizeof(serv_addr));
		portno = atoi(argv[1]);
		serv_addr.sin_family = AF_INET;
		serv_addr.sin_addr.s_addr = INADDR_ANY;
		serv_addr.sin_port = htons(portno);
        
		memset(&name, 0, sizeof(struct sockaddr_un));

        name.sun_family = AF_INET;
        strcpy(name.sun_path, SOCKETNAME);
        len = sizeof(name.sun_family) + strlen(name.sun_path);

        /* Bind the socket to the address.*/

		if (bind(s, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
		{
			error("ERROR on binding");
		}
        
        /* Listen for connections. */
        if (listen(s, 5) < 0){
        	perror( "listen");
        	exit(1);
        }

		clilen = sizeof(cli_addr);

		printf("0 clients connected. Waiting on CLIENT 1 to connect.\n");
        /* Accept a connection.*/
        if ((ns = accept(s, (struct sockaddr *) &cli_addr, &clilen)) < 0){
        	perror("accept");
        	exit(1);
        }


		printf("1 clients connected. Waiting on CLIENT 2 to connect.\n");
        /* Accept another connection. */
        if ((ns2 = accept(s, (struct sockaddr *) &cli_addr, &clilen)) < 0){
        	perror("accept");
        	exit(1);
        }
        
        maxfd = (ns > ns2 ? ns : ns2) + 1;
		printf("2 clients connected. Ready for incoming requests...\n");

        while (1){
                /* Set up polling using select. */
                FD_ZERO(&fds);
                FD_SET(ns,&fds);
                FD_SET(ns2,&fds);

                /* Wait for some input. */
                nready = select(maxfd, &fds, (fd_set *) 0, (fd_set *) 0, (struct timeval *) 0);
                
				/* If either descriptor has some input,
                   read it and copy it to the other. */

                if( FD_ISSET(ns, &fds)){
                        /*nread = recv(ns, buf, sizeof(buf), 0);
                         If error or eof, terminate. 
                        if(nread < 1){
                                close(ns);
                                close(ns2);
                                exit(0);
                        }
						strcpy(msg, "CLIENT 1: ");
						strcat(msg, buf);*/
						/* send( ns2, msg, nread + 10, 0);*/
						printf("Client 1\n");
						bzero(buffer,256);
						n = read(ns,buffer,255);
						if (n < 0){
							error("ERROR reading from socket");
						}
						
						if(strcmp(buffer, "BUY")){
							if(sold_counter == 20){
									n = write(ns,"[SERVER]: FULL",13);
							}
							else{
								for(i = 0; i < 20; i++){
									if(avail_table[i] == "AVAIL"){
										//n = write(ns,data_table[i], strlen(data_table[i]));
									}
								}
							}
						}

						printf("Here is the message: %s\n",buffer);
						n = write(ns,"I got your message",18);

						if (n < 0){
						error("ERROR writing to socket");
						}
                }

                if( FD_ISSET(ns2, &fds)){
                       /* nread = recv(ns2, buf, sizeof(buf), 0); */
                        /* If error or eof, terminate. */
						/*  if(nread < 1){
                                close(ns);
                                close(ns2);
                                exit(0);
                        }
						strcpy(msg, "CLIENT 2: ");
						strcat(msg, buf);*/
                        /*send( ns, msg, nread + 10, 0);*/
						
						printf("Client 2\n");
						bzero(buffer,256);
						n = read(ns2,buffer,255);
						if (n < 0){
							error("ERROR reading from socket");
						}

						printf("Here is the message: %s\n",buffer);
						n = write(ns2,"I got your message",18);

						if (n < 0){
						error("ERROR writing to socket");
						}
                }
        } 
}

