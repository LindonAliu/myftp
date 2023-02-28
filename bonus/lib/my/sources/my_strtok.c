/*
** EPITECH PROJECT, 2022
** my_strtok
** File description:
** FreeKOSOVO
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int check_letter(char separator, char c, int i, int check)
{
    if (check != 0)
        return (0);
    if (separator == c)
        return (i);
    return (0);
}

int get_size_str(const char *str, const char *delim)
{
    int result = 0;

    for (int i = 0; delim[i] != '\0'; i++) {
        for (int j = 0; str[j] != '\0'; j++) {
            result += check_letter(delim[i], str[j], j, result);
        }
    }
    return (result);
}

char *my_strtok(char *str, const char *delim)
{
    char *result = NULL;
    int len = 0;

    len = get_size_str(str, delim);
    if (len == 0)
        return (NULL);
    result = malloc(sizeof(char) * (len + 1));
    if (result == NULL)
        return (NULL);
    for (int i = 0; i != len; i++) {
        result[i] = str[i];
    }
    return (result);
}
