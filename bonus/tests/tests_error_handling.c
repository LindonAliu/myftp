/*
** EPITECH PROJECT, 2023
** tests_error_handling
** File description:
** FreeKOSOVO
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_ftp.h"
#include <unistd.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(function, test_output, .init = redirect_all_std)
{
}

Test(error_handling, test_error_handling_with_correct_params)
{
}
