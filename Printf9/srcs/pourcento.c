/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcento.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:46:43 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/13 19:13:42 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				octprintall(int j, int *lim, char *res)
{
	int						jj;

	jj = j;
	lim[1] = lim[1] > 0 ? lim[1] : jj;
	if (lim[4])
	{
		lim[5] == 1 ? ft_putchar(' ') : 0;
		lim[3] == 1 && *res != '-' ? ft_putchar('+') : 0;
		ft_putstr(res);
	}
	while (j++ + (lim[1] - jj) + lim[5] < lim[0])
		lim[2] == 1 ? ft_putchar('0') : ft_putchar(' ');
	while (lim[1]-- - jj > 0)
		ft_putchar('0');
	if (!lim[4])
	{
		lim[5] == 1 ? ft_putchar(' ') : 0;
		lim[3] == 1 && *res != '-' ? ft_putchar('+') : 0;
		ft_putstr(res);
	}
}

unsigned long long	pourcento2(va_list args, char *str, int i)
{
	unsigned long long int	nb;
	int						nb2;
	long long int			nb3;

	if (str[i] == 'h')
	{
		nb2 = va_arg(args, int);
		nb = convunsigned(nb2);
	}
	else if (ft_issamealpha(str[i], 'o'))
	{
		nb3 = va_arg(args, long long int);
		nb = convunsigned(nb3);
	}
	else if (islon(str, i, 'o'))
		nb = va_arg(args, unsigned long long int);
	else
		nb = va_arg(args, unsigned int);
	return (nb);
}

int					pourcento(va_list args, char *str, int *lim, int *i)
{
	unsigned long long int	nb;
	char					*res;
	int						printed;

	nb = pourcento2(args, str, *i);
	printed = 0;
	res = ft_convertbase(nb, 8);
	if ((lim[6] || lim[0] || lim[1]) && res[0] == '0' && !res[1])
		res[0] = '\0';
	res = checkzero(res);
	while (str[*i] != '%')
	{
		if (str[*i] == '.')
			lim[2] = 0;
		if (str[*i] == '.')
			printed = 1;
		*i = *i - 1;
	}
	res[0] = printed && res[0] == '0' && !lim[6] ? '\0' : res[0];
	lim[6] = !nb ? 0 : lim[6];
	printed = doshittythings(lim, res, 0, 'o');
	free(lim);
	free(res);
	return (printed);
}
