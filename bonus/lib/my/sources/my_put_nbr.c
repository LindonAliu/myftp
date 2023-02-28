/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** Write the number in stdout.
*/

void my_putchar(char c);

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb <= 9)
        my_putchar(nb + '0');
    else {
        my_put_nbr(nb / 10);
        nb = nb % 10;
        my_putchar(nb + '0');
    }
}
