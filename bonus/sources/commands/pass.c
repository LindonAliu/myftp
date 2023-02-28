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
    char *file = my_file_in_str(ACCOUNT_FILE);
    char **accounts = my_stwa_separator(file, "\n");
    char **account = NULL;
    struct account a = {NULL, NULL, 0};

    free(file);
    for (int i = 0; accounts[i] != NULL; i++) {
        account = my_stwa_separator(accounts[i], ":");
        if (strcmp(account[0], username) == 0) {
            create_account(&a,
                account[0] == NULL ? NULL : strdup(account[0]),
                account[1] == NULL ? NULL : strdup(account[1]));
            my_free_array(account);
            break;
        }
        my_free_array(account);
    }
    my_free_array(accounts);
    return a;
}

static int error_handling_pass(const char **cmd, struct server *server, int index)
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
