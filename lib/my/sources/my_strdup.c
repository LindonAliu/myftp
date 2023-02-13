/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** Duplicate a string.
*/

#include <stdlib.h>

size_t my_strlen(const char *str);
char *my_strcpy(char *dest, const char *src);

char *my_strdup(const char *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (!str)
        return str;
    str = my_strcpy(str, src);
    return str;
}
