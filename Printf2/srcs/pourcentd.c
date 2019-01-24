/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcentd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:31:49 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/24 19:04:41 by bviollet         ###   ########.fr       */
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
	if (s)
		s = ft_strdup(s);
	else
		s = ft_strdup("(null)");
	qte = (int)ft_strlen(s);
	lim[1] = lim[1] == 0 ? qte : lim[1];
	while (lim[1] < (int)ft_strlen(s))
		s[--qte] = '\0';
	qte = (int)ft_strlen(s);
	lim[1] = lim[1] > qte ? qte : lim[1];
	lim[0] = lim[0] > lim[1] ? lim[0] : lim[1];

	while (!lim[4] && lim[0]-- > lim[1])
	{
		printed++;
		ft_putchar(' ');
	}
	ft_putstr(s);
	printed += (int)ft_strlen(s);
	while (lim[4] && lim[0]-- > lim[1])
	{
		printed++;
		ft_putchar(' ');
	}
	(void)i;
	(void)str;
	free(lim);
	free(s);
	return (printed);
}

int		pourcentc(va_list args, char *str, int *lim, int *i)
{
	char	c;
	char	*res;
	int		printed;

//printf("t : %d %d %d %d %d %d\n", lim[0], lim[1], lim[2], lim[3], lim[4], lim[5]);
	printed = lim[0] ? lim[0] : 1;
	c = (char)va_arg(args, int);
	res = ft_strnew(3);
	if (c)
	{
		res[0] = c;
		res[1] = '\0';
	}
	else
	{
		res[0] = '^';
		res[1] = '@';
		res[2] = '\0';
	}
	while (!lim[4] && lim[0]-- > 1)
		lim[2] ? ft_putchar('0') : ft_putchar(' ');
	ft_putstr(res);
	while (lim[4] && lim[0]-- > 1)
		lim[2] ? ft_putchar('0') : ft_putchar(' ');
	free(lim);
	free(res);
	(void)i;
	(void)str;
	(void)lim;
	return (printed);
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

char	*delminus(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew((int)ft_strlen(str));
	if (str[0] && str[0] != '-')
	{
		free(tmp);
		return (str);
	}
	while (str[i + 1])
	{
		tmp[i] = str[i + 1];
		i++;
	}
	tmp[i] = '\0';
	free(str);
	return (tmp);
}

int		pourcentd(va_list args, char *str, int *lim, int *i)
{
	int				j;
	long long int	nb;
	int				neg;
	int				printed;
	char			*res;

	j = *i - 1;
	//nb = islongornot(str, j, 'd') ? va_arg(args, long long int) : va_arg(args, int);
//	printf("Int nb : %d, Ll nb : %lld\n", (int)nb, nb);
//printf("Res : (int)nb + nb : %lld\n", (int)nb + nb);
//	if (21474072687294 != (int)nb + nb && -21474072687294 != (int)nb + nb) // pas fou comme expression avec ces const !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//	printf("Str[*i] : %s\n", &(str[*i]));
	if (!(islongornot(str, j, 'd')))
	{
		nb = va_arg(args, int);
		nb = (int)nb;
		neg = nb >= 0 ? 0 : 1;
		res = ft_itoa(nb);
		//res[ft_qtenb(nb, 'd', 10, 10)] = '\0';
	}
	else
	{
		nb = va_arg(args, long long int);
		neg = nb > 0 ? 0 : 1;
		//nb = neg ? -nb : nb;
//printf("Ok, %lld\n", nb);
		res = ft_bigitoa(nb);
	}
	if (str[*i] == 'h')
	{
		nb = str[*i + 1] == 'h' ? converttosignedchar(nb, 2) : converttosignedchar(nb, 1);
		neg = nb < 0 ? 1 : 0;
		nb = neg ? -nb : nb;
		free(res);
		res = ft_itoa(nb);
	}

//printf("Res: %s && Neg : %d && Nb : %lld\n", res, neg, nb);
//printf("\n1 Res : %s\n", res);
	res = delminus(res);
//printf("\n2 Res : %s\n", res);
	while (str[j] && str[j] != '.' && str[j] != '%')
		j--;
	if (str[j] == '.' && !lim[1] && *res == '0')
		res[0] = '\0';
//printf("Res : %s || Len : %d\n", res, (int)ft_strlen(res));
//printf("\n3 Res : %s\n", res);
	printed = doshittythings(lim, res, neg, 'd');
	//ft_putbignbr(nb);

	free(res);
	free(lim);
	(void)str;
	return (printed);
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
