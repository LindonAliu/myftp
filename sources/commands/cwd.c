/*
** EPITECH PROJECT, 2023
** cwd
** File description:
** FreeKOSOVO
*/

#include "server.h"
#include "all_lib.h"
#include "builtins_array.h"
#include <unistd.h>
#include <stdlib.h>

int cwd(const char **cmd, struct server *server, int index)
{
    printf("(wd[%d]: %s)\n", index, server->clients[index]->working_dir);
    chdir(server->clients[index]->working_dir);
    if (my_len_array(cmd) != 2) {
        dprintf(server->clients[index]->cfd, code_501);
        return 0;
    }
    if (server->clients[index]->a.connected < 2) {
        dprintf(server->clients[index]->cfd, code_530);
        return 0;
    }
    if (chdir(cmd[1]) == -1) {
        dprintf(server->clients[index]->cfd, code_550);
        return 0;
    }
    if (server->clients[index]->working_dir)
        free(server->clients[index]->working_dir);
    server->clients[index]->working_dir = getcwd(NULL, 0);
    printf("(wd[%d]: %s)\n", index, server->clients[index]->working_dir);
    dprintf(server->clients[index]->cfd, code_250);
    return 0;
}
