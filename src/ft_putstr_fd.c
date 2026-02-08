#include <unistd.h>

void ft_putstr_fd(const char *s, int fd)
{
    if (!s)
        return;
    while (*s)
        (void)write(fd, s++, 1);
}

