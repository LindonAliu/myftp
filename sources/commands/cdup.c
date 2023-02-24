/*
** EPITECH PROJECT, 2023
** cdup
** File description:
** FreeKOSOVO
*/

#include "server.h"
#include "all_lib.h"
#include "builtins_array.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int cdup(const char **cmd, struct server *server, int index)
{
    if (my_len_array(cmd) != 1) {
        dprintf(server->clients[index]->cfd, code_501);
        return 0;
    }
    if (chdir(server->path) == -1) {
        dprintf(server->clients[index]->cfd, code_550);
        return 0;
    }
    if (server->clients[index]->working_dir)
        free(server->clients[index]->working_dir);
    server->clients[index]->working_dir = strdup(server->path);
    dprintf(server->clients[index]->cfd, code_200);
    return 0;
}
