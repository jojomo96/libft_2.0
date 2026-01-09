#include "libft/libft.h"

int ft_isspace(const int c) {
    return (c == ' ' || (c >= 9 && c <= 13));
}
