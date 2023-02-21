/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** FreeKOSOVO
*/

#ifndef MY_FTP_H_
    #define MY_FTP_H_

    #include "my.h"
    #include <sys/socket.h>
    #include <netinet/in.h>

    #include <arpa/inet.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/select.h>

// list handling
struct list_fd {
    int fd;
    struct list_fd *next;
};

void create_list(struct list_fd *list, int fd);
void delete_fd_in_list(struct list_fd *list, int fd);
void delete_all_list(struct list_fd *list);
void add_list(struct list_fd *list, int fd);

//ftp handling
int error_handling(int ac, char const *av[]);
int my_ftp(const char *port, const char *path);
int handle_client(int sfd);
int set_server(char const *port, char const *path);

#endif/* !MY_FTP_H_ */
