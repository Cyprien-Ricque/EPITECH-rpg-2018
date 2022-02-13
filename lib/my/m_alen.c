/*
** EPITECH PROJECT, 2018
** m_slen
** File description:
** m_slen
*/

#include <unistd.h>

int m_alen(void **a)
{
    int count = 0;

    if (!a)
        return (-1);
    while (a[count])
        ++count;
    return (count);
}