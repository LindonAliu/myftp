/*
** EPITECH PROJECT, 2021
** my_str_islower
** File description:
** Check if the string is lowercase.
*/

int my_str_islower(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'a' || str[i] > 'z') && str[i] != ' ')
            return (0);
    }
    return (1);
}
