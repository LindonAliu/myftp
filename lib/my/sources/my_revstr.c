/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** Reverse a string in place.
*/

#include <stddef.h>

size_t my_strlen(const char *str);

char *my_revstr(char *str)
{
    int i = my_strlen(str) - 1;
    char a;

    for (int j = 0; j < i; j++) {
        a = str[j];
        str[j] = str[i];
        str[i] = a;
        i--;
    }
    return (str);
}
