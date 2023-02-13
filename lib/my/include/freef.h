/*
** EPITECH PROJECT, 2022
** freef
** File description:
** FreeKOSOVO
*/

#ifndef MY_FREEF_H_
    #define MY_FREEF_H_

    #include <stdarg.h>

    #define NBR_FLAGS 2

/**
 * @brief Struct for handling of flags.
 * @param flag flag to handle.
 * @param ptr_function pointer of function to handle the flag.
 */
struct flag {
    char flag;
    void (*ptr_function) (va_list);
};

/**
 * @brief Free a string array.
 * @param array The string array to free.
 */
void my_free_array(char **array);


/**
 * @brief Free va args with the formated string.
 * @param format The string to format.
 * @param %s Free the string.
 * @param %t Free the string array.
 */
void my_freef(const char *format, ...);

void free_string(va_list arg);
void free_array(va_list arg);

#endif/* !MY_FREEF_H_ */
