/*
** EPITECH PROJECT, 2023
** stor
** File description:
** FreeKOSOVO
*/

#include "server.h"
#include "all_lib.h"
#include "builtins_array.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>

static int error_handling_stor(const char **cmd,
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

static void print_data_in_stream(FILE *stream, FILE *data)
{
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, data) != -1) {
        if (strcmp(line, "\r\n") == 0 || strcmp(line, "\n") == 0)
            break;
        fprintf(stream, "%s", line);
    }
    if (line)
        free(line);
}

static void do_stor(FILE *f, FILE *data, struct server *server, int index)
{
    dprintf(server->clients[index]->cfd, code_150);
    print_data_in_stream(f, data);
    fclose(f);
    fclose(data);
    destroy_mode(&server->clients[index]->m);
    dprintf(server->clients[index]->cfd, code_226);
}

static int open_files(int fds[2], const char *path, FILE **f, FILE **data)
{
    *data = fdopen(fds[1], "r");
    if (*data == NULL) {
        dprintf(fds[0], code_425);
        return -1;
    }
    *f = fopen(path, "w+");
    if (*f == NULL) {
        dprintf(fds[0], code_550);
        return -1;
    }
    return 0;
}

int stor(const char **cmd, struct server *server, int index)
{
    FILE *f = NULL;
    FILE *data = NULL;
    int fd = 0;
    int fds[2];

    if (error_handling_stor(cmd, server, index) == -1)
        return 0;
    fd = server->clients[index]->m.type != ACTIVE ?
        accept(server->clients[index]->m.sfd, NULL, NULL) :
        check_connect(server, index);
    if (fd == -1) {
        dprintf(server->clients[index]->cfd, code_425);
        return 0;
    }
    fds[1] = fd;
    fds[0] = server->clients[index]->cfd;
    if (open_files(fds, cmd[1], &f, &data) == -1 || data == NULL || f == NULL)
        return 0;
    do_stor(f, data, server, index);
    return 0;
}
