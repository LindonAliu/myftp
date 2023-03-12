/*
** EPITECH PROJECT, 2023
** retr
** File description:
** FreeKOSOVO
*/

#include "builtins_array.h"
#include "server.h"
#include "all_lib.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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

static void print_data_in_fd(int fd, int fd_data)
{
    size_t size = 0;

    while (read(fd_data, &size, sizeof(size_t)) > 0)
        write(fd, &size, sizeof(size_t));
}

static void do_retr(int fd, int fd_data, struct server *server, int index)
{
    dprintf(server->clients[index]->cfd, code_150);
    print_data_in_fd(fd, fd_data);
    close(fd_data);
    close(fd);
    destroy_mode(&server->clients[index]->m);
    dprintf(server->clients[index]->cfd, code_226);
}

static int open_file(const char *path, struct server *server, int index)
{
    char *new_path = NULL;
    int fd = 0;

    asprintf(&new_path, "%s/%s", server->clients[index]->working_dir, path);
    fd = open(new_path, O_RDONLY);
    free(new_path);
    if (fd == -1) {
        dprintf(server->clients[index]->cfd, code_550);
        return -1;
    }
    return fd;
}

int retr(const char **cmd, struct server *server, int index)
{
    int fd_data = 0;
    int fd = 0;

    if (error_handling_retr(cmd, server, index) == -1)
        return 0;
    fd_data = open_file(cmd[1], server, index);
    if (fd_data == -1)
        return 0;
    fd = server->clients[index]->m.type != ACTIVE ?
        accept(server->clients[index]->m.sfd, NULL, NULL) :
        check_connect(server, index);
    if (fd == -1) {
        dprintf(server->clients[index]->cfd, code_425);
        return 0;
    }
    do_retr(fd, fd_data, server, index);
    return 0;
}
