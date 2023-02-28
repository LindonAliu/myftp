/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** FreeKOSOVO
*/

#include "my_printf.h"

void flag_s(va_list arg);
void flag_c(va_list arg);
void flag_number(va_list arg);
void flag_e(va_list arg);
void flag_t(va_list arg);

static int check_flag(char flag, va_list list, const struct flag_printf f[])
{
    for (int i = 0; i < NBR_FLAGS_PRINTF; i++) {
        if (flag == f[i].flag) {
            f[i].ptr_function(list);
            return 1;
        }
        if (flag == '%') {
            my_putchar('%');
            return 1;
        }
    }
    return 0;
}

void my_printf(const char *format, ...)
{
    va_list list;
    const struct flag_printf f[] = {
        {'s', &flag_s},
        {'c', &flag_c},
        {'i', &flag_number},
        {'d', &flag_number},
        {'e', &flag_e},
        {'t', &flag_t}
    };

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i += check_flag(format[i + 1], list, f);
        } else
            my_putchar(format[i]);
    }
    va_end(list);
}
