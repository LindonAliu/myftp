/*
** EPITECH PROJECT, 2023
** server
** File description:
** FreeKOSOVO
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include "client.h"
    #define MAX_BUFFER 4096

struct server {
    int sfd;
    struct client **clients;
    char *path;
};

struct server *create_server(int port, const char *path);
void destroy_server(struct server *server);
void manage_clients(struct server *server, fd_set *fds);
int command_handling(const char **cmd, struct server *server, int index);

#endif /* !SERVER_H_ */
