#ifndef FT_LIBFT_H
#define FT_LIBFT_H

#include <stddef.h>

int ft_strcmp(const char *s1, const char *s2);
char *ft_strchr(const char *s, int c);
void *ft_memset(void *s, int c, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
int ft_atoi(const char *str);
long ft_strtol(const char *str, char **endptr, int base);




#endif //FT_LIBFT_H
