#include "libft/libft.h"

/*
** Returns 1 if the string is a valid "simple" double representation.
**
** Accepted forms:
** - optional leading whitespace
** - optional sign (+/-)
** - digits with optional fractional part: "12", "12.", "12.34"
** - leading dot with digits: ".5"
** - optional trailing whitespace
**
** Not accepted (by design): exponent notation ("1e3"), NaN/Inf.
*/
int	ft_str_is_double(const char *s)
{
	int	seen_digit;
	int	seen_dot;

	if (!s)
		return (0);
	while (ft_isspace((unsigned char)*s))
		s++;
	if (*s == '-' || *s == '+')
		s++;
	seen_digit = 0;
	seen_dot = 0;
	while (*s)
	{
		if (ft_isdigit((unsigned char)*s))
			seen_digit = 1;
		else if (*s == '.' && !seen_dot)
			seen_dot = 1;
		else
			break ;
		s++;
	}
	while (ft_isspace((unsigned char)*s))
		s++;
	if (*s != '\0')
		return (0);
	return (seen_digit);
}

