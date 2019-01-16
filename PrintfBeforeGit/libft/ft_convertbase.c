/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:16:45 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/14 20:13:27 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_convertbase(long long unsigned int nb, int base)
{
	int		i;
	char	*stres;

	i = 0;
	i = ft_qtebignb(nb, base);
	stres = ft_strnew(i);
	while (i-- >= 0)
	{
		stres[i] = (nb % base) + (nb % base > 9 ? 'A' - 10 : '0');
		nb = nb / base;
	}
	return (stres);
}
