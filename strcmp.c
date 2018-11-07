#include <stdio.h>
#include <string.h>
int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;

	while (s1[i] == s2[i])
		i++;
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d", ft_strcmp(argv[1], argv[2]));
	printf("%d", strcmp(argv[1], argv[2]));
	return (0);

}
