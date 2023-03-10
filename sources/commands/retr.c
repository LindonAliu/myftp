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
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

static int error_handling_retr(const char **cmd,
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

static void print_data_in_fd(int fd, FILE *data)
{
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, data) != -1)
        dprintf(fd, "%s", line);
    if (line)
        free(line);
}

int retr(const char **cmd, struct server *server, int index)
{
    FILE *f = 0;
    int fd = 0;

    if (error_handling_retr(cmd, server, index) == -1)
        return 0;
    fd = server->clients[index]->m.type != ACTIVE ?
        accept(server->clients[index]->m.sfd, NULL, NULL) :
        server->clients[index]->m.sfd;
    dprintf(server->clients[index]->cfd, code_150);
    f = fopen(cmd[1], "r");
    if (f == NULL) {
        dprintf(server->clients[index]->cfd, code_550);
        return 0;
    }
    print_data_in_fd(fd, f);
    pclose(f);
    close(fd);
    destroy_mode(&server->clients[index]->m);
    dprintf(server->clients[index]->cfd, code_226);
    return 0;
}
