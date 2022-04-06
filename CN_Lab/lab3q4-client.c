// Client side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#define PORT 8080 
#define MAXLINE 1024 
struct info { 
	int id; char *name; 
	};// Driver code 
int main() { 
		int sockfd; 
		char buffer[MAXLINE]; 
		char *hello = "Hello from client"; 
		struct sockaddr_in servaddr;
		int result; 
		struct info student; 
		student.name = (char *)malloc(100*sizeof(char)); 
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
		printf("Enter name : "); 
		scanf("%[^\n]%*c", student.name); 
		printf("Enter stident id : "); 
		scanf(" %d", &student.id); 
		sendto(sockfd, &student.id, sizeof(int), 0, 
		(const struct sockaddr *) &servaddr, sizeof(servaddr)); 
		len = sizeof(servaddr); 
		n = recvfrom(sockfd, &result, sizeof(int),0,
		 (struct sockaddr *) &servaddr, &len); 
		 student.id = result; printf("Reversed id is: %d\n", student.id); 
		 printf("Name: %s\n", student.name); 
		 close(sockfd); 
return 0; }