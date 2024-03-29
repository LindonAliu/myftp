/*
** EPITECH PROJECT, 2023
** my_ftp
** File description:
** FreeKOSOVO
*/

#include "my_ftp.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int close_ftp = 0;

static void sig_handler(int signo)
{
    if (signo == SIGINT)
        close_ftp = 1;
}

static int check_select(int nfds, fd_set *readfds, fd_set *writefds)
{
    struct timeval tv = {0.5, 0.5};
    int ret = select(nfds, readfds, writefds, NULL, &tv);

    if (ret < 0) {
        return -1;
    }
    return ret;
}

static int check_accept(int sfd)
{
    struct sockaddr_in *c_addr = NULL;
    socklen_t c_len = 0;
    int cfd = accept(sfd, (struct sockaddr *)c_addr, &c_len);

    if (cfd < 0) {
        perror("Error: accept");
        return -1;
    }
    return cfd;
}

static int handle_ftp(struct server *server)
{
    fd_set server_fd;
    int ret = 0;

    while (close_ftp == 0) {
        refresh_client(server->clients, &server_fd, &server->sfd);
        ret = check_select(FD_SETSIZE, &server_fd, NULL);
        if (ret < 0)
            break;
        if (ret == 0)
            continue;
        if (FD_ISSET(server->sfd, &server_fd))
            add_client(server->clients, check_accept(server->sfd),
                &server_fd, server->path);
        else
            manage_clients(server, &server_fd);
    }
    return 0;
}

int my_ftp(const char *port, const char *path)
{
    struct server *server = create_server(atoi(port), path);
    int ret = 0;

    if (!server)
        return -1;
    signal(SIGINT, sig_handler);
    ret = handle_ftp(server);
    destroy_server(server);
    return ret;
}
