/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcentp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:50:19 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/21 18:46:11 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pprintall(int j, int *lim)
{
	int	jj;

	jj = lim[1] > j ? lim[1] : j;
	while (lim[0]-- - 1 > jj)
		ft_putchar(' ');
}

int		pourcentp(va_list args, char *str, int *lim, int *i)
{
	long	*nb;
	int		j;
	char	*res;
	char	*tmp;
	int		printed;

	res = ft_strnew(15);
	j = 0;
	nb = va_arg(args, void*);
	res = ft_strcpy(res, "0x");
	tmp = ft_convertbase((long)(nb), 16);
	res = ft_strcat(res, tmp);
	free(tmp);
	while (res[j])
	{
		res[j] = ft_tolower(res[j]);
		j++;
	}
	printed = doshittythings(lim, res, 0, 'p');
	//pprintall(j, lim);
	//ft_putstr("0x");
	//ft_putstr(res);
	/*while (str[*i] != 'p')
		*i = *i + 1;
	*i = *i + 1;*/
	free(res);
	free(lim);
	(void)str;
	(void)i;
	return (printed);
}
