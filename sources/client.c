/*
** EPITECH PROJECT, 2023
** client
** File description:
** FreeKOSOVO
*/

#include "client.h"
#include <string.h>
#include <stdlib.h>

#include <stdio.h> // printf

void refresh_client(struct client **clients, fd_set *fds, int *sfd)
{
    if (clients == NULL)
        return;
    FD_ZERO(fds);
    FD_SET(*sfd, fds);
    for (int i = 0; clients[i] != NULL; i++)
        FD_SET(clients[i]->cfd, fds);
}

void destroy_client(struct client *client)
{
    if (!client)
        return;
    if (client->buffer)
        free(client->buffer);
    free(client);
}

void destroy_clients(struct client **clients)
{
    if (!clients)
        return;
    for (int i = 0; clients[i] != NULL; i++)
        destroy_client(clients[i]);
    free(clients);
}

void add_client(struct client **clients, int cfd, fd_set *fds)
{
    int i = 0;

    if (cfd < 0)
        return;
    for (; clients[i] != NULL; i++) {
        if (clients[i]->cfd == cfd)
            return;
    }
    clients[i] = malloc(sizeof(struct client));
    clients[i]->cfd = cfd;
    clients[i]->buffer = NULL;
    clients[i + 1] = NULL;
    FD_SET(cfd, fds);
}

void print_clients(struct client **clients)
{
    if (!clients)
        return;
    for (int i = 0; clients[i] != NULL; i++)
        printf("(%d)->", clients[i]->cfd);
    printf("end\n");
}

// static int check_select(int nfds, fd_set *readfds, fd_set *writefds)
// {
//     int ret = select(nfds, readfds, writefds, NULL, NULL);

//     if (ret < 0) {
//         perror("Error: select");
//         return -1;
//     }
//     return ret;
// }

// static int check_accept(int sfd,
//     struct sockaddr_in *c_addr, socklen_t *c_len)
// {
//     int cfd = accept(sfd, (struct sockaddr *)c_addr, c_len);

//     if (cfd < 0) {
//         perror("Error: accept");
//         return -1;
//     }
//     return cfd;
// }

// static int manage_clients(struct list_fd **list, fd_set *_sfd)
// {
//     char buffer[4096];
//     struct list_fd *tmp = *list;
//     int ret = -1;

//     memset(buffer, 0, 4096);
//     while (tmp != NULL) {
//         if (!FD_ISSET(tmp->fd, _sfd)) {
//             tmp = tmp->next;
//             continue;
//         }
//         ret = read(tmp->fd, buffer, 4096);
//         if (ret == 0) {
//             delete_fd_in_list(list, tmp->fd);
//             tmp = *list;
//             break;
//         }
//         // buffer_handling(buffer, tmp->fd, list);
//         // tmp = *list;
//         write(1, buffer, strlen(buffer));
//         if (tmp != NULL)
//             tmp = tmp->next;
//     }
//     return 0;
// }

// static void refresh_list(struct list_fd *list, fd_set *_sfd)
// {
//     if (list == NULL)
//         return;
//     FD_ZERO(_sfd);
//     while (list != NULL) {
//         FD_SET(list->fd, _sfd);
//         list = list->next;
//     }
// }

// int handle_client(int sfd)
// {
//     int cfd = -1;
//     struct list_fd *list = NULL;
//     struct sockaddr_in c_addr;
//     socklen_t c_len = sizeof(c_addr);
//     fd_set _sfd;
//     int ret = -1;

//     FD_ZERO(&_sfd);
//     FD_SET(sfd, &_sfd);
//     while (1) {
//         refresh_list(list, &_sfd);
//         // print_list(list);
//         ret = check_select(FD_SETSIZE, &_sfd, NULL);
//         if (ret < 0)
//             return -1;
//         if (ret == 0)
//             continue;
//         if (FD_ISSET(sfd, &_sfd)) {
//             cfd = check_accept(sfd, &c_addr, &c_len);
//             if (cfd < 0)
//                 continue;
//             if (list == NULL)
//                 list = create_list(cfd);
//             else
//                 add_list(list, cfd);
//         }
//         manage_clients(&list, &_sfd);
//     }
// }
