/*
** EPITECH PROJECT, 2022
** my_free_array
** File description:
** Free a string array.
*/

#include <stddef.h>
#include <stdlib.h>

void my_free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
