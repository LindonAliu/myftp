/*
** EPITECH PROJECT, 2023
** server
** File description:
** FreeKOSOVO
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include "client.h"

struct server {
    int sfd;
    struct client **clients;
    char *path;
};

struct server *create_server(int port, const char *path);
void destroy_server(struct server *server);
int manage_clients(struct client **clients, fd_set *fds);

#endif /* !SERVER_H_ */
