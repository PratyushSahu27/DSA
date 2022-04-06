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
	int arr[5];
    float avg;
	struct sockaddr_in	 servaddr;
    printf("Enter Five elements of array\n");
    for(int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }

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
	
        sendto(sockfd, arr, sizeof(int)*5, 0, ( const struct sockaddr *) &servaddr, sizeof(servaddr));
    
	printf("Average of the elements of array\n");
	len  = sizeof(servaddr);	
	n = recvfrom(sockfd, &avg, sizeof(float),
				0, (struct sockaddr *) &servaddr,
				&len);
    avg = (arr[0]+arr[1]+arr[2]+arr[3]+arr[4])/5;            
	
	printf("Average : %f\n", avg);

	close(sockfd);
	return 0;
}