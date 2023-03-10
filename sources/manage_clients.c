/*
** EPITECH PROJECT, 2023
** manage_clients
** File description:
** FreeKOSOVO
*/

#include "all_lib.h"
#include "builtins_array.h"
#include "server.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <stdio.h>

static int end_of_file_detected(char *buffer)
{
    if (buffer == NULL)
        return 0;
    if (strstr(buffer, "\r\n") != NULL)
        return 1;
    return 0;
}

static int buffer_handling(struct server *server, int index)
{
    char **commands = NULL;
    char **cmd = NULL;

    if (!end_of_file_detected(server->clients[index]->buffer))
        return 0;
    commands = my_stwa_separator(server->clients[index]->buffer, "\r\n");
    if (commands == NULL || commands[0] == NULL)
        return -1;
    cmd = my_stwa_separator(commands[0], " ");
    if (cmd == NULL)
        return -1;
    my_free_array(commands);
    if (command_handling((const char **)cmd, server, index) < 0)
        dprintf(server->clients[index]->cfd, code_500);
    my_free_array(cmd);
    return 0;
}

static int client_is_readable(struct server *server, int index, fd_set *fds)
{
    if (server->clients[index] == NULL ||
        !FD_ISSET(server->clients[index]->cfd, fds))
        return 0;
    return 1;
}

static void destroy_buffer(struct server *server, int index)
{
    if (server->clients[index] == NULL)
        return;
    if (server->clients[index]->buffer != NULL)
        free(server->clients[index]->buffer);
    server->clients[index]->buffer = NULL;
}

void manage_clients(struct server *server, fd_set *fds)
{
    size_t size = 0;

    for (int i = 0; i < FD_SETSIZE; i++) {
        if (!client_is_readable(server, i, fds))
            continue;
        if (getline(&server->clients[i]->buffer, &size,
                server->clients[i]->stream) < 0) {
            destroy_client(server->clients[i]);
            server->clients[i] = NULL;
            continue;
        }
        server->clients[i]->buffer[size - 1] = '\0';
        buffer_handling(server, i);
        destroy_buffer(server, i);
    }
}
