/*
** EPITECH PROJECT, 2022
** my_file_in_2d_char_array
** File description:
** Create a string array from a file.
*/

#include <stddef.h>
#include <stdlib.h>

char *my_file_in_str(const char *filepath);
char **my_str_to_word_array(const char *str);

char **my_file_in_array(const char *filepath)
{
    char *buffer = my_file_in_str(filepath);
    char **map;

    if (buffer == NULL)
        return (NULL);
    map = my_str_to_word_array(buffer);
    if (map == NULL) {
        free(buffer);
        return (NULL);
    }
    free(buffer);
    return (map);
}
