/*
** EPITECH PROJECT, 2022
** my_get_first_line_file
** File description:
** Get the first line of a file.
*/

#include <stdlib.h>

char *my_file_in_str(const char *filepath);
char *my_strncpy(char *dest, const char *src, size_t n);

char *my_get_first_line_file(const char *filepath)
{
    char *buffer = my_file_in_str(filepath);
    char *result;
    int i;

    if (buffer == NULL)
        return buffer;
    for (i = 0; buffer[i] != '\n'; ++i);
    result = malloc(sizeof(char) * (i + 1));
    if (result == NULL) {
        free(buffer);
        return NULL;
    }
    my_strncpy(result, buffer, i);
    result[i] = '\0';
    free(buffer);
    return result;
}
