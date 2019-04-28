#include <stdio.h>
#include <stdlib.h>
#include "Libft/libft.h"

void	*ft_realloc(void *ptr, int cursize, int newsize)
{
	void *tmp;

	if (!(tmp = malloc(newsize)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(tmp, ptr, cursize);
		free(ptr);
	}
	return (tmp);
}

int	main(void)
{
	char *str = malloc(sizeof(char) * 6);
char	c[10] = {0};

	str[0] = 'a';
	str[1] = 'a';
	str[2] = 'a';
	str[3] = 'a';
	str[4] = 'a';
	str[5] = '\0';
	printf("Str : %s\n", str);
	str = (char*)ft_realloc(str,6, 11);
	str[5] = 'b';
	str[6] = 'b';
	str[7] = 'b';
	str[8] = 'b';
	str[9] = 'b';
	str[10] = '\0';

	printf("Str : %s\n", str);
	free(str);
(void)c;
	return (0);
}
