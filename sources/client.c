/*
** EPITECH PROJECT, 2023
** client
** File description:
** FreeKOSOVO
*/

#include "client.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtins_array.h"

#include <stdio.h> // printf

void refresh_client(struct client **clients, fd_set *fds, int *sfd)
{
    if (clients == NULL)
        return;
    FD_ZERO(fds);
    FD_SET(*sfd, fds);
    for (int i = 0; clients[i] != NULL; i++)
        FD_SET(clients[i]->cfd, fds);
}

void destroy_client(struct client *client)
{
    if (!client)
        return;
    close(client->cfd);
    if (client->buffer)
        free(client->buffer);
    destroy_account(&client->a);
    free(client);
}

void destroy_clients(struct client **clients)
{
    if (!clients)
        return;
    for (int i = 0; clients[i] != NULL; i++)
        destroy_client(clients[i]);
    free(clients);
}

void add_client(struct client **clients, int cfd, fd_set *fds)
{
    int i = 0;

    if (cfd < 0)
        return;
    for (; clients[i] != NULL; i++) {
        if (clients[i]->cfd == cfd)
            return;
    }
    clients[i] = malloc(sizeof(struct client));
    clients[i]->cfd = cfd;
    clients[i]->buffer = NULL;
    clients[i]->a = (struct account){NULL, NULL, NULL, 0};
    clients[i + 1] = NULL;
    FD_SET(cfd, fds);
    dprintf(cfd, code_220);
}

void print_clients(struct client **clients)
{
    if (!clients)
        return;
    for (int i = 0; clients[i] != NULL; i++)
        printf("(%d)->", clients[i]->cfd);
    printf("end\n");
}
