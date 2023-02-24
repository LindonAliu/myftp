/*
** EPITECH PROJECT, 2023
** dele
** File description:
** FreeKOSOVO
*/

#include "server.h"
#include "all_lib.h"
#include "builtins_array.h"

int dele(const char **cmd, struct server *server, int index)
{
    if (my_len_array(cmd) != 2) {
        dprintf(server->clients[index]->cfd, code_501);
        return 0;
    }
    if (remove(cmd[1]) == -1) {
        dprintf(server->clients[index]->cfd, code_550);
        return 0;
    }
    dprintf(server->clients[index]->cfd, code_250);
    return 0;
}
