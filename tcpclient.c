/*
 *  *  *    * tcpclient.c
 *   *   *    * ICS 451
 *    *    *    * Lab #2 Client/Server
 *     *     *    * Reference from YouTube: Idiot Developer
 *      *      *    * https://www.youtube.com/watch?v=hptViBE23fI
 *       *       *    * Reference from GitHub: nikhilroxtomar
 *        *        *    * https://github.com/nikhilroxtomar/tcp-client-server-in-C/blob/master/tcpClient.c
 *         *         *    * Audrey Ford
 *          *          *    * 2/13/2020
 *           *           *    */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

void main(){
	
	int clientSocket;
	struct sockaddr_in serverAddr;
	char buffer[1024];

	clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	printf("Client Socket Created Sucessfully.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	printf("Connected to Server.\n");

	recv(clientSocket, buffer, 1024, 0);
	printf("Data Received: %s\n", buffer);
	printf("Closing the connection.\n");

}
