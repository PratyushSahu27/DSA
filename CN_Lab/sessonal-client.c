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


int main() {
	int sockfd;
	int a, factorial;
	struct sockaddr_in	 servaddr;
    printf("Enter a number\n");
	scanf("%d",&a);
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	memset(&servaddr, 0, sizeof(servaddr));
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = INADDR_ANY;
	
	int n, len;
	sendto(sockfd, &a, sizeof(int),
		0, (const struct sockaddr *) &servaddr,
			sizeof(servaddr));
	printf("Numbers sent for factorial\n");

	len = sizeof(servaddr);	
	n = recvfrom(sockfd, &factorial, sizeof(int),
				0, (struct sockaddr *) &servaddr,
				&len);
	
	printf("The factorial is %d and my roll number is 1906342",factorial);

	close(sockfd);
	return 0;
}
