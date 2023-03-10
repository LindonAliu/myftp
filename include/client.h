/*
** EPITECH PROJECT, 2023
** client
** File description:
** FreeKOSOVO
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #include <sys/select.h>
    #include <stdio.h> // printf

    #define NONE 0
    #define PASSIVE 1
    #define ACTIVE 2

struct account {
    char *username;
    char *password;
    int connected;
};

struct mode {
    int type;
    int sfd;
};

struct client {
    struct account a;
    char *buffer;
    char *working_dir;
    FILE *stream;
    int cfd;
    struct mode m;
};

//clients
void refresh_client(struct client **clients, fd_set *fds, int *sfd);
void destroy_client(struct client *client);
void destroy_clients(struct client **clients);
void add_client(struct client **clients, int cfd, fd_set *fds,
    const char *path);
void print_clients(struct client **clients);

//accounts
void create_account(struct account *account, char *username, char *password);
void destroy_account(struct account *account);
void print_account(struct account *account);

//mode
void destroy_mode(struct mode *mode);

#endif /* !CLIENT_H_ */
