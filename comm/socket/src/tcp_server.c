#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> // read(), write(), close()
#include "tcp_socket_conn.h"
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

// Function designed for chat between client and server.
void func(int connfd)
{
    char buff[MAX];
    int n;
    memset(&buff, '\0', MAX);
    while (strncmp(EXIT_WORD, buff, 4) != 0)
    {
        log_server_message(CLIENT, "waiting for client message...\n");
        read(connfd, buff, sizeof(buff));
        log_client_message(SERVER, buff);
        memset(&buff, '\0', MAX);
        n = 0;
        log_server_message(SERVER, "");
        while ((buff[n++] = getchar()) != '\n')
            ;
        write(connfd, buff, sizeof(buff));
    }
}

// Driver function
int main()
{
    struct sockaddr_in servaddr, cli;
    int connfd, sockfd = socket(AF_INET, SOCK_STREAM, 0);
    socklen_t len;
    if (sockfd == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    memset(&servaddr, '\0', sizeof(servaddr));
    memset(&cli, '\0', sizeof(cli));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0)
    {
        printf("socket bind failed...\n");
        exit(0);
    }

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0)
    {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening...\n");
    len = sizeof(cli);
    connfd = accept(sockfd, (SA *)&cli, &len);
    if (connfd < 0)
    {
        printf("server accept failed...\n");
        exit(0);
    }
    else
        log_client_message(SERVER, "client in on!\n");
        log_server_message(SERVER, "waiting for client message!\n");

    // Function for chatting between client and server
    func(connfd);
    close(sockfd);
}