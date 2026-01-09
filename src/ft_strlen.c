#include "libft/libft.h"

int ft_strlen(const char *s) {
    const char *p = s;

    while (*p)
        p++;

    return (int) (p - s);
}
