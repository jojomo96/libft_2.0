#include "libft/libft.h"

int	ft_str_is_number(const char *s)
{
	size_t	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit((unsigned char)s[i]))
			return (0);
		++i;
	}
	return (1);
}

