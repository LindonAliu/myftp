/*
** EPITECH PROJECT, 2023
** quit
** File description:
** FreeKOSOVO
*/

#include "client.h"
#include "all_lib.h"

int quit(UNUSED const char **cmd, struct client **client,
    UNUSED int index)
{
    destroy_client(client[index]);
    client[index] = NULL;
    return 0;
}
