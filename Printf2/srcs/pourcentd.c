/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcentd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:31:49 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/17 21:35:58 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		pourcents(va_list args, char *str, int *lim, int *i)
{
	char	*s;
	int		printed;
	int		qte;
	int		j;

//printf("t : %d %d %d %d %d %d\n", lim[0], lim[1], lim[2], lim[3], lim[4], lim[5]);
	j = 0;
	printed = 0;
	s = (char*)va_arg(args, int*);
	qte = ft_strlen(s);
	if (lim[1] > 0)
		lim[1] = lim[1] < qte ? lim[1] : qte;
	else
		lim[1] = qte;
	while (lim[0]-- > lim[1])
	{
		printed++;
		ft_putchar(' ');
	}
	while (lim[1]-- > 0)
	{
		//ft_putstr(s);
		ft_putchar(s[j++]);
		printed++;
	}
	(void)i;
	(void)str;
	return (printed);
}

int		pourcentc(va_list args, char *str, int *lim, int *i)
{
	int		printed;
	char	c;
	char	*res;

	c = (char)va_arg(args, int);
	res = ft_strnew(2);
	res[0] = c;
	res[1] = '\0';
	printed = doshittythings(lim, res, 0, 'c');
	free(res);
	(void)i;
	(void)str;
	(void)lim;
	return (printed + 1);
}

void	pourcentdll(va_list args, char *str, int *lim, int *i)
{
	long long int	nb;
	int				*tab;

	tab = setlim(str, i, args);
	nb = va_arg(args, long long int);
	tab[1] = tab[1] > ft_qtebignb(nb, 10) ? tab[1] : ft_qtebignb(nb, 10);
	if (tab[4])
	{
		tab[5] == 1 ? ft_putchar(' ') : 0;
		tab[3] == 1 && nb > 0 ? ft_putchar('+') : 0;
		ft_putbignbr(nb);
	}
	while (tab[0]-- > tab[1] + tab[3] + tab[5])
		tab[2] == 1 ? ft_putchar('0') : ft_putchar(' ');
	while (tab[1]-- > ft_qtebignb(nb, 10))
		ft_putchar('0');
	if (!tab[4])
	{
		tab[5] == 1 ? ft_putchar(' ') : 0;
		tab[3] == 1 && nb > 0 ? ft_putchar('+') : 0;
		nb < 0 ? ft_putbignbr(-nb) : ft_putbignbr(nb);
	}
	while (ft_isdigit(str[*i]) || str[*i] == 'd' || str[*i] == 'i')
		*i = *i + 1;
	*i = *i - 1;
	(void)lim;
}

void	pourcentdnol(va_list args, char *str, int *lim, int *i)
{
	int				nb;
	int				*t;

	t = setlim(str, i, args);
	nb = va_arg(args, int);
//printf("Nb : %d\n", nb);
//printf("t : %d %d %d %d %d %d qte:%d\n", t[0], t[1], t[2], t[3], t[4], t[5], ft_qtenb(nb, 'd', 10, 16));
	t[1] = t[1] > ft_qtenb(nb, 'd', 10, 16) ? t[1] : ft_qtenb(nb, 'd', 10, 16);
	if (t[4])
	{
		t[5] == 1 ? ft_putchar(' ') : 0;
		t[3] == 1 && nb > 0 ? ft_putchar('+') : 0;
		ft_putnbr(nb);
	}
	nb < 0 ? ft_putchar('-'),  t[1]++ : 0;
	while (t[0]-- > t[1] + t[3] + t[5])
		t[2] == 1 ? ft_putchar('0') : ft_putchar(' ');
	while (t[1]-- > ft_qtenb(nb, 'd', 10, 16) + (nb < 0 ? 1 : 0))
		ft_putchar('0');
	if (!t[4])
	{
		t[5] == 1 ? ft_putchar(' ') : 0;
		t[3] == 1 && nb > 0 ? ft_putchar('+') : 0;
		nb < 0 ? ft_putbignbr(-nb) : ft_putbignbr(nb);
	}
	(void)lim;
}

int		pourcentd(va_list args, char *str, int *lim, int *i)
{
	int				j;
	long long int	nb;
	int				neg;
	int				printed;
	char			*res;

	j = *i - 1;
	nb = islongornot(str, j, 'f') ? va_arg(args, long long int) : va_arg(args, int);
//printf("INTnb: %d, INT-nb: %d, NB: %lld, -NB:%lld \n\n", (int)nb, (int)-nb, nb, -nb);

//printf("Res : (int)nb + nb : %lld\n", (int)nb + nb);
	if (21474072687294 != (int)nb + nb && -21474072687294 != (int)nb + nb) // pas fou comme expression avec ces const !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	{
		nb = (int)nb;
		neg = nb > 0 ? 0 : 1;
		nb = neg ? -nb : nb;
		res = ft_itoa(nb);
	}
	else
	{
		neg = nb > 0 ? 0 : 1;
		nb = neg ? -nb : nb;
		res = ft_bigitoa(nb);
	}
	printed = doshittythings(lim, res, neg, 'd');
//printf("NB : %lld\n", nb);
	//ft_putbignbr(nb);

	free(lim);
	(void)str;
	return (printed + ft_qtebignb(nb, 10));
/*
	lim[1] = lim[1] > ft_qtebignb(nb, 'd') ? lim[1] : ft_qtebignb(nb, 'd');
	if (lim[4])
	{
		lim[5] == 1 ? ft_putchar(' ') : 0;
		lim[3] == 1 && nb > 0 ? ft_putchar('+') : 0;
		ft_putnbr(nb);
	}
	while (lim[0]-- > lim[1] + lim[3] + lim[5])
		lim[2] == 1 ? ft_putchar('0') : ft_putchar(' ');
	while (lim[1]-- > ft_qtebignb(nb, 'd') + (nb < 0 ? 1 : 0))
		ft_putchar('0');
	if (!lim[4])
	{
		lim[5] == 1 ? ft_putchar(' ') : 0;
		lim[3] == 1 && nb > 0 ? ft_putchar('+') : 0;
		ft_putnbr(nb);
	}*/

/*
	j = *i;
//printf("\nSTART : %s\n", str + *i);
	while (str[*i] && str[*i] != 'l' && str[*i] != 'd' && str[*i] != 'i')
	{
//printf("\nSTART : %s\n", str + *i);
		*i = *i + 1;
	}
	if (str[*i] == 'l')
	{
		*i = j;
		pourcentdll(args, str, i);
	}
	else
	{
		*i = j;
		pourcentdnol(args, str, i);
	}*/
}
