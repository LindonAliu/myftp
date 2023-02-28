/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** Swap two int.
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
