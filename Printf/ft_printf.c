#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

/* gerer les conversions csp
	conversion diouxX flags h, hh, l, ll
	conversion f flags l , L
	le %%
	#0 avec -, + et espace
	gerer taille minimun du champ
	gerer la precision

RECAP :
	D	%d %x.xd %ld %lld %hd %hhd -
	I	
	O	OK idem (ne gere que du unsigned)   A PRIORI OK mais peut etre bug avec vraiment le max max
	U	OK (unsigned uniquement)			^ 	
	X	OK									^
	F	OK
TO DO :
	corriger si * en lim[1], comme fait pour pourcentf, on doit break si str[*i] == '*'


tab avec les ptr sur  fonctions */

int		whatafterpourcent(char *str, int i, va_list args, t_matchpat *tab) // appeler la bonne fonction suivant le %
{
	int	ii;
	int	j;

	ii = i;
	while (str[ii])
	{
		j = 0;
		while (j < MAXPOURCENT)
		{
			//if (str[ii] == tab[j].pattern)
			if (ft_issamealpha(str[ii], tab[j].pattern))
			{
				i++;
				tab[j].f(args, str, &i);
				return (ii + 1);
			}
			j++;
		}
		ii++;
	}
	return (i);
}

t_matchpat	*initmatchpat(void)
{
	t_matchpat	*tab;

	if (!(tab = malloc(sizeof(t_matchpat) * MAXPOURCENT + 1)))
		return (NULL);
	tab[0].pattern = 'd';
	tab[0].f = &pourcentd;
	tab[2].pattern = 'i';
	tab[2].f = &pourcentd;
	tab[6].pattern = 'o';
	tab[6].f = &pourcento;
	tab[7].pattern = 'u';
	tab[7].f = &pourcentu;
	tab[5].pattern = 'x';
	tab[5].f = &pourcentx;
	tab[1].pattern = 'f';
	tab[1].f = &pourcentf;
	tab[3].pattern = 's';
	tab[3].f = &pourcents;
	tab[4].pattern = 'c';
	tab[4].f = &pourcentc;
	tab[8].pattern = 'p';
	tab[8].f = &pourcentp;
	return (tab);
}

void	ft_printf(char *str, ...)
{
	va_list		args;
	int			i;
	t_matchpat	*tab;

	tab = initmatchpat();
	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			i += 2;
			ft_putchar('%');
		}
		else if (str[i] == '%')
			i = whatafterpourcent(str, i, args, tab);
		ft_putchar(str[i]);
		i++;
	}
	va_end(args);
}

/* A FAIRE : PRECISION POUR %d 
 * bah non, reutiliser la ft setlim en fait
 * avec le pattern utilise dans pourcentD qui est le plus opti */

#include <limits.h>

int	main(int argc, char **argv)
{
	unsigned char i = 59;
	long int  ii = 99999999977895;
	double	d = atof(argv[1]);
//	char	*j = malloc(sizeof(char) * 2);
	char j = 'd';

/*	printf("Size total : %d\n", ft_qtenb(atof(argv[1]), 'f', 10, 16));
	printf("Size d     : %d\n", ft_qtenb(atof(argv[1]), 'd', 10, 16));
	printf("Size z     : %d\n", ft_qtenb(atof(argv[1]), 'z', 10, 16));*/
	ft_printf("D : %.*ld AAAA\n", 10, ii);
	printf("D : %.*ld AAAA\n", 10, ii);

/*
	ft_printf("%% || p : %20p et %2p || u : %*u || o : %6o || x : %#.5llx || f : %16f || di : %20.10lld et %i || s : %s || c : %c\n", &i, &j, 15, 1234,  1234, (long long int)12799, d, i, ii, "bien", 'E');
	printf("\t\t\t\t---------------------\n");
	printf("%% || p : %20p et %2p || u : %*u || o : %6o || x : %#.5llx || f : %16f || di : %20.10lld et %i || s : %s || c : %c\n", &i, &j, 15, 1234,  1234, (long long int)12799, d, i, ii, "bien", 'E'); */
	(void)i;
	(void)d;
	(void)j;
	(void)ii;
	(void)argc;
	(void)argv;
	return (0);
}
