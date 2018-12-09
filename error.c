#include "fillit.h"

int		ft_numberline(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	i--;
	return (i);
}

int		sharpvalid(char **str, int i, int j, int k, char direction)
{
	//printf("** i = %d | j = %d | k = %d | dir = %c\n",i, j, k, direction);

	//printf("char[%d][%d] : %c\n", i, j, str[i][j]);
	ft_putstr(" k");
	ft_putnbr(k);
	ft_putchar('i');
	ft_putnbr(i);
	ft_putchar('j');
	ft_putnbr(j);
	if (k <= 3 && j < 4 && direction != 'g' && str[i][j + 1] == '#')
		return (sharpvalid(str, i, j + 1, k + 1, 'd'));
	if (k <= 3 && j > 0 && direction != 'd' && str[i][j - 1] == '#')
		return (sharpvalid(str, i, j - 1, k + 1, 'g'));
	if (k <= 3 && i > 0 &&  direction != 'h' && str[i - 1][j] == '#')
		return (sharpvalid(str, i - 1, j, k + 1, 'b'));
	if (k <= 3 && direction != 'b' && str[i + 1][j] == '#')
		return (sharpvalid(str, i + 1, j, k + 1, 'h'));
	if (k >= 4)
		return (1);
	if (direction == 'd')
		return (sharpvalid(str, i, j - 1, k, 'g'));
	return (0);

/*
	if (k != 1 && i > 0 && j > 0 && str[i - 1][j - 1] == '#')
		return (sharpvalid(str, i - 1, j - 1, k, 'g'));
	if (k != 1 && j < 4  && str[i + 1][j + 1] == '#')
		return (sharpvalid(str, i, j + 1, k, 'd'));
	if (k != 1 && j < 4 && i > 0 && direction != 'h' && str[i - 1][j + 1] == '#')
		return (sharpvalid(str, i - 1, j + 1, k, 'b'));
	if (k != 1 && k != 3 && j > 0 && str[i + 1][j - 1] == '#')
		return (sharpvalid(str, i + 1, j - 1, k, 'h'));*/

/* fix le cas d'une diagonale en 1st avec k > 1 sur le i++ et j++
 * cas avec diagonale apres 1st, passent et ne devraient pas
*/

	if (k >= 4)
	{
		printf("OK\n");
		return (1);
	}
	return (0);
}

int		error(char **str)
{
	int		i;
	int		j;
	int		k;
	int		ii;

	k = 0;
	i = 0;
	j = 0;

	  while (str[i] != NULL)
	  {	
	  	while (str[i][j] != '\0')
	  	{	
	  		ft_putchar(str[i][j]);
			ft_putchar(' ');
	  		j++;
	  	}
		ft_putchar('\n');
	  	i++;
	  	j = 0;
	  }
	  	ft_putstr("---------\n");

	/* 4 # entre deux '\n' a j = 0
	 * 4 lignes par 4 lignes
	 * 4 colonnes 
	 * maximum 26 pieces */

	i = 0;
	j = 0;
	while ((i <= ft_numberline(str)) && (str[i] != NULL))
	{
		k = 0;
		ii = 0;
		while (str[i + ii] && str[i + ii][0] != '\0')
		{
			j = 0;
			while (str[i + ii][j] != '\0')
			{
				if (str[i + ii][j] != '.' && str[i + ii][j] != '#')
					return (0);
				if (str[i + ii][j] == '#')
				{
					if (k == 0)
						if (!(sharpvalid(str, i + ii, j, 1, 'a')))
						{
							ft_putstr("ERROR");
							return (0);
						}
					printf("SORTI\n");
					k++;
				}
				j++;
			}
			printf("!! i = %d | ii = %d | j = %d | k = %d\n",i,  ii, j, k);
			ii++;
		}
		printf("i = %d | ii = %d | j = %d | k = %d\n",i, ii, j, k);
		if ((ii != 4 | j != 4 || k != 4) || (ii == 0 && k == 0))
			return (0);
		i = i + ii + 1;
	}
	return (1);
}

/* > 
 *while (str[i] != NULL)
 * while (str[i][j] != '\0')
 * 		j++;
 * 		if (j > 4)
 * 			return 1
 * 		if (str[i][j] == #)
 * 			k++;
 i++*/

/* 0 si erreur
 * 1 si ok */
