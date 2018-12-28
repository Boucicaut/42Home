#include "libft.h"

int	ft_tento(int nb, int i)
{
	int	res;

	res = 1;
	while (i-- > 0)
		res = res * nb;
	return (res);
}
