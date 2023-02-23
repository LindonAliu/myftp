/*
** EPITECH PROJECT, 2023
** cdup
** File description:
** FreeKOSOVO
*/

#include "client.h"
#include "all_lib.h"

int cdup(UNUSED const char **cmd, UNUSED struct client **client,
    UNUSED int index)
{
    printf("%s\n", cmd[0]);
    return 0;
}
