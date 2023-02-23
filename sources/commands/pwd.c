/*
** EPITECH PROJECT, 2023
** pwd
** File description:
** FreeKOSOVO
*/

#include "client.h"
#include "all_lib.h"

int pwd(UNUSED const char **cmd, UNUSED struct client **client,
    UNUSED int index)
{
    printf("%s\n", cmd[0]);
    return 0;
}
