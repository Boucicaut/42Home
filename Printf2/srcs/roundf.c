/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roundf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:51:19 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/20 21:37:44 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	roundednine(char *str, int i)
{
	int	ii;

	ii = i;
	while (str[i] != '.' && str[i] == '9')
	{
		str[i] = '0';
		i--;
	}
	if (str[i] == '.')
		i--;
	str[i]++;
}

void	roundit(char *nbchar, int lim2, int z, int d)
{
	int	i;
	int	fullzero;

	fullzero = 1;
	i = 0;
	if (!ft_strchr(nbchar, '.'))
		return ;
	while (nbchar[i])
		i++;
	i--;
//printf("\nnbchar : %s, z : %d, lim2 : %d, i : %d\n", nbchar, z, lim2, i);
	if (nbchar[i] != '0')
		fullzero = 0;
	if (nbchar[i] && fullzero == 0 && d > 15)
		nbchar[i] = fullzero == 1 ? nbchar[i] : nbchar[i]++;
	else if (nbchar[i] && nbchar[i] == '9')
		roundednine(nbchar, i);
	//else if (fullzero == 0 && i > 14 && z > 15 && z+d >= 16 && z > 0 && lim2 < 16)
	//	nbchar[i]++;
	else if (nbchar[i] && fullzero == 0 && i <= z + lim2)
		nbchar[i]++;
}
