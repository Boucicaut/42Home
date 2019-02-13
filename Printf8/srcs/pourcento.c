/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcento.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:46:43 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/12 21:44:28 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include <stdio.h>
void	octprintall(int j, int *lim, char *res)
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

int		ifoh(unsigned long long int nb, char *str, int i)
{
	nb = ~nb;
	if (str[i + 1] == 'h')
	{
		while (nb > 128)
			nb -= 128;
	}
	else
	{
		while (nb > 32000)
			nb -= 32000;
	}
	return (nb);
}

int		pourcento(va_list args, char *str, int *lim, int *i)
{
	unsigned long long int	nb;
	int						nb2;
	long long int			nb3;
	char					*res;
	int						printed;

	nb3 = 0;
	nb2 = 0;
	nb = 0;
	printed = 0;
//printf("Str[*I] : %s\n", str + *i);
	if (str[*i] == 'h')
	{
		nb2 = va_arg(args, int);
//printf("Nb2 va_arg : %d\n", nb2);
		nb = convunsigned(nb2);
	}
	else if (ft_issamealpha(str[*i], 'o'))
	{
		nb3 = va_arg(args, long long int);
//printf("Nb3 va_arg : %lld\n", nb3);
		nb = convunsigned(nb3);
	}
	else
		nb = va_arg(args, unsigned long long int);
//printf("Nb convsignchar : %llu\n", nb);
	res = ft_convertbase(nb, 8);
	if ((lim[6] || lim[0] || lim[1]) && res[0] == '0' && !res[1])
		res[0] = '\0';
	res = checkzero(res);
//printf("Res : %s || Nb : %lld || ~nb : %lld\n", res, nb, ~nb);
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
