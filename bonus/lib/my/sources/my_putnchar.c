/*
** EPITECH PROJECT, 2022
** my_putnchar
** File description:
** Write n char c in stdout.
*/

void my_putchar(char c);

void my_putnchar(char c, int n)
{
    while (n--)
        my_putchar(c);
}
