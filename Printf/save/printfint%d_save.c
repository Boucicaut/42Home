#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"

/* gerer les conversions csp
	conversion diouxX flags h, hh, l, ll
	conversion f flags l , L
	le %%
	#0 avec -, + et espace
	gerer taille minimuj du champ
	gerer la precision

tab avec les ptr sur  fonctions */

	//	ft_printf("OK %f ca %15.5f cest %s str\n", atof(argv[1]), atof(argv[2]), "bien");

void	pourcentf(va_list args, char *str, int *i)
{
	int	qtenb;
	int	qtenb2;
	int	qtetotalnb;
	double	nb;
	int	lim1;
	int	lim2;
	int *tab;

	lim1 = 0;
	lim2 = 0;
	nb = va_arg(args, double);
	tab = ft_splitdouble(nb);
//printf("--\n(%d . %d)\n", tab[0], tab[1]);
	qtetotalnb = sizenbchar(10, 0, nb, 'f');
//printf("s : %c\n", str[*i]); 
	if (str[*i] && ft_isdigit(str[*i]))
		lim1 = ft_atoi(&str[*i]);
//printf("\n___. STR[I] : %c ---\n", str[*i]);
	while (str[*i] != 'f')
	{
		*i = *i + 1;
		if (str[*i] == '.')
		{
			*i = *i + 1;
			lim2 = ft_atoi(&str[*i]);
		}
	}
//printf("LIM1 : %d    LIM2 : %d\n", lim1, lim2);
	qtenb = sizenbchar(10, 0, (int)nb, 'd');
// nb1 = lim 1 ; nb2 = lim2 decimal ; qtetotal = qte total nb ; qtenb = qte nb entier
	qtenb2 = sizenbchar(10, 0, nb, 'z');

//printf("Lim1 : %d, lim2 : %d, qtetotalnb : %d, qtenb : %d, qtenb2 : %d\n", lim1, lim2, qtetotalnb, qtenb, qtenb2);

	while (lim1 != 0 && lim1-- - 1 - (qtenb + lim2) > 0)
		ft_putchar(' ');
	ft_putnbr(tab[0]);	// affichage partie entiere
	ft_putchar('.');

	while (lim2 != 0 && qtenb2 > lim2)
	{
		tab[1] = tab[1] / 10;
		qtenb2 = sizenbchar(10, 0, tab[1], 'd');
	}
	ft_putnbr(tab[1]);
	if (lim2 == 0)
		lim2 = 6;
	while (tab[1] != 0 && qtenb2 < 6 && qtenb2 < lim2)  // voir si 0 en trop ?? a priori ok
	{
		ft_putnbr(0);
		qtenb2++;
	}
	while (ft_isdigit(str[*i]) || str[*i] == 'f')
		*i = *i + 1;
	*i = *i - 1;
free(tab);
}

void	pourcentd(va_list args, char *str, int *i)
{
	int	qtenb;
	int	nb;
	int	pb;

	pb = 0;
	nb = va_arg(args, int);
	qtenb = sizenbchar(10, 0, nb, 'd');
	if (str[*i] && ft_isdigit(str[*i]))
		pb = ft_atoi(&str[*i]);
	while (pb-- > qtenb)
		ft_putnbr(0);	// ou des ' ' a voir
	ft_putnbr(nb);
	while (ft_isdigit(str[*i]) || str[*i] == 'd')
		*i = *i + 1;
	*i = *i - 1;
}
//nb = sizenbchar(10, i, nb);

void	printnb(int	*i, char *str, va_list args) // appeler la bonne fonction suivant le %
{
	int	ii;

	ii = *i;
	while (str[ii])
	{
		if (str[ii] == 'd')
		{
			pourcentd(args, str, i);
			return ;
		}
		if (str[ii] == 'f')
		{
			pourcentf(args, str, i);
			return ;
		}
		//...
		ii++;
	}

}

void	ft_printf(char *str, ...)
{
	va_list	args;
	int	i;

	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			{
				i++;
				if (str[i] == 'd' || str[i] == 'i' || str[i] == 'f' || ft_isdigit(str[i]))
					printnb(&i, str, args);
				else if (str[i] == 's')
					ft_putstr((char *)va_arg(args, int*));
				i++;
			}
		ft_putchar(str[i]);
		i++;
	}
	va_end(args);
}

int	main(int argc, char **argv)
{
	int	i;
	(void) argc;

	i = 0;
	ft_printf("OK %f ca %15.6f cest %s str\n", atof(argv[1]), atof(argv[2]), "bien");
	printf("---------------------\n");
	printf("OK %f ca %15.6f cest %s str\n", atof(argv[1]), atof(argv[2]), "bien");
	return (0);
}
