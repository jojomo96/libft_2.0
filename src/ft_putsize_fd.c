#include <stddef.h>

void ft_putchar_fd(char c, int fd);

void ft_putsize_fd(size_t n, int fd)
{
    if (n >= 10)
        ft_putsize_fd(n / 10, fd);
    ft_putchar_fd((char)('0' + (n % 10)), fd);
}

