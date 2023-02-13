/*
** EPITECH PROJECT, 2022
** str
** File description:
** FreeKOSOVO
*/

#ifndef MY_STR_H_
    #define MY_STR_H_

    #include <stddef.h>

/**
 * @brief Calculate the length of a string.
 * @param str The string to test.
 * @return Return the number of bytes in the string pointed to by str.
 */
size_t my_strlen(const char *str);


/**
 * @brief Converts the initial portion of the string pointed to by nptr to int.
 * @param nptr The string to test.
 * @return The converted value or 0 on error. 
 */
int my_getnbr(const char *nptr);


int my_showstr(const char *str);


/**
 * @brief Compare two strings.
 * @param str The first string to compare.
 * @param str The second string to compare.
 * @return Return an integer less than, equal to, or greater than zero if
 * s1 (or the first n bytes thereof) is found, respectively, to be  less
 * than, to match, or be greater than s2.
 */
int my_strcmp(const char *s1, const char *s2);


/**
 * @brief Compare two strings.
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The number of bytes to compare.
 * @return Retun an integer less than, equal to, or greater than zero if
 * s1 (or the first n bytes thereof) is found, respectively, to be  less
 * than, to match, or be greater than s2.
 */
int my_strncmp(const char *s1, const char *s2, size_t n);


/**
 * @brief Check if the string is a number.
 * @param str The string to test.
 * @return Return 1 if the string is a number, 0 otherwise.
 */
int my_str_isnum(const char *str);


/**
 * @brief Check if the string is lowercase.
 * @param str The string to test.
 * @return Return 1 if the string is lowercase, 0 otherwise.
 */
int my_str_islower(const char *str);


/**
 * @brief Check if the string is uppercase.
 * @param str The string to test.
 * @return Return 1 if the string is uppercase, 0 otherwise.
 */
int my_str_isupper(const char *str);


/**
 * @brief Check for an alphabetical string.
 * @param str Tht string to test.
 * @return Return 1 if the string is alphabetical, 0 otherwise.
 */
int my_str_isalpha(const char *str);


/**
 * @brief Check for a printable string.
 * @param str The string to test.
 * @return Return 1 if the string is printable, 0 otherwise.
 */
int my_str_isprintable(const char *str);


int my_showmem(const char *str, int size);


/**
 * @brief Reverse a string in place.
 * @param str String to reverse.
 * @return Return its argument.
 */
char *my_revstr(char *str);


/**
 * @brief Convert the given string to uppercase.
 * @param str String to convert in uppercase.
 * @return Return its argument.
 */
char *my_strupcase(char *str);


/**
 * @brief Convert the number into a string.
 * @param nb The number to convert.
 * @return Return a string containing the number or NULL if error.
 */
char *my_int_to_str(int nb);


/**
 * @brief Convert the given string to lowercase.
 * @param str String to convert in lowercase.
 * @return Return its argument.
 */
char *my_strlowcase(char *str);


/**
 * @brief Duplicate a string.
 * @param str String to duplicate.
 * @return Return a pointer to the duplicated string.
 */
char *my_strdup(const char *str);


/**
 * @brief Open a file and return a pointer to its content.
 * @param filepath Path to the file to open.
 * @return Return a pointer to the file content or NULL if error.
 */
char *my_file_in_str(const char *filepath);


/**
 * @brief Copies the string pointed to by src to the string pointed to by dest.
 * @param dest The destination string.
 * @param src The source string.
 * @return Return the destination string.
 */
char *my_strcpy(char *dest, const char *src);


/**
 * @brief Copies the first n bytes of the string pointed to by src to the
 * string pointed to by dest.
 * @param dest The destination string.
 * @param src The source string.
 * @param n The number of bytes to copy.
 * @return Return the destination string.
 */
char *my_strncpy(char *dest, const char *src, size_t n);


/**
 * @brief Concatenate two strings.
 * @param dest The destination string.
 * @param src The source string.
 * @return Return the destination string or NULL if error.
 */
char *my_strcat(char *dest, const char *src);


/**
 * @brief Get the first line of a file.
 * @param filepath Path to the file to open.
 * @return Return a pointer to the first line of the file or NULL if error.
 */
char *my_get_first_line_file(const char *filepath);


/**
 * @brief Locate a substring.
 * @param haystack The string to search in.
 * @param needle The string to search for.
 * @return Return a pointer to the first occurrence of the substring in the
 * haystack or NULL if error.
 */
char *my_strstr(const char *haystack, const char *needle);


/**
 * @brief Concatenate two strings
 * @param dest The destination string. 
 * @param src The source string. 
 * @param n The number of bytes to copy.
 * @return Return the destination string.
 */
char *my_strncat(char *dest, const char *src, size_t n);


#endif /* !MY_STR_H_ */
