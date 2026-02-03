#include "libft/libft.h"
#include <limits.h>

/*
 * ft_atoll_checked
 * Parse a base-10 signed integer from `str` into `out`.
 * Returns 1 on success, 0 on error (invalid/overflow/empty/extra chars).
 */
int ft_atoll_checked(const char *str, long long *out) {
    const char *s;
    int sign;
    unsigned long long acc;

    if (!str || !out)
        return 0;

    s = str;
    while (*s == ' ' || (*s >= 9 && *s <= 13))
        ++s;

    sign = 1;
    if (*s == '+' || *s == '-') {
        if (*s == '-')
            sign = -1;
        ++s;
    }

    if (*s < '0' || *s > '9')
        return 0;

    acc = 0ULL;
    while (*s >= '0' && *s <= '9') {
        const unsigned digit = (unsigned)(*s - '0');
        const unsigned long long limit = (sign == 1)
            ? (unsigned long long)LLONG_MAX
            : (unsigned long long)LLONG_MAX + 1ULL; /* abs(LLONG_MIN) */

        if (acc > (limit - digit) / 10ULL)
            return 0; /* overflow */

        acc = acc * 10ULL + digit;
        ++s;
    }

    /* reject trailing junk */
    if (*s != '\0')
        return 0;

    if (sign == 1)
        *out = (long long)acc;
    else {
        if (acc == (unsigned long long)LLONG_MAX + 1ULL)
            *out = LLONG_MIN;
        else
            *out = -(long long)acc;
    }

    return 1;
}

