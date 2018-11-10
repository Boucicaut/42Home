#include "libft.h"
#include <fcntl.h>

int	main(void)
{
	int	i;
	int fd;

	fd = open("fd", O_RDWR | O_CREAT);
	i = -900836401;
	ft_putnbr_fd(i, fd);
	return (0);
}
