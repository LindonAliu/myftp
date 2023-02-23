/*
** EPITECH PROJECT, 2023
** builtins_array
** File description:
** FreeKOSOVO
*/

#ifndef BUILTINS_ARRAY_H_
    #define BUILTINS_ARRAY_H_

    #include "client.h"

struct builtin {
    char *name;
    int (*func)(const char **cmd, struct client **client, int index);
};

int user(const char **cmd, struct client **client, int index);
int pass(const char **cmd, struct client **client, int index);
int cwd(const char **cmd, struct client **client, int index);
int cdup(const char **cmd, struct client **client, int index);
int quit(const char **cmd, struct client **client, int index);
int dele(const char **cmd, struct client **client, int index);
int pwd(const char **cmd, struct client **client, int index);
int pasv(const char **cmd, struct client **client, int index);
int port(const char **cmd, struct client **client, int index);
int help(const char **cmd, struct client **client, int index);
int noop(const char **cmd, struct client **client, int index);
int retr(const char **cmd, struct client **client, int index);
int stor(const char **cmd, struct client **client, int index);
int list(const char **cmd, struct client **client, int index);

static const int BUILTINS_ARRAY_SIZE = 14;

static const struct builtin builtins_array[] = {
    {"USER", &user},
    {"PASS", &pass},
    {"CWD", &cwd},
    {"CDUP", &cdup},
    {"QUIT", &quit},
    {"DELE", &dele},
    {"PWD", &pwd},
    {"PASV", &pasv},
    {"PORT", &port},
    {"HELP", &help},
    {"NOOP", &noop},
    {"RETR", &retr},
    {"STOR", &stor},
    {"LIST", &list},
};

#endif /* !BUILTINS_ARRAY_H_ */
