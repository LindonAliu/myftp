/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** Copies the first n bytes of src to dest.
*/

#include <stddef.h>

char *my_strncpy(char *dest, const char *src, size_t n)
{
    size_t i;

    for (i = 0; src[i] != '\0' && i < n; i += 1)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
