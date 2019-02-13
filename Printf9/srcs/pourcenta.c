/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcenta.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:02:26 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/13 18:02:09 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		printbeforea(char *str, int i, int *lim, int qted)
{
	int	printed;

	printed = 0;
	while (str[i] && str[i] != 'a' && str[i] != 'A')
		i += 1;
	if (lim[7] && lim[2] && !lim[4] && lim[0] > (lim[1] + lim[7] + 6 + qted))
		ft_putchar('-');
	if (lim[6] && lim[2] && !lim[4] && lim[0] > (lim[1] + lim[7] + 6 + qted))
	{
		ft_putchar('0');
		ft_putchar(str[i] + 23);
	}
	while (!lim[4] && lim[0] > (lim[1] + lim[7] + 5 + qted))
	{
		lim[2] ? ft_putchar('0') : ft_putchar(' ');
		printed++;
		lim[0]--;
	}
	lim[7] && !lim[4] && !lim[2] ? ft_putchar('-') : 0;
	if (lim[6] && !lim[4] && !lim[2])
	{
		ft_putchar('0');
		ft_putchar(str[i] + 23);
	}
	return (printed);
}

int		*setuphha(int *hh, int *lim, long double vl)
{
	int			j;
	long double	vl2;

	lim[6] = 1;
	vl2 = vl;
	j = -1;
	hh[lim[1] + 1] = 0;
	hh[lim[1] + 2] = -1;
	while (vl2 >= 2.0)
	{
		vl2 = vl;
		vl2 = vl2 / (double)ft_tento(2, ++hh[lim[1] + 2]);
	}
	hh[lim[1]] = (int)vl2;
	vl2 = vl2 - hh[lim[1]];
	while (++j < lim[1])
	{
		vl2 *= 16.0;
		hh[j] = (int)vl2;
		vl2 -= (int)hh[j];
		hh[lim[1] + 1] = (int)(vl2 * 16.0);
	}
	return (hh);
}

char	*setupresa(char *res, int *lim, int *hh)
{
	int	jj;
	int	j;

	jj = 0;
	j = -1;
	res[jj++] = hh[lim[1]] < 10 ? hh[lim[1]] + '0' : hh[lim[1]] + 'W';
	res[jj++] = lim[8] && !lim[1] ? '\0' : '.';
	jj -= lim[8] && !lim[1] ? 1 : 0;
	while (++j < lim[1])
		res[jj + j] = hh[j] < 10 ? hh[j] + '0' : hh[j] + 'W';
	jj = jj + j;
	res[jj++] = 'p';
	res[jj++] = '+';
	j = ft_qtenb(hh[lim[1] + 2], 'd', 10, 50);
	while (j > 0)
	{
		res[jj + --j] = (hh[lim[1] + 2] % 10) + '0';
		hh[lim[1] + 2] /= 10;
	}
	if (hh[lim[1] + 1] > 7 && res[lim[1] + 1] != 'f')
		res[lim[1] + 1] += res[lim[1] + 1] != '9' ? 1 : 40;
	else if (hh[lim[1] + 1] > 7 && res[lim[1] + 1] == 'f')
		roundedf(res, (int)(lim[1] + 1));
	return (res);
}

int		formatresaftera(char *str, char *res, int printed, int *lim)
{
	int	i;

	i = 0;
	while (str[i] != 'a' && str[i] != 'A')
		i += 1;
	str[i] == 'A' ? hexatoupper(res, 'u') : 0;
	printed += (int)ft_strlen(res);
	if (lim[6] && lim[4])
	{
		ft_putchar('0');
		ft_putchar(str[i] + 23);
	}
	ft_putstr(res);
	while (lim[4] && lim[0] > (lim[1] + lim[7] + 5))
	{
		ft_putchar(' ');
		printed++;
		lim[0]--;
	}
	return (printed);
}

int		pourcenta(va_list args, char *str, int *lim, int *i)
{
	int			*hh;
	int			j;
	long double vl;
	char		*res;
	int			printed;

	vl = islon(str, *i, 'a') ? va_arg(args, long double) : va_arg(args, double);
	lim[7] = vl < 0 ? 1 : lim[7];
	vl = vl < 0 ? -vl : vl;
	lim[1] = !lim[1] && !lim[8] ? 13 : lim[1];
	if (!(hh = (int*)malloc(sizeof(int) * (lim[1] + 4))))
		return (0);
	hh = setuphha(hh, lim, vl);
	j = hh[lim[1] + 2];
	printed = printbeforea(str, *i, lim, ft_qtenb(hh[lim[1] + 2], 'd', 10, 50));
	res = ft_strnew(lim[7] + 4 + lim[1] + 4 + 15);
	res = setupresa(res, lim, hh);
	lim[1] = lim[1] + ft_qtenb(j, 'd', 10, 50);
	printed = formatresaftera(str + *i, res, printed, lim);
	printed += lim[7] + 2;
	free(res);
	free(lim);
	free(hh);
	return (printed);
}
