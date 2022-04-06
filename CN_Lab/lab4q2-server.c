#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080
char* armstrongNum(int n){
    int originalNum = n;
    int remainder,result;
        while (originalNum != 0) {
            remainder = originalNum % 10;
            
            result += remainder * remainder * remainder;
            originalNum /= 10;
        }

        if (result == n)
            return "Yes";
        return "No";
}
int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int num;
    char* result;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t *)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    valread = read(new_socket, &num, sizeof(int));
    
    printf("%d received from client\n", num);
    result = armstrongNum(num);
    send(new_socket, result, strlen(result), 0);
    printf("result sent = %s\n",result);
    close(new_socket); // closes this particular connection
    close(server_fd); // server cannot accept any more connections
    return 0;
}
