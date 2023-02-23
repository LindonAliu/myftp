/*
** EPITECH PROJECT, 2023
** pass
** File description:
** FreeKOSOVO
*/

#include "builtins_array.h"
#include "all_lib.h"

static const char *get_password(char *username)
{
    //open accounts.txt and get the password
    if (my_strcmp(username, "Anonymous") == 0)
        return NULL;
    
    return NULL;
}

int pass(const char **cmd, struct server *server, int index)
{
    if (server->clients[index]->a.connected == 0) {
        dprintf(server->clients[index]->cfd, code_503);
        return 0;
    }
    if (cmd[1] == get_password(server->clients[index]->a.username)) {
        server->clients[index]->a.connected = 2;
        dprintf(server->clients[index]->cfd, code_230);
        return 0;
    }
    return 0;
}
