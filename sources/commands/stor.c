/*
** EPITECH PROJECT, 2023
** stor
** File description:
** FreeKOSOVO
*/

#include "server.h"
#include "all_lib.h"
#include "builtins_array.h"

static int error_handling_stor(const char **cmd,
    struct server *server, int index)
{
    if (server->clients[index]->a.connected < 2) {
        dprintf(server->clients[index]->cfd, code_530);
        return -1;
    }
    if (my_len_array(cmd) > 2) {
        dprintf(server->clients[index]->cfd, code_501);
        return -1;
    }
    if (server->clients[index]->m.type == NONE) {
        dprintf(server->clients[index]->cfd, code_425);
        return -1;
    }
    return 0;
}

int stor(const char **cmd, struct server *server, int index)
{
    if (error_handling_stor(cmd, server, index) == -1)
        return -1;
    dprintf(server->clients[index]->cfd, code_150);
    dprintf(server->clients[index]->cfd, code_226);
    return 0;
}
