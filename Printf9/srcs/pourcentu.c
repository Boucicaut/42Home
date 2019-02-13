/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcentu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:45:31 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/13 18:05:21 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				uprintall(char *res, int *tab, int qtenb)
{
	tab[1] = tab[1] > qtenb ? tab[1] : qtenb;
	if (tab[4])
	{
		tab[5] == 1 ? ft_putchar(' ') : 0;
		tab[3] == 1 && *res != '-' ? ft_putchar('+') : 0;
		ft_putstr(res);
	}
	while (tab[0]-- > tab[1] + tab[5])
		tab[2] == 1 ? ft_putchar('0') : ft_putchar(' ');
	while (tab[1]-- > qtenb)
		ft_putchar('0');
	if (!tab[4])
	{
		tab[5] == 1 ? ft_putchar(' ') : 0;
		tab[3] == 1 && *res != '-' ? ft_putchar('+') : 0;
		ft_putstr(res);
	}
}

void				fillcharu(unsigned long long int nb, char *str, int j)
{
	while (nb > 9)
	{
		str[j] = (nb % 10) + '0';
		nb = (nb - (nb % 10)) / 10;
		j--;
	}
	str[j] = (nb % 10) + '0';
}

unsigned long long	pourcentu2(va_list args, char *str, int i)
{
	unsigned long long int	nb;
	int						nb2;
	long long int			nb3;

	if (str[i] == 'h')
	{
		nb2 = va_arg(args, int);
		nb = convunsigned(nb2);
	}
	else if (ft_issamealpha(str[i], 'u'))
	{
		nb3 = va_arg(args, long long int);
		nb = convunsigned(nb3);
	}
	else if (islon(str, i, 'u'))
		nb = va_arg(args, unsigned long long int);
	else
		nb = va_arg(args, unsigned int);
	return (nb);
}

int					pourcentu(va_list args, char *str, int *lim, int *i)
{
	unsigned long long int	nb;
	char					*res;
	int						qtenb;

	nb = pourcentu2(args, str, *i);
	qtenb = nb == 0 ? 1 : ft_qtebignb(nb, 10);
	res = ft_strnew(qtenb);
	res[qtenb] = '\0';
	if (qtenb > 1)
	{
		fillcharu(nb, res, qtenb - 1);
		res = checkzero(res);
	}
	else
		fillcharu(nb, res, 0);
	while (str[*i] && str[*i] != '.' && str[*i] != '%')
		*i -= 1;
	res[0] = str[*i] == '.' && !lim[1] && nb == 0 ? '\0' : res[0];
	qtenb = doshittythings(lim, res, 0, 'u');
	free(res);
	free(lim);
	return (qtenb);
}
