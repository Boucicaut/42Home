/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcento.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:46:43 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/13 18:47:32 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		pourcentb(va_list args, char *str, int *lim, int *i)
{
	int						j;
	unsigned long long int	nb;
	char					*res;
	int						printed;

	printed = 0;
	j = *i;
	nb = va_arg(args, unsigned long long int);
	res = ft_convertbase(nb, 2);
	res = checkzero(res);
	*i = j;
	printed = doshittythings(lim, res, 0, 'o');
	free(lim);
	free(res);
	(void)str;
	return (printed);
}

int		pourcentpourcent(va_list args, char *str, int *lim, int *i)
{
	int	printed;

	printed = 0;
	while (!lim[4] && lim[0]-- > 1)
	{
		printed++;
		lim[2] ? ft_putchar('0') : ft_putchar(' ');
	}
	ft_putchar('%');
	while (lim[4] && lim[0]-- > 1)
	{
		printed++;
		lim[2] ? ft_putchar('0') : ft_putchar(' ');
	}
	free(lim);
	(void)args;
	(void)str[*i];
	return (printed + 1);
}
