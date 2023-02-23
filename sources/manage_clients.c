/*
** EPITECH PROJECT, 2023
** manage_clients
** File description:
** FreeKOSOVO
*/

#include "all_lib.h"

#include "server.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>

static int handle_client(struct client *client)
{
    char **cmd = my_stwa_separator(client->buffer, "\r\n");

    if (cmd == NULL)
        return 0;
    for (int i = 0; cmd[i] != NULL; i++)
        printf("cmd[%d]: %s\n", i, cmd[i]);
    my_free_array(cmd);
    free(client->buffer);
    client->buffer = NULL;
    return 0;
}

int manage_clients(struct client **clients, fd_set *fds)
{
    for (int i = 0; clients[i] != NULL; i++) {
        if (!FD_ISSET(clients[i]->cfd, fds))
            continue;
        if (clients[i]->buffer == NULL) {
            clients[i]->buffer = malloc(sizeof(char) * 4096);
            memset(clients[i]->buffer, 0, 4096);
        }
        if (read(clients[i]->cfd, clients[i]->buffer, 4096) <= 0) {
            destroy_client(clients[i]);
            clients[i] = NULL;
            continue;
        }
        handle_client(clients[i]);
    }
    return 0;
}
