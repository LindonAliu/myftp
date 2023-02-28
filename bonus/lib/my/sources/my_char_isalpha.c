/*
** EPITECH PROJECT, 2021
** my_char_isalpha
** File description:
** Check if the given character is alphabetical.
*/

int my_char_isalpha(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
