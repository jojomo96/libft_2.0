#include "libft/libft.h"
#include <limits.h>

/*
 * ft_strtol – converts a string to long
 *   - supports bases from 2 to 36
 *   - stops on invalid char
 *   - optional endptr receives the stopping point
 *   - handles "0x" or "0" prefix for base 0
 */
long ft_strtol(const char *str, char **endptr, int base)
{
    const char *s = str;
    long result = 0;
    int sign = 1;

    // 1. Skip leading whitespace
    while (*s == ' ' || (*s >= 9 && *s <= 13))
        ++s;

    // 2. Optional sign
    if (*s == '+' || *s == '-') {
        if (*s == '-')
            sign = -1;
        ++s;
    }

    // 3. Autodetect base (if base == 0)
    if (base == 0) {
        if (*s == '0') {
            if (s[1] == 'x' || s[1] == 'X') {
                base = 16;
                s += 2;
            } else {
                base = 8;
                ++s;
            }
        } else {
            base = 10;
        }
    } else if (base == 16 && *s == '0' && (s[1] == 'x' || s[1] == 'X')) {
        s += 2;
    }

    // 4. Convert digits
    const char *start = s;
    while (*s) {
        int digit;

        if (*s >= '0' && *s <= '9')
            digit = *s - '0';
        else if (*s >= 'a' && *s <= 'z')
            digit = *s - 'a' + 10;
        else if (*s >= 'A' && *s <= 'Z')
            digit = *s - 'A' + 10;
        else
            break;

        if (digit >= base)
            break;

        result = result * base + digit;
        ++s;
    }

    if (s == start && endptr)
        *endptr = (char *)str;  // No digits were read
    else if (endptr)
        *endptr = (char *)s;

    return result * sign;
}
