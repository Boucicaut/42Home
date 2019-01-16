/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcentu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:45:31 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/16 15:01:56 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	fillcharu(unsigned long long int nb, char *str, int j)
{
	while (nb > 9)
	{
		str[j] = (nb % 10) + '0';
		nb = (nb - (nb % 10)) / 10;
		j--;
	}
	str[j] = (nb % 10) + '0';
}

void	uprintall(char *res, int *tab, int qtenb)
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

void	pourcentunll(va_list args, char *str, int *lim, int *i)
{
	int				qtenb;
	int				nb;
	char			*res;

	nb = va_arg(args, int);
	qtenb = ft_qtenb(nb, 'd', 10, 16);
	if (!(res = malloc(sizeof(char) * qtenb + 1)))
		return ;
	res[qtenb] = '\0';
	fillcharu(nb, res, qtenb - 1);
	uprintall(res, lim, qtenb);
/*
	tab[1] = tab[1] > qtenb ? tab[1] : qtenb;
	while (tab[0]-- > tab[1])
		ft_putchar(' ');	// ou des '0' a voir
	while (tab[1]-- > qtenb)
		ft_putchar('0');
	ft_putstr(res);
*/
	while (ft_isdigit(str[*i]) || str[*i] == 'u')
		*i = *i + 1;
	*i = *i - 1;
}

void	pourcentull(va_list args, char *str, int *lim, int *i)
{
	int						qtenb;
	long long int			nb;
	char					*res;

	nb = va_arg(args, long long int);
	qtenb = ft_qtebignb(nb, 10);
	if (!(res = malloc(sizeof(char) * qtenb + 1)))
		return ;
	res[qtenb] = '\0';
	fillcharu(nb, res, qtenb - 1);
	uprintall(res, lim, qtenb);
/*
	tab[1] = tab[1] > qtenb ? tab[1] : qtenb;
	while (tab[0]-- > tab[1])
		ft_putchar(' ');	// ou des '0' a voir
	while (tab[1]-- > qtenb)
		ft_putchar('0');
	ft_putstr(res);
*/
	while (ft_isdigit(str[*i]) || str[*i] == 'u')
		*i = *i + 1;
	*i = *i - 1;
}

int		pourcentu(va_list args, char *str, int *lim, int *i)
{
	int						j;
	unsigned long long int	nb;
	char					*res;
	int						qtenb;
	int						printed;

	j = *i;
	nb = va_arg(args, unsigned long long int);
	qtenb = ft_qtebignb(nb, 10);
	if (!(res = malloc(sizeof(char) * qtenb + 1)))
		return (0);
	res[qtenb] = '\0';
	fillcharu(nb, res, qtenb - 1);
//printf("Lim : %d %d %d %d %d %d %d || Qtenb : %d || Res : %s\n", lim[0], lim[1], lim[2], lim[3], lim[4], lim[5], lim[6], qtenb, res);
	printed = doshittythings(lim, res, 0, 'u');
	ft_putstr(res);
	(void)str;
	return (printed + (int)ft_strlen(res));
/*	while (str[*i] == '.' || str[*i] == '*' || ft_isdigit(str[*i]))
		*i = *i + 1;
	if (str[*i] == 'l')
	{
		*i = j;
		pourcentull(args, str, lim, i);
	}
	else
	{
		*i = j;
		pourcentunll(args, str, lim, i);
	}*/
}
