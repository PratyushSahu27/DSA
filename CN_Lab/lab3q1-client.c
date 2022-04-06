// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT	 8080
#define MAXLINE 1024

// Driver code
int main() {
	int sockfd;
	int a,b,result;
	struct sockaddr_in	 servaddr;
	scanf("%d%d",&a,&b);

	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	memset(&servaddr, 0, sizeof(servaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = INADDR_ANY;
	
	int n, len;
	sendto(sockfd, &a, sizeof(int),
		0, (const struct sockaddr *) &servaddr,
			sizeof(servaddr));
	sendto(sockfd, &b, sizeof(int),
		0, (const struct sockaddr *) &servaddr,
			sizeof(servaddr));
	printf("Two numbers sent for sum\n");

	len = sizeof(servaddr);	
	n = recvfrom(sockfd, &result, sizeof(int),
				0, (struct sockaddr *) &servaddr,
				&len);
	
	printf("SUM : %d\n", a+b);

	close(sockfd);
	return 0;
}
