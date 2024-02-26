#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr client;
    char data[1024];
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        error("Falla socket");
    }
    client.sa_family = AF_UNIX;
    strcpy(client.sa_data, argv[1]);
    if (connect(sockfd, &client, sizeof(client)) < 0)
    {
        close(sockfd);
        error("Falla connect");
    }

    while (fgets(data, 1024, stdin))
    {
        if (send(sockfd, data, strlen(data), 0) == -1)
        {
            error("Falla send");
        }
    }
    close(sockfd);
    return 0;
}
