/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** Copies the string src to the string dest.
*/

char *my_strcpy(char *dest, const char *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
