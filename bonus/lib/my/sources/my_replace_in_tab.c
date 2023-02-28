/*
** EPITECH PROJECT, 2022
** my_replace_in_tab
** File description:
** Remove a old char in the string array and add a new_element.
*/

#include <stddef.h>

static char **replace_char(char **tab, char old_element, char new_element,
    int i)
{
    for (int j = 0; tab[i][j] != '\0'; j++) {
        if (tab[i][j] == old_element)
            tab[i][j] = new_element;
    }
    return (tab);
}

void my_replace_in_tab(char **tab, char old_element, char new_element)
{
    for (int i = 0; tab[i] != NULL; i++)
        tab = replace_char(tab, old_element, new_element, i);
}
