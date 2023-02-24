/*
** EPITECH PROJECT, 2023
** server
** File description:
** FreeKOSOVO
*/

#include "server.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

static int set_server(struct server *server,
    struct sockaddr_in addr, const char *path)
{
    if (bind(server->sfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Error: bind");
        return -1;
    }
    if (listen(server->sfd, SOMAXCONN) == -1) {
        perror("Error: listen");
        return -1;
    }
    if (chdir(path) < 0) {
        perror("Error: chdir");
        return -1;
    }
    server->path = getcwd(NULL, 0);
    return 0;
}

struct server *create_server(int port, const char *path)
{
    struct server *server = malloc(sizeof(struct server));
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr = (struct in_addr){.s_addr = htonl(INADDR_ANY)}
    };

    if (!server)
        return server;
    server->clients = malloc(sizeof(struct client *) * 1024);
    if (server->clients == NULL)
        return NULL;
    memset(server->clients, 0, sizeof(struct client *) * 1024);
    server->sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->sfd < 0)
        return NULL;
    if (set_server(server, addr, path) < 0)
        return NULL;
    return server;
}

void destroy_server(struct server *server)
{
    if (!server)
        return;
    destroy_clients(server->clients);
    if (server->path != NULL)
        free(server->path);
    free(server);
}
