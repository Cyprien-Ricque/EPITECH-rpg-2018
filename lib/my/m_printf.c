/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static const char flag_base[7] = "dcsSiI";
static const char flag_ebase[12] = "-0123456789%";

char *(*function_base[6])(va_list ap, char *str, char *buf) =
{
    m_int, m_char, m_string, m_array, m_iarray, m_maj_iarray
};

char *redirection(char *str, va_list *ap, char *buf, int *e)
{
    int a;

    for (int i = 0; str[i]; ++i) {
        for (a = 0; flag_base[a] && str[i] != flag_base[a]; ++a);
        if (flag_base[a]) {
            *e += i;
            return (function_base[a](*ap, str, buf));
        }
        for (a = 0; flag_ebase[a] && str[i] != flag_ebase[a]; ++a);
        if (!flag_ebase[a])
            return (m_scat(buf, "%", m_slen(buf), 1));
    }
    return (buf);
}

char *m_printf(int fd, char *str, ...)
{
    va_list ap;
    char *buf = "\0";

    va_start(ap, str);
    for (int i = 0; str[i]; ++i)
        buf = str[i] == '%' ? redirection(&(str[i]), &ap, buf, &i) :
            m_scat(buf, &str[i], m_slen(buf), 1);
    va_end(ap);
    if (fd >= 0)
        m_puts(buf, fd);
    return (buf);
}