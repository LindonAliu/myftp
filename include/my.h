/*
** EPITECH PROJECT, 2021
** my
** File description:
** #FreeKOSOVO
*/

#ifndef MY_H_
    #define MY_H_

    #define ATOD(x) (x - '0')
    #define DTOA(x) (x + '0')
    #define UNUSED __attribute__((unused))

/**
 * @brief Swap two int.
 * @param a The first int.
 * @param b The second int.
 */
void my_swap(int *a, int *b);

/**
 * @brief Calculate the length of a strings.
 * @param n The number of arguments.
 * @param str The string to test.
 * @return Return the number of bytes in the string pointed to by str.
 */
int sum_strings_length(int n, ...);

/**
 * @brief Adding all the numbers
 * @param n The number of arguments.
 * @param ... 
 * @return Return the sum of all the numbers.
 */
int sum_numbers(int n, ...);


#endif/* MY_H_ */
