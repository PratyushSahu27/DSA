#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <math.h>
int oddEvenCheck(int number){
    return (number%2 ? 1 : 0);
}
int primeCheck(int number){
    for(int i=2; i*i<=number; ++i){
        if(number % i == 0)
            return 0;
    }
    return 1;
}
int armstrongCheck(int number){
    int temp = number;
    int digitSum = 0;
    int rem;
    while(temp){
        rem = temp % 10;
        temp/=10;
        digitSum+=(rem*rem*rem);
    }
    if(digitSum == number)
        return 1;
    return 0;
}
int main(){
    struct sockaddr_in clientAddress, serverAddress;
    int socketFD, clientSocketFD;
    if((socketFD = socket(AF_INET, SOCK_STREAM, 0))<0){
        printf("Error In Socket Creation.\n");
        exit(EXIT_FAILURE);
    }
    memset(&serverAddress, 0, sizeof(serverAddress));
    memset(&clientAddress, 0, sizeof(clientAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8050);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    if(bind(socketFD, (const struct sockaddr *)&serverAddress, sizeof(serverAddress))<0){
        printf("Error In Binding!");
        exit(-1);
    }
    if((listen(socketFD, 3))<0){
        printf("Error In Listening!");
        exit(-1);
    }
    int len = sizeof(clientAddress);
    if((clientSocketFD = accept(socketFD, (struct sockaddr *)&clientAddress, (socklen_t *)&len)) < 0){
        printf("Error In Accept!");
        exit(-1);
    }
    int number;
    int n = read(clientSocketFD, &number, sizeof(int));
    int ans1 = oddEvenCheck(number);
    int ans2 = primeCheck(number);
    int ans3 = armstrongCheck(number);
    printf("%d %d %d\n", ans1, ans2, ans3);
    send(clientSocketFD, &ans1, sizeof(int), 0);
    send(clientSocketFD, &ans2, sizeof(int), 0);
    send(clientSocketFD, &ans3, sizeof(int), 0);
    close(socketFD);
    close(clientSocketFD);
}