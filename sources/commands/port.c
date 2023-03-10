/*
** EPITECH PROJECT, 2023
** port
** File description:
** FreeKOSOVO
*/

#include "server.h"
#include "all_lib.h"
#include "builtins_array.h"
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

static int error_handling_port(const char **cmd,
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
    if (server->clients[index]->m.type != NONE)
        destroy_mode(&server->clients[index]->m);
    return 0;
}

static int get_socket(struct server *server, int index)
{
    int sfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sfd < 0) {
        dprintf(server->clients[index]->cfd, code_425);
        return -1;
    }
    return sfd;
}

static int get_port(const char *cmd, struct server *server, int index)
{
    char **ip = my_stwa_separator(cmd, ",");
    int port = 0;

    if (my_len_array((const char **)ip) != 6) {
        dprintf(server->clients[index]->cfd, code_501);
        my_freef("%t", ip);
        return -1;
    }
    port = atoi(ip[4]) * 256 + atoi(ip[5]);
    my_freef("%t", ip);
    return port;
}

int check_connect(struct server *server, int index)
{
    if (connect(server->clients[index]->m.sfd,
            (struct sockaddr *)&server->clients[index]->m.addr,
            sizeof(server->clients[index]->m.addr)) < 0) {
        return -1;
    }
    return server->clients[index]->m.sfd;
}

int port(const char **cmd, struct server *server, int index)
{
    struct sockaddr_in addr = { .sin_family = AF_INET,
        .sin_addr = (struct in_addr){.s_addr = htonl(INADDR_ANY)} };
    int port = 0;

    if (error_handling_port(cmd, server, index) == -1)
        return 0;
    port = get_port(cmd[1], server, index);
    if (port == -1)
        return 0;
    addr.sin_port = htons(port);
    server->clients[index]->m.addr = addr;
    server->clients[index]->m.sfd = get_socket(server, index);
    if (server->clients[index]->m.sfd == -1)
        return 0;
    server->clients[index]->m.type = ACTIVE;
    dprintf(server->clients[index]->cfd, code_200);
    return 0;
}
