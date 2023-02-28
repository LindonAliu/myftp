/*
** EPITECH PROJECT, 2022
** my_write_in_file
** File description:
** Write the text in a file.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

size_t my_strlen(const char *str);

int my_write_in_file(const char *filepath, const char *text)
{
    int fd = open(filepath, O_CREAT | O_WRONLY | O_TRUNC, 00666);

    if (fd == -1)
        return (1);
    write(fd, text, my_strlen(text));
    close(fd);
    return (0);
}
