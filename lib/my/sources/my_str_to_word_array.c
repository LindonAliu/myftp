/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** Create a string array from a string.
*/

#include "str.h"
#include "char.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

static int count_word(const char *str)
{
    int counter = 0;
    int size = my_strlen(str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\\')
            i++;
        if ((my_char_isalphanum(str[i]) == 1) && str[i - 1] == '\\' && i > 0)
            i++;
        if (size < i)
            return (counter);
        if ((my_char_isprintable(str[i]) == 1) &&
        (my_char_isprintable(str[i + 1]) == 0)) {
            counter++;
        }
    }
    return (counter);
}

static char **mem_alloc_2d_array(int nb_rows)
{
    char **arr = malloc(sizeof(char *) * (nb_rows + 1));
    arr[nb_rows] = NULL;
    return arr;
}

static int size_word(const char *str, int i)
{
    int k = 0;

    while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' &&
    str[i] != '\0') {
        i++;
        k++;
    }
    return (k);
}

char **my_str_to_word_array(const char *str)
{
    int nb_word = count_word(str);
    char **tab = mem_alloc_2d_array(nb_word);
    int size = 0;
    int i = 0;

    for (int j = 0; j < nb_word; j++) {
        for (; str[i] == ' ' || str[i] == '\n' || str[i] == '\t'; i++);
        size = size_word(str, i);
        tab[j] = malloc(sizeof(char) * (size + 1));
        if (tab[j] == NULL)
            return NULL;
        my_strncpy(tab[j], &str[i], size);
        i += size;
    }
    return (tab);
}
