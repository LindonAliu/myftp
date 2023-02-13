/*
** EPITECH PROJECT, 2021
** sum_strings_length
** File description:
** Return the number of bytes in all strings.
*/

#include <stdarg.h>
#include "str.h"

int sum_strings_length(int n, ...)
{
    va_list list;
    int result = 0;

    va_start(list, n);
    for (int i = 0; i < n; i++)
        result += my_strlen(va_arg(list, char *));
    va_end(list);
    return (result);
}
