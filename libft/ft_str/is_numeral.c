#include "libft.h"

bool	is_numeral(char *str)
{
	if (!str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}
