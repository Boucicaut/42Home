#include "libft.h"

int	strmaxint(char *str)
{
	int	i;

	i = 0;
	if ((str[0] && str[0] >= '2' && str[0] <= '9') &&
			(str[1] && str[1] >= '1' && str[1] <= '9') &&
			(str[2] && str[2] >= '4' && str[2] <= '9') &&
			(str[3] && str[3] >= '7' && str[3] <= '9') &&
			(str[4] && str[4] >= '4' && str[4] <= '9') &&
			(str[5] && str[5] >= '8' && str[5] <= '9') &&
			(str[6] && str[6] >= '3' && str[6] <= '9') &&
			(str[7] && str[7] >= '6' && str[7] <= '9') &&
			(str[8] && str[8] >= '4' && str[8] <= '9') &&
			(str[9] && str[9] >= '8' && str[9] <= '9'))
		return (1);
	return (0);
}
