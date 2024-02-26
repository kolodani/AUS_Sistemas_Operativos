#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_CLIENTS 5

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd;
    int msgsock;
    int rval;
    struct sockaddr server;
    char buf[1024];

    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        error("Falla socket");
    }

    server.sa_family = AF_UNIX;
    strcpy(server.sa_data, argv[1]);
    unlink(server.sa_data); // Para desvincular cualquier socket previo...

    if (bind(sockfd, &server, sizeof(server)))
    {
        error("Falla bind");
    }

    listen(sockfd, MAX_CLIENTS);

    for (;;)
    {
        msgsock = accept(sockfd, 0, 0);
        if (msgsock == -1)
        {
            error("Falla accept");
        }
        do
        {
            bzero(buf, sizeof(buf));                   // Inicializa el buffer
            if ((rval = read(msgsock, buf, 1024)) < 0) // lee del socket
                error("Falla lectura");
            else if (rval == 0)
            {
                printf("Conexion finalizada.\n");
                exit(0);
            }
            else
            { // Lee datos ok
                printf("-->%s\n", buf);
            }
        } while (rval > 0);
        close(msgsock);
    } // for

    close(sockfd);
    return 0;
}