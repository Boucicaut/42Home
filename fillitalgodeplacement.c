#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


void	afficher(char str[9][4]);
int	main(void)
{
	char str[19][4] = {{'.', '.', '#', '.'},{
						'.', '.', '#', '.'},{
						'.', '.', '#', '.'},{
						'.', '.', '#', '.'},{
						0},{
						'.', '.', '.', '.'},{
						'#', '#', '#', '#'},{
						'.', '.', '.', '.'},{
						'.', '.', '.', '.'},{
						0},{
						'.', '#', '#', '.'},{
						'.', '.', '#', '#'},{
						'.', '.', '.', '.'},{
						'.', '.', '.', '.'},{
						0},{
						'.', '.', '.', '.'},{
						'.', '.', '.', '.'},{
						'.', '.', '#', '#'},{
						'.', '.', '#', '#'}};

	int	i = 0;
	int	j = 0;
	double	k = 0;
	int	a = 1;
	int	ii = 0;
	int	jj = 0;
	int nbpiece = 0;

	while (i < 19)
	{
		if (str[i][j] == '\0')
			a = 1;
printf("\nnbpiece = %d, a = %d\n", nbpiece, a);
		while (j < 4)
		{
			if (str[i][j] == '#' && a == 1)
			{
				jj = j;
				ii = i - nbpiece * 5;
				a = 0;
				str[i][j] = '.';
				str[nbpiece * 5][0] = '#';
				nbpiece++;
			}
printf("nb piece : %d\n", nbpiece);

			if (str[i][j] == '#' && a == 0)
			{
				
				str[i - ii][j - jj] = '#';
printf("i : %d, ii : %d\n", i, ii);
printf("j : %d, jj : %d\n\n", j, jj);
				str[i][j] = '.';
afficher (str);
			}
			j++;
		}
		j = 0;
		i++;
	}
write(1, "\n\n", 2);
afficher (str);
write(1, "\n\n", 2);
return (0);
}

void	afficher(char str[18][4])
{
	int i = 0;
	int j = 0;
	while (i < 18)
	{
		while (j < 4)
		{
		write(1, &str[i][j], 1);
		j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}
