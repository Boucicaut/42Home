#include "../includes/ft_printf.h"

/* gerer les conversions csp
	conversion diouxX flags h, hh, l, ll
	conversion f flags l , L
	le %%
	#0 avec -, + et espace
	gerer taille minimun du champ
	gerer la precision

RECAP :
	D	%d %x.xd %ld %lld %hd %hhd - // FLAGS OK
	I	
	O	OK idem (ne gere que du unsigned)   A PRIORI OK mais peut etre bug avec vraiment le max max
	U	OK (unsigned uniquement)			^ 	
	X	OK			// FLAGS OK u et o	^
	F	OK
TO DO :
	corriger si * en lim[1], comme fait pour pourcentf, on doit break si str[*i] == '*'
*/



int		pourcentpourcent(va_list args, char *str, int *lim,  int *i)
{
	int	j;
	int	printed;

	printed = 0;
	j = *i - 1;
	while (str[j] && str[j] != '%')
		j--;
//printf(" Str : %s\n", &(str[j]));
	j++;
	/*while (str[j] && str[j] != '%' && (!ft_isdigit(str[j]) || str[j] == '0'))
	{
		str[j] == '0' ? lim[2] = 1 : 0;
		str[j] == '+' ? lim[3] = 1 : 0;
		str[j] == '-' ? lim[4] = 1 : 0;
		str[j] == ' ' ? lim[5] = 1 : 0;
		str[j++] == '#' ? lim[6] = 1 : 0;
	}*/
//printf(" Str : %s\n", &(str[j]));
	while (str[j] && str[j] != '%')
	{
		lim[0] = str[j] == '*' ? va_arg(args, int) : ft_atoi(&str[j]);
		j++;
	}
	lim[4] == 1 ? lim[1] = lim[0], lim[0] = 0 : 0;
	while (lim[0]-- > 1)
	{
		printed++;
		ft_putchar(' ');
	}
	ft_putchar('%');
	while (lim[1]-- > 1)
	{
		printed++;
		ft_putchar(' ');
	}
	free(lim);
	return (printed + 1);
}

int		whatafterpourcent(char *str, int i, va_list args, t_matchpat *tab) // appeler la bonne fonction suivant le %
{
	int	ii;
	int	j;
	int	printed;

	printed = 0;
	ii = i;
	while (str[ii])
	{
		j = 0;
//printf("Current str[%d] : %c\n", ii, str[ii]);
		while (j < MAXPOURCENT)
		{
			//if (str[ii] == tab[j].pattern)
			if (ft_issamealpha(str[ii], tab[j].pattern))
			{
//printf("Ok entered with : %s\n", &str[i]);
//printf("Ok entered with : %c %c\n", tab[j].pattern, str[ii]);
				printed = tab[j].f(args, str, setlim(str, &i, args), &i);
				return (printed);
			}
			j++;
		}
		/*if (str[ii] == '%')
		{
			pourcentpourcent((str + i), &i, args);
			return (ii + 1);
		}*/
		ii++;
	}
	return (printed);
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
	tab[9].pattern = '%';
	tab[9].f = &pourcentpourcent;
	return (tab);
}

int		gofurther(char *str, int i, t_matchpat *tab)
{
	int	j;

	while (str[i])
	{
		j = 0;
		while (j < MAXPOURCENT)
		{
			if (ft_issamealpha(str[i], tab[j].pattern))
				return (i + 1);
			j++;
		}
		i++;
	}
	return (i);
}

int		ft_printf(char *str, ...)
{
	va_list		args;
	int			i;
	t_matchpat	*tab;
	int			printed;

	printed = 0;
	tab = initmatchpat();
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i += 1;
			printed += whatafterpourcent(str, i, args, tab);
			i = gofurther(str, i, tab);
		}
		else if (str[i] != '\0')
		{
			ft_putchar(str[i]);
			printed += 1;
			i++;
		}
	}
	va_end(args);
	free(tab);
	return (printed);
}

/* A FAIRE : PRECISION POUR %d 
 * bah non, reutiliser la ft setlim en fait
 * avec le pattern utilise dans pourcentD qui est le plus opti */

/*
int	main(int argc, char **argv)
{
	unsigned char i = 59;
	long double  ii = 99999971.87544587;
	double	d = atof(argv[1]);
//	char	*j = malloc(sizeof(char) * 2);
	int j = 150;

//	printf("Size total : %d\n", ft_qtenb(atof(argv[1]), 'f', 10, 16));
//	printf("Size d     : %d\n", ft_qtenb(atof(argv[1]), 'd', 10, 16));
//	printf("Size z     : %d\n", ft_qtenb(atof(argv[1]), 'z', 10, 16));
	ft_printf("D : %+Lf AAAA\n", ii);
	printf("D : %+Lf AAAA\n", ii);


	ft_printf("%% || p : %20p et %2p || u : %*u || o : %6o || x : %#.5llx || f : %16f || di : %20.10lld et %i || s : %s || c : %c\n", &i, &j, 15, 1234,  1234, (long long int)12799, d, i, ii, "bien", 'E');
	printf("\t\t\t\t---------------------\n");
	printf("%% || p : %20p et %2p || u : %*u || o : %6o || x : %#.5llx || f : %16f || di : %20.10lld et %i || s : %s || c : %c\n", &i, &j, 15, 1234,  1234, (long long int)12799, d, i, ii, "bien", 'E'); 
	(void)i;
	(void)d;
	(void)j;
	(void)ii;
	(void)argc;
	(void)argv;
	return (0);
}*/
