/*
** EPITECH PROJECT, 2022
** my_int_to_char
** File description:
** Convert the number into a string.
*/

#include <stdlib.h>

char *my_int_to_str(int nb)
{
    int len = 0;
    char *str;
    int tmp = nb;

    while (tmp > 0) {
        tmp /= 10;
        len++;
    }
    str = malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);
    str[len] = '\0';
    while (len--) {
        str[len] = nb % 10 + '0';
        nb /= 10;
    }
    return (str);
}
