/*
** EPITECH PROJECT, 2023
** port
** File description:
** FreeKOSOVO
*/

#include "server.h"
#include "all_lib.h"
#include "builtins_array.h"

int port(const char **cmd, struct server *server, int index)
{
    if (my_len_array(cmd) != 2) {
        dprintf(server->clients[index]->cfd, code_501);
        return 0;
    }
    if (server->clients[index]->a.connected < 2) {
        dprintf(server->clients[index]->cfd, code_530);
        return 0;
    }
    dprintf(server->clients[index]->cfd, code_200);
    return 0;
}
