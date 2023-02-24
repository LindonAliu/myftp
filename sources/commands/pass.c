/*
** EPITECH PROJECT, 2023
** pass
** File description:
** FreeKOSOVO
*/

#include "builtins_array.h"
#include "all_lib.h"
#include <string.h>

//open accounts.txt and get the password
static const char *get_password(char *username)
{
    if (my_strcmp(username, "Anonymous") == 0)
        return NULL;
    return NULL;
}

int pass(const char **cmd, struct server *server, int index)
{
    char const *correct_password =
        get_password(server->clients[index]->a.username);

    if (server->clients[index]->a.connected == 0) {
        dprintf(server->clients[index]->cfd, code_503);
        return 0;
    }
    if (cmd[1] == correct_password || strcmp(cmd[1], correct_password) == 0) {
        server->clients[index]->a.connected = 2;
        dprintf(server->clients[index]->cfd, code_230);
        return 0;
    }
    return 0;
}
