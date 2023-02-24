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

static int end_of_file_detected(char *buffer)
{
    if (buffer == NULL)
        return 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\r' || buffer[i] == '\n')
            return 1;
    }
    return 0;
}

static int buffer_handling(struct server *server, int index)
{
    char **commands = NULL;
    char **cmd = NULL;

    if (!end_of_file_detected(server->clients[index]->buffer))
        return 0;
    commands = my_stwa_separator(server->clients[index]->buffer, "\r\n");
    if (commands == NULL)
        return -1;
    cmd = my_stwa_separator(commands[0], " ");
    if (cmd == NULL)
        return -1;
    my_free_array(commands);
    if (command_handling((const char **)cmd, server, index) == -1)
        dprintf(server->clients[index]->cfd, code_500);
    my_free_array(cmd);
    return 0;
}

int manage_clients(struct server *server, fd_set *fds)
{
    for (int i = 0; server->clients[i] != NULL; i++) {
        if (!FD_ISSET(server->clients[i]->cfd, fds))
            continue;
        if (server->clients[i]->buffer == NULL) {
            server->clients[i]->buffer = malloc(sizeof(char) * 4096);
            memset(server->clients[i]->buffer, 0, 4096);
        }
        if (read(server->clients[i]->cfd,
            server->clients[i]->buffer, 4096) <= 0) {
            destroy_client(server->clients[i]);
            server->clients[i] = NULL;
            continue;
        }
        buffer_handling(server, i);
    }
    return 0;
}
