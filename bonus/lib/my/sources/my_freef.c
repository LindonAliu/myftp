/*
** EPITECH PROJECT, 2022
** my_freef
** File description:
** Free va args with the formated string.
*/

#include "freef.h"

static int check_flag(char flag, va_list list,
    const struct flag f[])
{
    for (int i = 0; i < NBR_FLAGS; i++) {
        if (flag == f[i].flag) {
            f[i].ptr_function(list);
            return 1;
        }
    }
    return 0;
}

void my_freef(const char *format, ...)
{
    va_list list;
    const struct flag f[] = {
        {'s', &free_string},
        {'t', &free_array},
    };

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%')
            i += check_flag(format[i + 1], list, f);
    }
    va_end(list);
}
