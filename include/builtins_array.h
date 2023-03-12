/*
** EPITECH PROJECT, 2023
** builtins_array
** File description:
** FreeKOSOVO
*/

#ifndef BUILTINS_ARRAY_H_
    #define BUILTINS_ARRAY_H_

    #define UNUSED __attribute__((unused))
    #define _GNU_SOURCE
    #include "server.h"
    #include <stdio.h>

typedef int builtin_func_t (const char **cmd,
    struct server *server, int index);

struct builtin {
    char *name;
    int (*func)(const char **cmd, struct server *server, int index);
};

builtin_func_t user;
builtin_func_t pass;
builtin_func_t cwd;
builtin_func_t cdup;
builtin_func_t quit;
builtin_func_t dele;
builtin_func_t pwd;
builtin_func_t pasv;
builtin_func_t port;
builtin_func_t help;
builtin_func_t noop;
builtin_func_t retr;
builtin_func_t stor;
builtin_func_t list;

static const int BUILTINS_ARRAY_SIZE = 14;

//success messages
UNUSED static const char *code_120 =
    "120 Service ready in nnn minutes.\r\n";
UNUSED static const char *code_125 =
    "125 Data connection already open; transfer starting.\r\n";
UNUSED static const char *code_150 =
    "150 File status okay; about to open data connection.\r\n";
UNUSED static const char *code_200 =
    "200 Command okay.\r\n";
UNUSED static const char *code_214 =
    "214 Help message.\r\n";
UNUSED static const char *code_220 =
    "220 Service ready for new user.\r\n";
UNUSED static const char *code_221 =
    "221 Service closing control connection.\r\n";
UNUSED static const char *code_226 =
    "226 Closing data connection.\r\n";
UNUSED static const char *code_227 =
    "227 Entering Passive Mode (127,0,0,1,%d,%d).\r\n";
UNUSED static const char *code_230 =
    "230 User logged in, proceed.\r\n";
UNUSED static const char *code_250 =
    "250 Requested file action okay, completed.\r\n";
UNUSED static const char *code_257 =
    "257 \"%s\" created.\r\n";
UNUSED static const char *code_331 =
    "331 User name okay, need password.\r\n";
UNUSED static const char *code_332 =
    "332 Need account for login.\r\n";

//error messages
UNUSED static const char *code_425 =
    "425 Can't open data connection.\r\n";
UNUSED static const char *code_426 =
    "426 Connection closed; transfer aborted.\r\n";
UNUSED static const char *code_450 =
    "450 Requested file action not taken.\r\n";
UNUSED static const char *code_451 =
    "451 Requested action aborted: local error in processing.\r\n";
UNUSED static const char *code_452 =
    "452 Requested action not taken.\r\n";
UNUSED static const char *code_500 =
    "500 Syntax error, command unrecognized.\r\n";
UNUSED static const char *code_501 =
    "501 Syntax error in parameters or arguments.\r\n";
UNUSED static const char *code_502 =
    "502 Command not implemented.\r\n";
UNUSED static const char *code_503 =
    "503 Bad sequence of commands.\r\n";
UNUSED static const char *code_504 =
    "504 Command not implemented for that parameter.\r\n";
UNUSED static const char *code_530 =
    "530 Not logged in.\r\n";
UNUSED static const char *code_532 =
    "532 Need account for storing files.\r\n";
UNUSED static const char *code_550 =
    "550 Requested action not taken.\r\n";
UNUSED static const char *code_551 =
    "551 Requested action aborted: page type unknown.\r\n";
UNUSED static const char *code_552 =
    "552 Requested file action aborted.\r\n";
UNUSED static const char *code_553 =
    "553 Requested action not taken.\r\n";

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
