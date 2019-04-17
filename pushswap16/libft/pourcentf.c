/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcentf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:45:39 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/13 19:32:54 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*setuplim(char *str, int *i, va_list args)
{
	int						*lim;

	if (!(lim = malloc(sizeof(int) * 2)))
		return (NULL);
	lim = setflag(str, i, lim);
	if (str[*i] == '*')
		lim[0] = va_arg(args, int);
	if (str[*i] && ft_isdigit(str[*i]))
		lim[0] = ft_atoi(&str[*i]);
	while (str[*i] && str[*i] != 'f')
	{
		if (str[*i] == '.')
		{
			*i = *i + 1;
			if (str[*i] == '*')
				break ;
			lim[1] = ft_atoi(&str[*i]);
		}
		*i = *i + 1;
	}
	if (str[*i] == '*')
		lim[1] = va_arg(args, int);
	if (lim[1] == 0)
		lim[1] = 6;
	return (lim);
}

void	fpall(int *lim, char *res, int d, int z)
{
	int						j;

	z = z > 0 ? z : 6;
	j = d;
	lim[1] = lim[1] > 0 ? lim[1] : 6;
	if (lim[4])
	{
		lim[5] == 1 ? ft_putchar(' ') : 0;
		lim[3] == 1 && *res != '-' ? ft_putchar('+') : 0;
		ft_putstr(res);
	}
	while (j++ + (lim[1]) + lim[5] < lim[0])
		lim[2] == 1 ? ft_putchar('0') : ft_putchar(' ');
	while (lim[1]-- > z)
		ft_putchar('0');
	if (!lim[4])
	{
		lim[5] == 1 ? ft_putchar(' ') : 0;
		lim[3] == 1 && *res != '-' > 0 ? ft_putchar('+') : 0;
		ft_putstr(res);
	}
}

int		islon(char *str, int i, char c)
{
	while (str[i])
	{
		if (ft_issamealpha(str[i], c))
			return (0);
		if (c == 'd' && ft_issamealpha(str[i], 'i'))
			return (0);
		if (ft_issamealpha(str[i], 'l'))
			return (1);
		if (ft_issamealpha(str[i], 'z'))
			return (1);
		if (ft_issamealpha(str[i], 'j'))
			return (1);
		i++;
	}
	return (0);
}

int		arrondii(long double vl, int lim)
{
	int						i;
	unsigned long long int	vl2;

	i = -1;
	vl2 = 0;
	while (i++ < lim)
	{
		vl2 = vl;
		vl *= (long double)10;
		vl2 *= 10;
		vl -= vl2;
	}
	return ((unsigned long long int)vl % 10);
}

int		pourcentf(va_list args, char *str, int *lim, int *i)
{
	int						j;
	long double				nb;
	char					*res;
	int						neg;
	int						printed;

	printed = 0;
	j = *i;
	while (str[*i] != '.' && str[*i] != '%')
		*i = *i - 1;
	lim[1] = lim[1] == 0 && str[*i] != '.' ? 6 : lim[1];
	lim[6] = str[*i] == '.' && str[*i + 1] == '0' ? lim[6] : 0;
	nb = islon(str, j, 'f') ? va_arg(args, long double) : va_arg(args, double);
	neg = nb < 0 ? 1 : 0;
	nb = neg == 1 ? -nb : nb;
	res = ft_itoadouble(nb, lim[1], 19);
	printed = arrondii(nb, lim[1]);
	if (res[(int)ft_strlen(res) - 1] == '.')
		res[(int)ft_strlen(res) - 1] = '\0';
	roundit(res, lim[1], ft_qtenb(nb, 'z', 10, 16), printed);
	printed = doshittythings(lim, res, neg, 'f');
	free(res);
	free(lim);
	return (printed);
}
