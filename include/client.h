/*
** EPITECH PROJECT, 2023
** client
** File description:
** FreeKOSOVO
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #include <sys/select.h>

struct client {
    char *buffer;
    int cfd;
};

void refresh_client(struct client **clients, fd_set *fds, int *sfd);
void destroy_client(struct client *client);
void add_client(struct client **clients, int cfd, fd_set *fds);
void print_clients(struct client **clients);

#endif /* !CLIENT_H_ */
