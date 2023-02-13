/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** Concatenate two strings.
*/

#include <stddef.h>

size_t my_strlen(const char *str);

char *my_strncat(char *dest, const char *src, size_t nb)
{
    size_t len_dest = my_strlen(dest);
    size_t i = 0;

    for (i = 0; src[i] != '\0' && i < nb; i++)
        dest[len_dest + i] = src[i];
    dest[len_dest + i] = '\0';
    return (dest);
}
