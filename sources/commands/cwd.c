/*
** EPITECH PROJECT, 2023
** cwd
** File description:
** FreeKOSOVO
*/

#include "client.h"
#include "all_lib.h"

int cwd(UNUSED const char **cmd, UNUSED struct client **client,
    UNUSED int index)
{
    printf("%s\n", cmd[0]);
    return 0;
}