/*
** EPITECH PROJECT, 2022
** flags_printf
** File description:
** flags of printf
*/

#include "my_printf.h"

void flag_s(va_list arg)
{
    my_putstr(va_arg(arg, char *));
}

void flag_c(va_list arg)
{
    my_putchar(va_arg(arg, int));
}

void flag_number(va_list arg)
{
    my_put_nbr(va_arg(arg, int));
}

void flag_e(va_list arg)
{
    my_puterr(va_arg(arg, char *));
}

void flag_t(va_list arg)
{
    my_show_word_array((const char **)va_arg(arg, char **));
}
