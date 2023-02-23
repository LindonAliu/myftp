/*
** EPITECH PROJECT, 2023
** list
** File description:
** FreeKOSOVO
*/

#include "client.h"
#include "all_lib.h"

int list(UNUSED const char **cmd, UNUSED struct client **client,
    UNUSED int index)
{
    printf("%s\n", cmd[0]);
    return 0;
}
