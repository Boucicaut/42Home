#include "libft.h"

void	ft_runthrough(char **ptr, void (*f)(char **ptr, int i, int j))
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ptr)
	{
		while (ptr[i])
		{
			while (ptr[i][j])
			{
				f(ptr, i, j);
				j++;
			}
			i++;
			j = 0;
		}
	}
}
