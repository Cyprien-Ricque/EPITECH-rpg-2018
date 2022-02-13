/*
** EPITECH PROJECT, 2018
** my_putss
** File description:
** my_putss
*/

#include "../../include/my.h"
#include <stdlib.h>
#include <unistd.h>

void m_putarray(char **array, char c, int fd)
{
    for (int i = 0; array[i]; ++i) {
        m_puts(array[i], fd);
        if (array[i + 1])
            write(fd, &c, 1);
    }
}
