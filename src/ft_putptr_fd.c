#include <stddef.h>

void ft_putstr_fd(const char *s, int fd);
void ft_puthex_fd(size_t n, int uppercase, int fd);

void ft_putptr_fd(const void *p, int fd)
{
    ft_putstr_fd("0x", fd);
    ft_puthex_fd((size_t)p, 1, fd);
}

