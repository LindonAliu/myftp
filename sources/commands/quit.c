/*
** EPITECH PROJECT, 2023
** quit
** File description:
** FreeKOSOVO
*/

#include "server.h"
#include "builtins_array.h"
#include "all_lib.h"

int quit(const char **cmd, struct server *server, int index)
{
    if (my_len_array(cmd) != 1) {
        dprintf(server->clients[index]->cfd, code_501);
        return 0;
    }
    destroy_client(server->clients[index]);
    server->clients[index] = NULL;
    return 0;
}
