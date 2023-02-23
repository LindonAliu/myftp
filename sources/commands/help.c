/*
** EPITECH PROJECT, 2023
** help
** File description:
** FreeKOSOVO
*/

#include "server.h"
#include "all_lib.h"
#include "builtins_array.h"

int help(UNUSED const char **cmd, struct server *server UNUSED,UNUSED int index)
{
    dprintf(server->clients[index]->cfd, code_214);
    return 0;
}
