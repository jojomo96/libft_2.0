#include "libft/libft.h"

/*
** Simple ASCII-to-double conversion.
**
** Supported:
** - leading whitespace
** - optional sign
** - integer part
** - optional fractional part ('.' followed by digits)
**
** Not supported (intentionally minimal):
** - exponent notation (e/E)
** - nan/inf
**
** This matches typical libft expectations for small projects.
*/
double ft_atof(const char *str) {
    double result;
    double frac;
    double div;
    int sign;

    result = 0.0;
    frac = 0.0;
    div = 1.0;
    sign = 1;
    if (!str)
        return (0.0);
    while (ft_isspace((unsigned char) *str))
        str++;
    if (*str == '-' || *str == '+') {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        result = result * 10.0 + (double) (*str - '0');
        str++;
    }
    if (*str == '.') {
        str++;
        while (*str >= '0' && *str <= '9') {
            frac = frac * 10.0 + (double) (*str - '0');
            div *= 10.0;
            str++;
        }
        result += frac / div;
    }
    return (result * (double) sign);
}
