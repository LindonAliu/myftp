/*
** EPITECH PROJECT, 2023
** error_handling
** File description:
** FreeKOSOVO
*/

#include "all_lib.h"
#include <stdlib.h>
#include <stdio.h>

void display_help(char const *bin_name)
{
    printf("USAGE:\t%s port path\n", bin_name);
    printf("\tport is the port number on which the ");
    printf("server socket listens\n");
    printf("\tpath is the path to the ");
    printf("home directory for the Anonymous user\n");
    exit(0);
}

int error_handling(int ac, char const *av[])
{
    if ((!my_strcmp(av[1], "--help") || !my_strcmp(av[1], "-h")) && ac == 2)
        display_help(av[0]);
    if (ac != 3) {
        perror("Error: invalid arguments");
        return -1;
    }
    return 0;
}
