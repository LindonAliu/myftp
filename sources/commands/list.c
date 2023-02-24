/*
** EPITECH PROJECT, 2023
** list
** File description:
** FreeKOSOVO
*/

#include "server.h"
#include "all_lib.h"
#include "builtins_array.h"

static int error_handling_list(const char **cmd,
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
    return 0;
}

int list(const char **cmd, struct server *server , int index)
{
    int len = my_len_array(cmd);

    if (error_handling_list(cmd, server, index) < 0)
        return 0;
    if (len == 1) {
        dprintf(server->clients[index]->cfd, code_150);
        dprintf(server->clients[index]->cfd, code_226);
    } else {
        dprintf(server->clients[index]->cfd, code_150);
        dprintf(server->clients[index]->cfd, code_226);
    }
    return 0;
}
