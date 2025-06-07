/* ft_strcmp.c – self-implemented strcmp.
*
 *  Returns <0, 0, >0 exactly like the standard strcmp.
 *  No locale or multibyte handling – byte-wise compare.
 */
#include "libft/libft.h"

int ft_strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        if (*s1 != *s2)
            return (unsigned char)*s1 - (unsigned char)*s2;
        ++s1;
        ++s2;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}