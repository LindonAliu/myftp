/*
** EPITECH PROJECT, 2022
** my_memcpy
** File description:
** Copy the nmemb elements of the array src to the array dest.
*/

#include <stddef.h>

void my_memcpy(void *dest, const void *src, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        ((char *)dest)[i] = ((char *)src)[i];
}
