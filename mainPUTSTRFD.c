#include "libft.h"
#include <fcntl.h>

int	main(void)
{
	int		i = open("fd", O_CREAT | O_RDWR);
	ft_putstr_fd("Aller !!! ok", i);
	close(i);
	return 0;
}
