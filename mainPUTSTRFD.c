#include "libft.h"
#include <fcntl.h>

int	main(void)
{
	int		i = open("fd", O_CREAT | O_RDWR);
	ft_putchar_fd('a', i);
	close(i);
	return 0;
}
