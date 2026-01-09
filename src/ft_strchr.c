// ft_strchr.c
#include "libft/libft.h"

char *ft_strchr(const char *s, int c) {
    while (*s) {
        if (*s == (char) c)
            return (char *) s;
        s++;
    }
    // If c is '\0', return pointer to null terminator
    return (c == 0) ? (char *) s : NULL;
}
