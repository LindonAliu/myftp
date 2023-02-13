/*
** EPITECH PROJECT, 2021
** cpool day04 task03
** File description:
** my_strlen.c
*/

#include <stddef.h>

size_t my_strlen(char const *str)
{
    size_t counter;

    for (counter = 0; str[counter] != '\0'; counter++);
    return (counter);
}
