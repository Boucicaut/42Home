#include "libft.h"

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
