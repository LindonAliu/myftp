/*
** EPITECH PROJECT, 2021
** my_str_isupper
** File description:
** Check if the string is uppercase.
*/

int my_str_isupper(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') && str[i] != ' ')
            return (0);
    }
    return (1);
}
