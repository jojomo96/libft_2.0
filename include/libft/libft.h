#ifndef FT_LIBFT_H
#define FT_LIBFT_H

#include <stddef.h>

int ft_strcmp(const char *s1, const char *s2);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strchr(const char *s, int c);
void *ft_memset(void *s, int c, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
int ft_atoi(const char *str);
double ft_atof(const char *str);
long ft_strtol(const char *str, char **endptr, int base);
int ft_isdigit( int c);
int ft_isspace(int c);
int ft_strlen(const char *s);
int ft_str_is_number(const char *s);
int ft_str_is_double(const char *s);
double ft_sqrt(double x);




#endif //FT_LIBFT_H
