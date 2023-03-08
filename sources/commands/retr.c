/*
** EPITECH PROJECT, 2023
** retr
** File description:
** FreeKOSOVO
*/

#include "server.h"
#include "all_lib.h"
#include "builtins_array.h"
#include <stdlib.h>

static int error_handling_retro(const char **cmd,
    struct server *server, int index)
{
    if (server->clients[index]->a.connected < 2) {
        dprintf(server->clients[index]->cfd, code_530);
        return -1;
    }
    if (my_len_array(cmd) != 2) {
        dprintf(server->clients[index]->cfd, code_501);
        return -1;
    }
    if (server->clients[index]->m.type == NONE) {
        dprintf(server->clients[index]->cfd, code_425);
        return -1;
    }
    return 0;
}

static void print_data_in_fd(int fd, FILE *f)
{
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, f) != -1)
        dprintf(fd, "%s", line);
    if (line)
        free(line);
}

int retr(const char **cmd, struct server *server, int index)
{
    FILE *f = 0;
    
    if (error_handling_retro(cmd, server, index) == -1)
        return 0;
    f = fopen(cmd[1], "r");
    if (f == NULL) {
        dprintf(server->clients[index]->cfd, code_550);
        return 0;
    }
    dprintf(server->clients[index]->cfd, code_150);
    print_data_in_fd(server->clients[index]->m.fd, f);
    pclose(f);
    destroy_mode(&server->clients[index]->m);
    dprintf(server->clients[index]->cfd, code_226);
    return 0;
}
