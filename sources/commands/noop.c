/*
** EPITECH PROJECT, 2023
** noop
** File description:
** FreeKOSOVO
*/

#include "server.h"
#include "all_lib.h"
#include "builtins_array.h"

int noop(UNUSED const char **cmd, UNUSED struct server *server, UNUSED int index)
{
    dprintf(server->clients[index]->cfd, code_200);
    return 0;
}
