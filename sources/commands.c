/*
** EPITECH PROJECT, 2023
** commands
** File description:
** FreeKOSOVO
*/

// #include "my_ftp.h"
// #include "all_lib.h"
// #include "builtins_array.h"
// #include <string.h>
// #include "all_lib.h"

// int user(char **cmd, int cfd, int *connected, UNUSED struct list_fd **list)
// {
//     int size = 0;

//     for (; cmd[size] != NULL; size++)
//         ;
//     if (size != 2)
//         return -1;
//     if (strcmp(cmd[0], "USER") != 0)
//         return -1;
//     if (strcmp(cmd[1], "Anonymous") != 0)
//         return -1;
//     dprintf(cfd, "331 User name okay, need password.\n");
//     *connected = 1;
//     return 0;
// }

// int pass(char **cmd, int cfd, int *connected, UNUSED struct list_fd **list)
// {
//     int size = 0;
//     const char *correct_password = NULL;

//     if (*connected == 0)
//         return -1;
//     for (; cmd[size] != NULL; size++)
//         ;
//     if (size != 2)
//         return -1;
//     if (strcmp(cmd[0], "PASS") != 0)
//         return -1;
//     if (cmd[1] != correct_password)
//         return -1;
//     dprintf(cfd, "230 User logged in, proceed.\n");
//     *connected = 2;
//     return 0;
// }

// int quit(char **cmd, int cfd, int *connected, struct list_fd **list)
// {
//     int size = 0;

//     for (; cmd[size] != NULL; size++);
//     if (size != 1)
//         return -1;
//     if (strcmp(cmd[0], "QUIT") != 0)
//         return -1;
//     dprintf(cfd, "221 Service closing control connection.\n");
//     *connected = 0;
//     delete_fd_in_list(list, cfd);

//     struct list_fd *tmp = *list;

//     while (tmp != NULL) {
//         printf("(%d) -> ", tmp->fd);
//         tmp = tmp->next;
//     }
//     printf("null\n");
//     return 0;
// }

// int cwd(char **cmd, int cfd, int *connected, UNUSED struct list_fd **list)
// {
//     int size = 0;

//     if (*connected != 2)
//         return -1;
//     for (; cmd[size] != NULL; size++)
//         ;
//     if (size != 2)
//         return -1;
//     if (strcmp(cmd[0], "CWD") != 0)
//         return -1;
//     if (chdir(cmd[1]) == -1)
//         return -1;
//     dprintf(cfd, "250 Requested file action okay, completed.\n");
//     return 0;
// }
