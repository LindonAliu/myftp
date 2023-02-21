/*
** EPITECH PROJECT, 2023
** handle_list
** File description:
** FreeKOSOVO
*/

#include "my_ftp.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void create_list(struct list_fd *list, int fd)
{
    struct list_fd *new = malloc(sizeof(struct list_fd));

    new->fd = fd;
    new->next = list;
    list = new;
}

void delete_fd_in_list(struct list_fd *list, int fd)
{
    struct list_fd *tmp = list;

    while (tmp->next != NULL) {
        if (tmp->next->fd == fd) {
            tmp->next = tmp->next->next;
            break;
        }
        tmp = tmp->next;
    }
}

void delete_all_list(struct list_fd *list)
{
    struct list_fd *tmp = list;

    while (tmp->next != NULL) {
        tmp = tmp->next;
        close(tmp->fd);
        free(tmp);
    }
    free(list);
}

void add_list(struct list_fd *list, int fd)
{
    struct list_fd *tmp = list;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = malloc(sizeof(struct list_fd));
    tmp->next->fd = fd;
    tmp->next->next = NULL;
}
