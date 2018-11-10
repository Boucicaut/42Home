#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	int		i;
	char	c;

	c = '\n';
	i = 0;
	while (str[i] != '\0')
		i++;
	write(fd, str, i);
	write(fd, &c, 1);
}
