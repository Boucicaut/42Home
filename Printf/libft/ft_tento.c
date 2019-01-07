#include "libft.h"

double	ft_tento(int nb, int i)
{
	double	res;

	res = 1;
	while (i-- > 0)
		res = res * nb;
	return (res);
}
