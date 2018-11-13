#include "libft.h"

<<<<<<< HEAD
int	main(void)
{
	int	nb = -45874;
	char	*str;

	str = ft_itoa(nb);
	printf("NB = %s\n", str);
=======
int	main(int argc, char **argv)
{
	(void)argc;
	int	nb = atoi(argv[1]);

	printf("NB = %s\n", ft_itoa(nb));
>>>>>>> bbe1d56ff90addd1e430f5ebee91362e87f9b249
	return (0);
}
