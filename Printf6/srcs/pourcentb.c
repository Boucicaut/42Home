/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcento.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:46:43 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/03 21:26:55 by bviollet         ###   ########.fr       */
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
