// TCP Client
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT 8080
typedef struct numbers{
    int num1;
    int num2;
    char operation;
} Numbers;
int main(){
    struct sockaddr_in serverAddress;
    int socketFD, numOfRecievedCharacter;
    if((socketFD = socket(AF_INET, SOCK_STREAM, 0))<0){
        printf("Error In Socket Creation.\n");
        exit(EXIT_FAILURE);
    }
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    if(inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr) < 0){
		printf("\nInvalid address/ Address not supported \n");
		exit(EXIT_FAILURE);
	}
    if((connect(socketFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress))) < 0){
        printf("Error In Connect.\n");
		exit(EXIT_FAILURE);
    }
    Numbers *obj = (Numbers *)malloc(sizeof(Numbers));
    printf("Enter First Number: ");
    scanf("%d", &obj->num1);
    printf("Enter Second Number: ");
    scanf("%d", &obj->num2);
    printf("Enter Operator: ");
    scanf(" %c", &obj->operation);
    float answer;
    send(socketFD, obj, sizeof(Numbers), 0);
    int n = read(socketFD, &answer, sizeof(float));
    printf("Answer from Server: %.2f \n", answer);
}