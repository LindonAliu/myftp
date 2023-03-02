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

static int error_handling_cdup(const char **cmd,
    struct server *server, int index)
{
    if (my_len_array(cmd) != 1) {
        dprintf(server->clients[index]->cfd, code_501);
        return -1;
    }
    if (server->clients[index]->a.connected < 2) {
        dprintf(server->clients[index]->cfd, code_530);
        return -1;
    }
    if (chdir("..") == -1) {
        dprintf(server->clients[index]->cfd, code_550);
        return -1;
    }
    return 0;
}

int cdup(const char **cmd, struct server *server, int index)
{
    char *new_path = NULL;

    chdir(server->clients[index]->working_dir);
    if (error_handling_cdup(cmd, server, index) < 0)
        return 0;
    new_path = getcwd(NULL, 0);
    if (strncmp(new_path, server->path, strlen(server->path)) != 0) {
        dprintf(server->clients[index]->cfd, code_200);
        free(new_path);
        return 0;
    }
    if (server->clients[index]->working_dir)
        free(server->clients[index]->working_dir);
    server->clients[index]->working_dir = strdup(server->path);
    dprintf(server->clients[index]->cfd, code_200);
    return 0;
}
