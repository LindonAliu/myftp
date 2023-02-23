/*
** EPITECH PROJECT, 2023
** buffer_handling
** File description:
** FreeKOSOVO
*/

// #include "my_ftp.h"
// #include "all_lib.h"
// #include <stdio.h>
// #include "builtins_array.h"

// int manage_commands(char *command, int cfd, struct list_fd **list)
// {
//     int connected = 0;
//     char **cmd = my_stwa_separator(command, " ");
//     int ret = -1;

//     for (int i = 0; i < 4; i++) {
//         if (builtins_array[i](cmd, cfd, &connected, list) == 0) {
//             ret = 0;
//             break;
//         }
//     }
//     my_free_array(cmd);
//     return ret;
// }

// int buffer_handling(char buffer[4096], int cfd, struct list_fd **list)
// {
//     char **cmd = my_stwa_separator(buffer, "\r\n");

//     if (cmd == NULL)
//         return -1;
//     for (int i = 0; cmd[i] != NULL; i++) {
//         if (manage_commands(cmd[i], cfd, list) == -1)
//             write(cfd, "500 Syntax error, command unrecognized.\r\n", 41);
//     }
//     my_free_array(cmd);
//     return 0;
// }
