#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
int main(){
    struct sockaddr_in serverAddress;
    int socketFD, noOfReceivingCharacters;
    socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if(socketFD <= 0){
        printf("Error in socketFD");
        exit(-1);
    }
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8050);
    if(inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr) < 0){
		printf("\nInvalid address/ Address not supported \n");
		exit(-1);
	}
    if((connect(socketFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress))) < 0){
        printf("Error In Connect.\n");
		exit(-1);
    }
    int num;
    printf("Enter Number: ");
    scanf("%d", &num);
    send(socketFD, &num, sizeof(int), 0);
    int oddEven, prime, armstrong;
    int n1 = read(socketFD, &oddEven, sizeof(int));
    int n2 = read(socketFD, &prime, sizeof(int));
    int n3 = read(socketFD, &armstrong, sizeof(int));
    if(oddEven == 1){
        printf("%d is a Odd Number.\n", num);
    } else {
        printf("%d is a Even Number.\n", num);
    }
    if(prime == 1){
        printf("%d is a Prime Number.\n", num);
    } else {
        printf("%d is not a Prime Number.\n", num);
    }
    if(armstrong == 1){
        printf("%d is a Armstrong Number.\n", num);
    } else {
        printf("%d is not a Armstrong Number.\n", num);
    }
}