/*
** EPITECH PROJECT, 2022
** main
** File description:
** FreeKOSOVO
*/

#include "all_lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(UNUSED int argc, UNUSED const char *argv[], UNUSED const char *env[])
{
}

    // struct sockaddr_in server = {
    //     .sin_family = AF_INET,
    //     .sin_port = htons(atoi(argv[1])),
    //     .sin_addr.s_addr = INADDR_ANY
    // };
    // int socket_res = socket(AF_INET, SOCK_STREAM, 0);

    // if (socket_res == -1) {
    //     perror("socket");
    //     return 84;
    // }
    // if (bind(socket_res, (struct sockaddr *)&server, sizeof(server)) == -1) {
    //     perror("bind");
    //     return 84;
    // }
    // int listen_res = listen(socket_res, 5);
    // if (listen_res == -1) {
    //     perror("listen");
    //     return 84;
    // }
    // int client = accept(socket_res, NULL, NULL);
    // if (client == -1) {
    //     perror("accept");
    //     return 84;
    // }
    // int max_fd = MAX(socket_res, 0) + 1;
    // while (1) {
    //     char buffer[1024];
    //     int read_res = read(client, buffer, 1024);
    //     if (read_res == -1) {
    //         perror("read");
    //         return 84;
    //     }
    //     if (read_res == 0) {
    //         printf("Client disconnected\n");
    //         break;
    //     }
    //     write(1, buffer, read_res);
    //     if (read_res > 0)
    //         break;
    // }
    // close(socket_res);
    // close(client);
    // return 0;
