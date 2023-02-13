/*
** EPITECH PROJECT, 2021
** my_str_isalpha
** File description:
** Check for an alphabetical string.
*/

int my_str_isalpha(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] > 'z' || str[i] < 'a'))
            return (0);
    }
    return (1);
}
