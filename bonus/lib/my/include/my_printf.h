/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** FreeKOSOVO
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include <stdarg.h>
    #include <stddef.h>
    #define NBR_FLAGS_PRINTF 6

/**
 * @brief Struct for handling of flags.
 * @param flag flag to handle.
 * @param ptr_function pointer of function to handle the flag.
 */
struct flag_printf {
    char flag;
    void (*ptr_function) (va_list);
};


/**
 * @brief Write the char in stdout.
 * @param c The char to write.
 */
void my_putchar(char c);


/**
 * @brief Write n char c in stdout.
 * @param c The char to write.
 * @param n The number of char to write.
 */
void my_putnchar(char c, int n);


/**
 * @brief Write the string in stdout.
 * @param str The string to write.
 */
void my_putstr(const char *str);


/**
 * @brief Write the string in error output.
 * @param str The string to write.
 */
void my_puterr(const char *str);


/**
 * @brief Write the char in error output.
 * @param c The char to write.
 */
void my_putchar_error(char c);


/**
 * @brief Write the number in stdout.
 * @param nb The number to write.
 */
void my_put_nbr(int nb);


/**
 * @brief Write the string array in stdout.
 * @param array The string array to write.
 */
void my_show_word_array(const char **array);


/**
 * @brief Write the text in a file.
 * @param filepath The path to the file.
 * @param text The text to write.
 * @return Return 0 if the text was written, 1 otherwise.
 */
int my_write_in_file(const char *filepath, const char *text);


void my_printf(const char *format, ...);


#endif/* !MY_PRINTF_H_ */
