#include "libft.h"

char	*ft_strrev(char *str)
{
	int	i;
	int	len;
	char	*strev;

	i = 0;
	len = ft_strlen(str) - 1;
	strev = ft_strnew(len);
	while (str[i])
	{
		strev[len] = str[i];
		len--;
		i++;
	}
	return (strev);
}

void	printbits(void *ptr, int size)
{
	int		i;
	int		j;
	char	*str;
	char	*buf;

	buf = ft_strnew(size);
	str = ft_strnew(64 + 8);
	j = 0;
	i = -1;
	memcpy((void*)buf, (void*)ptr, size);
	while (++i < size)
	{
		str[j++] = (*(char*)buf & 0x01) + '0';
		*buf >>= 1;
	}
	i = -1;
	str = ft_strrev(str);
	j = size % 8;
	while (++i < size)
	{
		if (i == j && i != 0)
			write(1, " ", 1);
		else if (((i % 8) == 0) && i != j)
			write(1, " ", 1);
		write(1, str + i, 1);
	}
}
