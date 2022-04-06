#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT 8080
int toReturnNumOfWords(char str[5][1000]){
    int largestStringIndex = 0;
    for(int i=1; i<5; ++i){
        if(strlen(str[i]) > strlen(str[largestStringIndex])){
            largestStringIndex = i;
        }
    }
    int numOfWords = 0;
    for(int i=0; i<strlen(str[largestStringIndex]); ++i){
        if(str[largestStringIndex][i] == ' ')
            numOfWords+=1;
    }
    return numOfWords + 1;
}
int main(){
    int socketFD, numOfCharacterRecieved;
    struct sockaddr_in serverAddress, clientAddress;
    if((socketFD = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        printf("Error In Socket.\n");
        exit(EXIT_FAILURE);
    }
    memset(&serverAddress, 0, sizeof(serverAddress));
    memset(&clientAddress, 0, sizeof(clientAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    if(bind(socketFD, (const struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0){
        printf("Error In Bind.\n");
        exit(EXIT_FAILURE);
    }
    char sentences[5][1000];
    int len = sizeof(clientAddress);
    numOfCharacterRecieved = recvfrom(socketFD, sentences, sizeof(sentences), 0, (struct sockaddr *)&clientAddress, &len);
    printf("Data Recieved\n");
    int numOfWord = toReturnNumOfWords(sentences);
    sendto(socketFD, &numOfWord, sizeof(int), 0, (const struct sockaddr *)&clientAddress, len);
    printf("%d \n", numOfWord);
}