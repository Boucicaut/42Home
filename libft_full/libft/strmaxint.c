#include "libft.h"

int	strmaxint(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 10)
		return (1);
	if ((str[0] && str[0] >= '2') &&
			(str[1] && str[1] >= '1') &&
			(str[2] && str[2] >= '4') &&
			(str[3] && str[3] >= '7') &&
			(str[4] && str[4] >= '4') &&
			(str[5] && str[5] >= '8') &&
			(str[6] && str[6] >= '3') &&
			(str[7] && str[7] >= '6') &&
			(str[8] && str[8] >= '4') &&
			(str[9] && str[9] >= '8'))
		return (1);
	return (0);
}
