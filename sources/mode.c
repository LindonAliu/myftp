/*
** EPITECH PROJECT, 2023
** mode
** File description:
** FreeKOSOVO
*/

#include "client.h"
#include <unistd.h>

void destroy_mode(struct mode *mode)
{
    if (!mode)
        return;
    if (mode->type == NONE)
        return;
    close(mode->sfd);
    mode->type = NONE;
}
