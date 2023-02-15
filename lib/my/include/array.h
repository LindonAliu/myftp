/*
** EPITECH PROJECT, 2022
** array
** File description:
** FreeKOSOVO
*/

#ifndef MY_ARRAY_H_
    #define MY_ARRAY_H_

    #include <stddef.h>

/**
 * @brief Create a string array from a string.
 * @param str The string to split.
 * @return Return a string array.
 */
char **my_str_to_word_array(const char *str);


/**
 * @brief Create a string array from a file.
 * @param filepath The path to the file.
 * @return Return a string array or NULL if error.
 */
char **my_file_in_array(const char *filepath);


/**
 * @brief Create a string array from a string.
 * @param str The string to split.
 * @param separator The string with the separators.
 * @return Return a string array or NULL if error.
 */
char **my_stwa_separator(const char *str, const char *separator);


/**
 * @brief Concate a string in all the string of the array.
 * @param arr The string array.
 * @param str The string to concate.
 */
void my_strcat_in_array(char **arr, const char *str);


/**
 * @brief Duplicate a string array.
 * @param array The string array to duplicate.
 * @return Return a pointer to the duplicated string array.
 */
char **my_arrdup(const char **array);


/**
 * @brief Remove a old char in the string array and add a new_element.
 *
 * @param tab The string array.
 * @param old_element The old element to remove.
 * @param new_element The new element to add.
 * @return Return 0 if the element was removed and remplaced, 0 otherwise.
 */
int my_replace_in_tab(char **tab, char old_element, char new_element);


/**
 * @brief Get the line number of to the first occurrence of the string to find.
 *
 * @param array The string array.
 * @param to_find The string to find.
 * @return Return the line number or -1 if the string was not found.
 */
int my_get_line_tab(const char **array, const char *to_find);


/**
 * @brief Get the length of a string array.
 * @param array The string array.
 * @return Return the length of the string array.
 */
size_t my_len_array(const char **array);


/**
 * @brief Sort a int array.
 * @param array The int array to sort.
 * @param size The size of the array.
 */
void my_sort_int_array(int *array, int size);

#endif/* !MY_ARRAY_H_ */
