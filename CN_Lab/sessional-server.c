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

int fact(int n){
    if (n == 0)  
        return 1;  
    return(n * fact(n-1));
}

int main() {
	int sockfd;
	int a, factorial;
	struct sockaddr_in servaddr, cliaddr;
	
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	
	int len, n;

	len = sizeof(cliaddr);

	n = recvfrom(sockfd, &a, sizeof(int),
				0, ( struct sockaddr *) &cliaddr,
				&len);
	factorial = fact(a);
	printf("Answer sent : %d\n",factorial );
	sendto(sockfd, &factorial, sizeof(int),
		0, (const struct sockaddr *) &cliaddr,
			len);
	return 0;
}