/*
** EPITECH PROJECT, 2022
** char
** File description:
** FreeKOSOVO
*/
#ifndef MY_CHAR_H_
    #define MY_CHAR_H_


/**
 * \brief Check if the given character is alphanumeric.
 * \param c The character to test.
 * \return Return 1 if the character is a digit or a letter, 0 otherwise.
 */
int my_char_isalphanum(char c);


/**
 * \brief Check if the given character is in the given string.
 * \param str The string to test.
 * \param c The character to test.
 * \return Return 1 if the character is in the string, 0 otherwise.
 */
int my_char_instr(const char *str, char c);


/**
 * @brief Check if the given character is alphabetical.
 * @param c The character to test.
 * @return Return 1 if the character is a letter, 0 otherwise.
 */
int my_char_isalpha(char c);


/**
 * @brief Check if the given character is printable.
 * @param c The character to test.
 * @return Return 1 if the character is printable, 0 otherwise.
 */
int my_char_isprintable(char c);


/**
 * @brief Check if the given character is lowercase.
 * @param c The character to test.
 * @return Return 1 if the character is lowercase, 0 otherwise.
 */
int my_char_islower(char c);


/**
 * @brief Check if the given character is uppercase.
 * @param c The character to test.
 * @return Return 1 if the character is uppercase, 0 otherwise.
 */
int my_char_isupper(char c);


/**
 * @brief Check if the given character is a digit.
 * @param c The character to test.
 * @return Return 1 if the character is a digit, 0 otherwise.
 */
int my_char_isnum(char c);


#endif/* !MY_CHAR_H_ */
