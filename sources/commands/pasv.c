/*
** EPITECH PROJECT, 2023
** pasv
** File description:
** FreeKOSOVO
*/

#include "server.h"
#include "all_lib.h"
#include "builtins_array.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static int generate_random_port(int serv_port)
{
    int port = 0;

    srand(time(NULL));
    while (port < 1024 || port > 65535 || port == serv_port)
        port = rand() % 65535;
    return port;
}

static int create_passive_socket(struct server *server, int index)
{
    int p = generate_random_port(server->port);
    struct sockaddr_in addr = { .sin_family = AF_INET, .sin_port = htons(p),
        .sin_addr = (struct in_addr){.s_addr = htonl(INADDR_ANY)} };
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    if (fd < 0)
        return -1;
    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0 ||
        listen(fd, FD_SETSIZE) < 0)
        return -1;
    printf("Port: %d\n", p);
    dprintf(server->clients[index]->cfd, code_227, p / 256, p % 256);
    return fd;
}

static int error_handling_pasv(const char **cmd, struct server *server,
    int index)
{
    if (my_len_array(cmd) != 1) {
        dprintf(server->clients[index]->cfd, code_501);
        return -1;
    }
    if (server->clients[index]->a.connected < 2) {
        dprintf(server->clients[index]->cfd, code_530);
        return -1;
    }
    if (server->clients[index]->m.type != NONE)
        destroy_mode(&server->clients[index]->m);
    return 0;
}

int pasv(const char **cmd, struct server *server,
    int index)
{
    if (error_handling_pasv(cmd, server, index) < 0)
        return 0;
    server->clients[index]->m.type = PASSIVE;
    server->clients[index]->m.sfd = create_passive_socket(server, index);
    if (server->clients[index]->m.sfd < 0)
        dprintf(server->clients[index]->cfd, code_425);
    return 0;
}
