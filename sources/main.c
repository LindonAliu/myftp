/*
** EPITECH PROJECT, 2022
** main
** File description:
** FreeKOSOVO
*/

#include "all_lib.h"
#include "my_ftp.h"

int main( int argc, char const *argv[])
{
    if (error_handling(argc, argv) < 0)
        return 84;
    return my_ftp(argv[1], argv[2]) == -1 ? 84 : 0;
}
