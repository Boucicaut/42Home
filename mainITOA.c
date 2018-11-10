#include "libft.h"

int	main(int argc, char **argv)
{
	(void)argc;
	int	nb = atoi(argv[1]);

	printf("NB = %s\n", ft_itoa(nb));
	return (0);
}
