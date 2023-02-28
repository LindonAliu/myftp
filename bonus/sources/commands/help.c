/*
** EPITECH PROJECT, 2023
** help
** File description:
** FreeKOSOVO
*/

#include "server.h"
#include "all_lib.h"
#include "builtins_array.h"

int help(const char **cmd, struct server *server, int index)
{
    if (my_len_array(cmd) > 2) {
        dprintf(server->clients[index]->cfd, code_501);
        return 0;
    }
    dprintf(server->clients[index]->cfd, code_214);
    return 0;
}
