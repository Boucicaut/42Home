/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcento.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:46:43 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/24 19:24:54 by bviollet         ###   ########.fr       */
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
	//if ((lim[6] || lim[0] || lim[1]) && res[0] == '0' && !res[1])
	//	res[0] = '\0';
	res = checkzero(res);
	//lim[6] == 1 ? lim[0] -= 1, lim[1] -= 1 : 0;
	*i = j;
	/*while (str[j] != '%')
	{
		if (str[j--] == '.')
			printed = 1;
	}
	if (printed && res[0] == '0')
		res[0] = '\0';
*/
	printed = doshittythings(lim, res, 0, 'o');
	//	lim[6] == 1 ? ft_putchar('0') : 0;
	//ft_putstr(res);
	free(lim);
	free(res);
	(void)str;
	return (printed);
/*	while (str[*i] == '.' || str[*i] == '*' || ft_isdigit(str[*i]))
		*i = *i + 1;
	if (str[*i] == 'l')
	{
		*i = j;
		pourcentoll(args, str, lim, i);
	}
	else
	{
		*i = j;
		pourcentonoll(args, str, lim, i);
	}*/
}
