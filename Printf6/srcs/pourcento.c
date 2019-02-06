/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcento.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:46:43 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/04 15:09:56 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	octprintall(int j, int *lim, char *res)
{
	int						jj;

//printf("Lim : %d %d %d %d %d %d\n", lim[0], lim[1], lim[2], lim[3], lim[4], lim[5]);
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

int		pourcento(va_list args, char *str, int *lim, int *i)
{
	unsigned long long int	nb;
	char					*res;
	int						printed;

//printf("\nLim0 : %d, lim1 : %d, lim2 : %d, lim6 : %d\n", lim[0], lim[1], lim[2], lim[6]);
	printed = 0;
	nb = va_arg(args, unsigned long long int);
	res = ft_convertbase(nb, 8);
	if ((lim[6] || lim[0] || lim[1]) && res[0] == '0' && !res[1])
		res[0] = '\0';
	res = checkzero(res);
	while (str[*i] != '%')
	{
		if (str[*i] == '.')
		{
			lim[2] = 0;
			printed = 1;
		}
		*i = *i - 1;
	}
	res[0] = printed && res[0] == '0' && !lim[6] ? '\0' : res[0];
	lim[6] = !nb ? 0 : lim[6];
	printed = doshittythings(lim, res, 0, 'o');
	free(lim);
	free(res);
	return (printed);
}
