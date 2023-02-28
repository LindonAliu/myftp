/*
** EPITECH PROJECT, 2022
** my_char_instr
** File description:
** Check if the given character is in the given string.
*/

int my_char_instr(const char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}
