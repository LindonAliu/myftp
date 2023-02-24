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
    if (my_len_array(cmd) != 1) {
        dprintf(server->clients[index]->cfd, code_501);
        return 0;
    }
    dprintf(server->clients[index]->cfd, code_200);
    return 0;
}
