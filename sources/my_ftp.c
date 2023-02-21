/*
** EPITECH PROJECT, 2023
** my_ftp
** File description:
** FreeKOSOVO
*/

#include "my_ftp.h"

int my_ftp(const char *port, const char *path)
{
    int sfd = set_server(port, path);

    if (sfd < 0)
        return -1;
    if (handle_client(sfd) < 0)
        return -1;
    return 0;
}
