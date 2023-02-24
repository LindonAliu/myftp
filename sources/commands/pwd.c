/*
** EPITECH PROJECT, 2023
** pwd
** File description:
** FreeKOSOVO
*/

#include "server.h"
#include "all_lib.h"
#include "builtins_array.h"
#include <unistd.h>

int pwd(const char **cmd, struct server *server, int index)
{
    char *pwd = NULL;

    if (my_len_array(cmd) != 1) {
        dprintf(server->clients[index]->cfd, code_501);
        return 0;
    }
    printf("pwd:(wd[%d]: %s)\n", index, server->clients[index]->working_dir);
    chdir(server->clients[index]->working_dir);
    pwd = getcwd(pwd, 0);
    dprintf(server->clients[index]->cfd, code_257, pwd);
    return 0;
}
