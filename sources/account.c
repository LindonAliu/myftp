/*
** EPITECH PROJECT, 2023
** account
** File description:
** FreeKOSOVO
*/

#include "client.h"
#include <stdlib.h>

void create_account(struct account *account, char *username,
    char *password, char *current_dir)
{
    account->username = username;
    account->password = password;
    account->current_dir = current_dir;
    account->connected = 0;
}

void destroy_account(struct account *account)
{
    if (account->username)
        free(account->username);
    if (account->password)
        free(account->password);
    if (account->current_dir)
        free(account->current_dir);
    account->connected = 0;
}

void print_account(struct account *account)
{
    printf("username: %s password: %s current_dir: %s connected: %d\n",
        account->username, account->password,
        account->current_dir, account->connected);
}
