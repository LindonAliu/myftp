/*
** EPITECH PROJECT, 2022
** my_char_isalphanum
** File description:
** Check if the given character is alphanumeric.
*/

int my_char_isnum(char c);
int my_char_isalpha(char c);

int my_char_isalphanum(char c)
{
    return (my_char_isalpha(c) || my_char_isnum(c));
}
