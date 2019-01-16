#include "../includes/ft_printf.h"

/* 
	lim[0] : width	|	lim[1] : precision	|	2: '0' | 3: '+' | 4: '-' | 5: ' ' | 6: '#'
*/
int		doshittythings(int *lim, char *nb, int neg, char c)
{
	int	printed;
	char *res;
	int	qtenb;
	int	i;

	i = 0;
	printed = 0;
	
	if (c == 'u' || ft_issamealpha(c, 'x') || c == 'o' || neg)	// ignore '+' si  u x o
		lim[3] = 0;
	if (c == 'u' || ft_issamealpha(c, 'x') || c == 'o' || neg) // ignore ' ' si uxo ou < 0
		lim[5] = 0;
	if (c == 'p' || c == 's' || c == 'c' || lim[1]) // ignore '0' si psc ou lim[1] prec. int
		lim[2] = 0;
	if (c == 'd' || c == 'i' || c == 'u' || c == 'c' || c == 's') // ignore '#' si diucs
		lim[6] = 0;

	qtenb = (int)ft_strlen(nb);
	if (c != 'f' && lim[1] > (int)ft_strlen(nb))	// lim[1] ou qtenb
		qtenb = lim[1];
	if (c == 'o')
		qtenb += lim[6];	// # de o
	if (ft_issamealpha(c, 'x'))
		qtenb += lim[6] * 2;	// # de x
	qtenb += neg;				// a priori neg

	i = qtenb > lim[1] ? qtenb : lim[1];
	i = i > lim[0] ? i : lim[0]; // lim[0] = qtenb si inferieure
	res = ft_memalloc(sizeof(char) * i);

	i = 0;
	while (lim[4] && lim[0] > qtenb++)		// lim[0] >, print 0 ou ' ' AVANT
		res[i++] = lim[2] ? '0' : ' ';
	if (neg)
		res[i++] = '-';	
	if (lim[3] || lim[5])	// si '+' ' ', print '+'
		res[i++] = '+';
	while (c != 'f' && lim[1]-- > qtenb)	// lim[1] '0' si != 'f'
		res[i++] = '0';

	res = ft_strcat(res, nb);	// concatene les deux chaines

	while (c != 'f' && lim[1]-- > (int)ft_strlen(ft_strchr(nb, '.')))	// lim[1] '0' si == 'f'
		res[i++] = '0';
	if (c == 'f' && lim[6])	// ajoute le '.' si 'f' et lim[6]
		res[i++] = '.';
	
	while (lim[4] && lim[0] > qtenb++)		// lim[0] >, print 0 ou ' ' APRES
		res[i++] = lim[2] ? '0' : ' ';
	ft_putstr(res);
	i = (int)ft_strlen(res);
	free(res);
	return (i);
//	qtenb = c == 'f' ? ft_strlen(ft_strchr(nb, '.')) : ft_strlen(nb); // concerne 'f' et lim[1]
}

int		*setflag(char *str, int *i, int *tab)
{
	//printf("Str : %s\n", &str[*i]);
	*i -= 1;
	while (str[*i] && str[*i] != '*' &&
str[*i] != '.' && (!(ft_isalnum(str[*i])) || str[*i] == '0'))
	{
		*i += 1;
		str[*i] == '0' /*&& !ft_isdigit(str[*i + 1])*/ ? tab[2] = 1, *i += 1 : 0;
		str[*i] == '+' ? tab[3] = 1, *i += 1 : 0;
		str[*i] == '-' ? tab[4] = 1, *i += 1 : 0;
		str[*i] == ' ' ? tab[5] = 1, *i += 1 : 0;
		str[*i] == '#' ? tab[6] = 1, *i += 1 : 0;
	}
/*	tab [2] == '0' || tab[3] == '+' || tab[4] == '-' || tab[5] == ' ' || tab[6] == '#'	*/

	tab[5] = tab[5] == 1 && tab[3] == 1 ? 0 : tab[5];
	tab[2] = tab[4] == 1 && tab[2] == 1 ? 0 : tab[2]; // Prends le dessus ? Flag '0' ou '-' ??
//printf("\nTab : %d %d %d %d %d %d %d\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6]);
	return (tab);
}

int		*setlim(char *str, int *i, va_list args)
{
	int	*tab;

	if (!(tab = (int*)malloc(sizeof(int) * 7)))
		return (NULL);
	ft_bzero(tab, sizeof(int) * 7);
	tab = setflag(str, i, tab);
//printf("\nAfter-Flag Tab : %d %d %d %d %d %d %d\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6]);
//printf("\nStr : %s\n", str + *i); // on se situe sur le 1er %
	if (str[*i] == '*')
	{
		tab[0] = va_arg(args, int);
		*i += 1;
	}
	else
	{
		tab[0] = ft_atoi(&str[*i]);
		tab[0] != 0 ? *i += ft_qtenb(tab[0], 'd', 10, 10) : 0;
//printf("Tab[0] : %d et Qte : %d\n", tab[0], ft_qtenb(tab[0], 'd', 10, 10));
	}
	if (str[*i] == '.')
		*i += 1;
	if (str[*i] == '*')
	{	
		tab[1] = va_arg(args, int);
		*i += 1;
	}
	else
	{
		tab[1] = ft_atoi(&str[*i]);
		tab[1] != 0 ? *i += ft_qtenb(tab[1], 'd', 10, 10) : 0;
	}
//printf("\nAfter-Lim Tab : %d %d\n", tab[0], tab[1]);
//printf("tab %d %d %d %d %d %d %d \n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6]);
	return (tab);
}
