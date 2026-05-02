#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()
#include "tcp_socket_conn.h"
#define MAX 80
#define PORT 8080
#define LOCALHOST "127.0.0.1"
#define SA struct sockaddr

void func(int sockfd)
{
    char buff[MAX];
    int n;
    memset(&buff, '\0', MAX);
    while ((strncmp(buff, "exit", 4)) != 0)
    {
        log_client_message(CLIENT, "");
        n = 0;
        while ((buff[n++] = getchar()) != '\n')
            ;
        write(sockfd, buff, sizeof(buff));
        memset(&buff, '\0', MAX);
        log_client_message(CLIENT, "waiting for server message...\n");
        read(sockfd, buff, sizeof(buff));
        log_server_message(CLIENT, buff);
    }
    log_client_message(CLIENT, "EXIT FROM SERVER, BYE!\n");
}

int main()
{
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    memset(&servaddr, '\0', sizeof(servaddr)); // bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(LOCALHOST);
    servaddr.sin_port = htons(PORT);

    // connect the client socket to server socket
    if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) != 0)
    {
        printf("connection with the server failed...\n");
        exit(0);
    }

    // function for chat
    func(sockfd);

    // close the socket
    close(sockfd);
}