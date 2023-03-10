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
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

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
    if (server->clients[index]->m.type == NONE) {
        dprintf(server->clients[index]->cfd, code_425);
        return -1;
    }
    return 0;
}

static void print_list_in_fd(int fd, FILE *f)
{
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, f) != -1)
        dprintf(fd, "%s", line);
    if (line)
        free(line);
}

void list_dir(const char *path, struct server *server, int index)
{
    FILE *f = NULL;
    char *cmd = my_strcat(strdup("ls -la "), path == NULL ? "" : path);
    int fd = server->clients[index]->m.type != ACTIVE ?
        accept(server->clients[index]->m.sfd, NULL, NULL) :
        server->clients[index]->m.sfd;

    printf("fd = %d\n", fd);

    f = popen(cmd, "r");
    free(cmd);
    if (f == NULL) {
        dprintf(server->clients[index]->cfd, code_550);
        return;
    }
    dprintf(server->clients[index]->cfd, code_150);
    print_list_in_fd(fd, f);
    pclose(f);
    close(fd);
    destroy_mode(&server->clients[index]->m);
    dprintf(server->clients[index]->cfd, code_226);
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
