#include <stddef.h>

void ft_putchar_fd(char c, int fd);

void ft_puthex_fd(size_t n, int uppercase, int fd)
{
    const char *base;

    base = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    if (n >= 16)
        ft_puthex_fd(n / 16, uppercase, fd);
    ft_putchar_fd(base[n % 16], fd);
}

