/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** Write the string in stdout.
*/

#include <unistd.h>

int my_strlen(const char *str);

void my_putstr(const char *str)
{
    write(1, str, my_strlen(str));
}
