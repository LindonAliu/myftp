/*
** EPITECH PROJECT, 2023
** pasv
** File description:
** FreeKOSOVO
*/

#include "server.h"
#include "all_lib.h"

int pasv(UNUSED const char **cmd, UNUSED struct server *server, UNUSED int index)
{
    printf("%s\n", cmd[0]);
    return 0;
}
