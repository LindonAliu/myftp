/*
** EPITECH PROJECT, 2022
** flags_freef
** File description:
** flags_freef
*/

#include <stdarg.h>
#include <stdlib.h>

void my_free_array(char **array);

void free_string(va_list arg)
{
    free((char *)va_arg(arg, char *));
}

void free_array(va_list arg)
{
    my_free_array((char **)va_arg(arg, char **));
}
