/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcentp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:50:19 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/03 21:15:27 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (!res[4] && res[2] == '0' && res[3] == '0')
		res[3] = '\0';
	free(tmp);
	while (res[j])
	{
		res[j] = ft_tolower(res[j]);
		j++;
	}
	printed = doshittythings(lim, res, 0, 'p');
	free(res);
	free(lim);
	(void)str[*i];
	return (printed);
}
