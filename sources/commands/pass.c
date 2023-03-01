/*
** EPITECH PROJECT, 2023
** pass
** File description:
** FreeKOSOVO
*/

#include "builtins_array.h"
#include "all_lib.h"
#include <string.h>
#include "my_ftp.h"
#include <stdlib.h>

static struct account get_account(char *username)
{
    struct account a = {NULL, NULL, 0};

    if (username == NULL)
        return a;
    if (strcmp(username, "Anonymous") == 0) {
        a.username = strdup("Anonymous");
        a.password = strdup("");
        a.connected = 2;
    }
    return a;
}

static int error_handling_pass(const char **cmd,
    struct server *server, int index)
{
    if (my_len_array(cmd) > 2) {
        dprintf(server->clients[index]->cfd, code_501);
        return 1;
    }
    if (server->clients[index]->a.connected == 0 ||
        server->clients[index]->a.connected == 2) {
        dprintf(server->clients[index]->cfd, code_503);
        return 1;
    }
    return 0;
}

int pass(const char **cmd, struct server *server, int index)
{
    struct account account;
    int diff = 0;

    if (error_handling_pass(cmd, server, index))
        return 0;
    account = get_account(server->clients[index]->a.username);
    diff = strcmp(cmd[1] == NULL ? "" : cmd[1],
        account.password == NULL ? "" : account.password);
    if (account.username == NULL || diff != 0) {
        destroy_account(&account);
        dprintf(server->clients[index]->cfd, code_530);
        return 0;
    }
    server->clients[index]->a.connected = 2;
    dprintf(server->clients[index]->cfd, code_230);
    destroy_account(&account);
    return 0;
}
