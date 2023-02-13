/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** The converted value or 0 on error. 
*/

int my_getnbr(const char *str)
{
    int result = 0;
    int a = 0;
    int b = 1;

    while (str[a] == '+' || str[a] == '-') {
        if (str[a] == '-')
            b *= -1;
        a++;
    }
    while (str[a] >= '0' && str[a] <= '9') {
        result *= 10;
        result += str[a] - '0';
        a++;
    }
    return (result * b);
}
