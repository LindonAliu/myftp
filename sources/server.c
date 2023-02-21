/*
** EPITECH PROJECT, 2023
** server
** File description:
** FreeKOSOVO
*/

#include "my_ftp.h"

int set_server(char const *port, char const *path)
{
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(atoi(port)),
        .sin_addr = (struct in_addr){.s_addr = htonl(INADDR_ANY)}
    };

    if (bind(sfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Error: bind");
        return -1;
    }
    if (listen(sfd, SOMAXCONN) == -1) {
        perror("Error: listen");
        return -1;
    }
    if (chdir(path) < 0) {
        perror("Error: chdir");
        return -1;
    }
    return sfd;
}
