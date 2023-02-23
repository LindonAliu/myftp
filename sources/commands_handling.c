/*
** EPITECH PROJECT, 2023
** commands
** File description:
** FreeKOSOVO
*/

#include "all_lib.h"
#include "builtins_array.h"
#include <string.h>

#include <stdio.h> // printf

int command_handling(const char **cmd, struct client **clients, int index)
{
    if (cmd == NULL || clients == NULL || clients[index] == NULL)
        return -1;
    for (int i = 0; i < BUILTINS_ARRAY_SIZE; i++) {
        if (strcmp(cmd[0], builtins_array[i].name) == 0) {
            return builtins_array[i].func(cmd, clients, index);
        }
    }
    return -1;
}
