#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT 8080
int main(){
    int socketFD, numOfCharacterRecieved;
    struct sockaddr_in serverAddress;
    if((socketFD = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        printf("Error In Socket.\n");
        exit(EXIT_FAILURE);
    }
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    char sentences[5][1000];
    for(int i=0; i<5; ++i){
        printf("Enter a sentence: ");
        scanf(" %[^\n]", sentences[i]);
    }
    int len = sizeof(serverAddress);
    sendto(socketFD, sentences, sizeof(sentences), 0, (const struct sockaddr *)&serverAddress, len);
    int answer;
    int n = recvfrom(socketFD, &answer, sizeof(int), 0, (struct sockaddr *)&serverAddress, &len);
    printf("Max Word: %d\n", answer);
    close(socketFD);
}