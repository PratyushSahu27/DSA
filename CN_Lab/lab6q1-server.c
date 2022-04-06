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
    struct sockaddr_in clientAddress, serverAddress;
    int socketFD, clientSocketFD, numOfRecievedCharacter;
    if((socketFD = socket(AF_INET, SOCK_STREAM, 0))<0){
        printf("Error In Socket Creation.\n");
        exit(EXIT_FAILURE);
    }
    memset(&serverAddress, 0, sizeof(serverAddress));
    memset(&clientAddress, 0, sizeof(clientAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    if(bind(socketFD, (const struct sockaddr *)&serverAddress, sizeof(serverAddress))<0){
        printf("Error In Binding!");
        exit(EXIT_FAILURE);
    }
    if((listen(socketFD, 3))<0){
        printf("Error In Listening!");
        exit(EXIT_FAILURE);
    }
    int len = sizeof(clientAddress);
    if((clientSocketFD = accept(socketFD, (struct sockaddr *)&clientAddress, (socklen_t *)&len)) < 0){
        printf("Error In Accept!");
        exit(EXIT_FAILURE);
    }
    Numbers *nums = (Numbers *)malloc(sizeof(Numbers));
    numOfRecievedCharacter = read(clientSocketFD, nums, sizeof(Numbers));
    int n1 = nums->num1;
    int n2 = nums->num2;
    float answer;
    if(nums->operation == '+'){
        answer = n1 + n2;
    } else if(nums->operation == '-'){
        answer = n1 - n2;
    } else if(nums->operation == '*'){
        answer = n1 * n2;
    } else if(nums->operation == '/'){
        answer = n1 / n2;
    } else {
        printf("Wrong Operator!");
        answer = -1;
    }
    printf("Answer: %f. \n", answer);
    send(clientSocketFD, &answer, sizeof(float), 0);
    close(socketFD);
    close(clientSocketFD);
}