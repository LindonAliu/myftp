/*
** EPITECH PROJECT, 2023
** user
** File description:
** FreeKOSOVO
*/

#include "builtins_array.h"
#include <string.h>

int user(const char **cmd, struct server *server, int index)
{
    if (cmd[1] == NULL) {
        dprintf(server->clients[index]->cfd, code_501);
        return 0;
    }
    if (server->clients[index]->a.username != NULL)
        destroy_account(&server->clients[index]->a);
    create_account(&server->clients[index]->a, strdup(cmd[1]), NULL);
    server->clients[index]->a.connected = 1;
    dprintf(server->clients[index]->cfd, code_331);
    return 0;
}
