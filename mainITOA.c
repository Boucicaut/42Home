#include "libft.h"

int	main(void)
{
	int	nb = -45874;
	char	*str;

	str = ft_itoa(nb);
	printf("NB = %s\n", str);
	return (0);
}
