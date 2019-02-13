/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setflaglim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:03:50 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/11 19:43:05 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		signandbase(char *res, int neg, int *lim, char c)
{
	int	i;

	i = 0;
	if (neg)
		res[i++] = '-';
	if (lim[3] && c != 's')
		res[i++] = '+';
	if (lim[5] && c != 's')
		res[i++] = ' ';
	if (lim[6] && (c == 'o' || ft_issamealpha(c, 'x')))
		res[i++] = '0';
	if (lim[6] && ft_issamealpha(c, 'x'))
		res[i++] = c;
	return (i);
}

int		putend(char *res, int *lim, int *qtenb, char c)
{
	int	i;

	i = 0;
	if (c == 'f' && lim[6] && qtenb[1] <= 0)
	{
		res[i++] = '.';
		qtenb[1]++;
	}
	while (c == 'f' && lim[1] > (qtenb[1] < 0 ? 0 : qtenb[1]))
	{
		qtenb[1]++;
		res[i++] = '0';
	}
	while (lim[4] && lim[0] > qtenb[0])
	{
		qtenb[0]++;
		res[i++] = lim[2] ? '0' : ' ';
	}
	free(qtenb);
	return (i);
}

int		putbeginning(char *res, int *lim, int *qtenb, char c)
{
	int	i;
	int	b;

	b = 1;
	i = 0;
	if (lim[0] > qtenb[0] && !lim[4] && ((c == 'f' && lim[2]) ||\
(lim[1] == 0 && lim[2] && !lim[8]) || (lim[2] && lim[1] < 0)))
	{
		i += signandbase(res + i, lim[7], lim, c);
		b = 0;
	}
	while (!lim[4] && lim[0] > qtenb[0])
	{
		qtenb[0]++;
		res[i++] = (c != 's') && ((c == 'f' && lim[2]) ||\
(lim[1] == 0 && lim[2] && !lim[8]) || (lim[2] && lim[1] < 0)) ? '0' : ' ';
	}
	i += b ? signandbase(res + i, lim[7], lim, c) : 0;
	while (c != 'f' && lim[1] > qtenb[1])
	{
		qtenb[1]++;
		res[i++] = lim[2] ? '0' : '0';
	}
	return (i);
}

int		doshittythings(int *lim, char *nb, int neg, char c)
{
	char	*res;
	int		*qtenb;
	int		i;

	i = 0;
	lim[7] = neg ? 1 : 0;
	qtenb = preqte(lim, c, neg, nb);
	if (c == 'f')
		res = ft_strnew(sizeof(char) * (lim[0] > qtenb[0] ? lim[0] : qtenb[0]));
	else
		res = ft_strnew(sizeof(char) * 1 +\
(1 + (qtenb[0] > lim[0] ? qtenb[0] : lim[0])));
	i = putbeginning(res, lim, qtenb, c);
	res = ft_strcat(res, nb);
	i += ft_strlen(nb);
	i += putend(res + i, lim, qtenb, c);
	ft_putstr(res);
	i = (int)ft_strlen(res);
	free(res);
	return (i);
}

int		*setflag(char *str, int *i, int *tab)
{
	while (str[*i] && (str[*i] == '0' || str[*i] == '+' || str[*i] == '-' ||
str[*i] == ' ' || str[*i] == '#'))
	{
		if (str[*i] == '0')
			tab[2] = 1;
		if (str[*i] == '+')
			tab[3] = 1;
		if (str[*i] == '-')
			tab[4] = 1;
		if (str[*i] == ' ')
			tab[5] = 1;
		if (str[*i] == '#')
			tab[6] = 1;
		*i += 1;
	}
	tab[5] = tab[5] == 1 && tab[3] == 1 ? 0 : tab[5];
	tab[2] = tab[4] == 1 && tab[2] == 1 ? 0 : tab[2];
	return (tab);
}
