/*
** EPITECH PROJECT, 2023
** port
** File description:
** FreeKOSOVO
*/

#include "server.h"
#include "all_lib.h"

int port(UNUSED const char **cmd, UNUSED struct server *server, UNUSED int index)
{
    printf("%s\n", cmd[0]);
    return 0;
}
