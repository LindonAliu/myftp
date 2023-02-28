/*
** EPITECH PROJECT, 2023
** retr
** File description:
** FreeKOSOVO
*/

#include "server.h"
#include "all_lib.h"
#include "builtins_array.h"

int retr(const char **cmd, struct server *server, int index)
{
    if (my_len_array(cmd) != 2) {
        dprintf(server->clients[index]->cfd, code_501);
        return 0;
    }
    if (server->clients[index]->a.connected < 2) {
        dprintf(server->clients[index]->cfd, code_530);
        return 0;
    }
    dprintf(server->clients[index]->cfd, code_150);
    dprintf(server->clients[index]->cfd, code_226);
    return 0;
}
