/*
** EPITECH PROJECT, 2022
** my_show_word_array
** File description:
** Write the string array in stdout.
*/

#include <stddef.h>

void my_putstr(const char *src);
void my_putchar(char c);

void my_show_word_array(const char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(array[i]);
        my_putchar('\n');
    }
}
