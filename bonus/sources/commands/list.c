/*
** EPITECH PROJECT, 2023
** list
** File description:
** FreeKOSOVO
*/

#include "server.h"
#include "all_lib.h"
#include "builtins_array.h"
#include <stdlib.h>
#include <string.h>

static int error_handling_list(const char **cmd,
    struct server *server, int index)
{
    if (server->clients[index]->a.connected < 2) {
        dprintf(server->clients[index]->cfd, code_530);
        return -1;
    }
    if (my_len_array(cmd) > 2) {
        dprintf(server->clients[index]->cfd, code_501);
        return -1;
    }
    return 0;
}

static int list_dir(const char *path, struct server *server, int index)
{
    FILE *f = NULL;
    char *line = NULL;
    size_t len = 0;
    char *cmd = my_strcat(strdup("ls -la "), path == NULL ? "" : path);

    f = popen(cmd, "r");
    printf("cmd = %s\n", cmd);
    free(cmd);
    if (f == NULL) {
        dprintf(server->clients[index]->cfd, code_550);
        return -1;
    }
    dprintf(server->clients[index]->cfd, code_150);
    while (getline(&line, &len, f) != -1)
        dprintf(server->clients[index]->cfd, "%s", line);
    pclose(f);
    if (line)
        free(line);
    dprintf(server->clients[index]->cfd, code_226);
    return 0;
}

int list(const char **cmd, struct server *server , int index)
{
    int len = my_len_array(cmd);
    const char *path = NULL;

    if (error_handling_list(cmd, server, index) < 0)
        return 0;
    path = len == 1 ? server->path : cmd[1];
    list_dir(path, server, index);
    return 0;
}
