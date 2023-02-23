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

static int buffer_handling(struct client **clients, int index)
{
    char **commands = NULL;
    char **cmd = NULL;

    if (!end_of_file_detected(clients[index]->buffer))
        return 0;
    commands = my_stwa_separator(clients[index]->buffer, "\r\n");
    if (commands == NULL)
        return -1;
    cmd = my_stwa_separator(commands[0], " ");
    if (cmd == NULL)
        return -1;
    command_handling((const char **)cmd, clients, index);
    my_free_array(cmd);
    my_free_array(commands);
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
        buffer_handling(clients, i);
    }
    return 0;
}
