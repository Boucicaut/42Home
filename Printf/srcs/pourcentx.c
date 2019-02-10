/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcentx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:50:02 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/10 15:09:09 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	hexatolower(char *res)
{
	int					j;

	j = 0;
	while (res[j])
	{
		res[j] = ft_tolower(res[j]);
		j++;
	}
}

void	hexaprintall(int j, int x, int *lim, char *res)
{
	int					jj;

	jj = j;
	lim[1] = lim[1] > 0 ? lim[1] : jj;
	if (lim[4])
	{
		lim[5] == 1 ? ft_putchar(' ') : 0;
		lim[3] == 1 && *res != '-' ? ft_putchar('+') : 0;
		ft_putstr(res);
	}
	while (j++ + (lim[1] - jj) + lim[5] < lim[0] + (x * 2))
		lim[2] == 1 ? ft_putchar('0') : ft_putchar(' ');
	if (x == 1)
		ft_putstr("0x");
	while (lim[1]-- > jj)
		ft_putchar('0');
	if (!lim[4])
	{
		lim[5] == 1 ? ft_putchar(' ') : 0;
		lim[3] == 1 && *res != '-' > 0 ? ft_putchar('+') : 0;
		ft_putstr(res);
	}
}

char	*checkzero(char *str)
{
	int		j;
	char	*res;
	char	*tmp;

	tmp = str;
	j = 0;
	if (str[j] && str[j] != '0')
		return (str);
	res = ft_strnew(ft_strlen(str));
	while (str[j])
	{
		res[j] = str[j + 1];
		j++;
	}
	res[j] = '\0';
	free(tmp);
	return (res);
}

int		pourcentx2(char *res, int printed, char c, int *lim)
{
	if (printed && res[0] == '0')
		res[0] = '\0';
	printed = doshittythings(lim, res, 0, c);
	free(lim);
	free(res);
	return (printed);
}

int		pourcentx(va_list args, char *str, int *lim, int *i)
{
	int							j;
	unsigned long long int		nb;
	char						*res;
	int							printed;

	j = *i;
	printed = 0;
	nb = islon(str, *i, 'x') ? va_arg(args, unsigned long long int) :\
va_arg(args, unsigned int);
	res = ft_convertbase(nb, 16);
	res = checkzero(res);
	res[0] && res[0] == '0' ? lim[6] = 0 : 0;
	while (str[j] && str[j] != 'x' && str[j] != 'X')
		j++;
	str[j] == 'x' ? hexatolower(res) : 0;
	*i = j;
	while (str[j] != '%')
	{
		if (str[j--] == '.')
		{
			printed = 1;
			lim[2] = 0;
		}
	}
	return (pourcentx2(res, printed, str[*i], lim));
}
