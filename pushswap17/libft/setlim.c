/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setflaglim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:03:50 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/10 19:31:52 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*setlim2(va_list args, char *str, int *i, int *tab)
{
	if (str[*i] == '*')
	{
		tab[0] = va_arg(args, int);
		if (tab[0] < 0)
		{
			tab[0] = -tab[0];
			tab[4] = 1;
		}
		*i += 1;
	}
	else
	{
		tab[0] = ft_atoi(&str[*i]);
		tab[0] != 0 ? *i += ft_qtenb(tab[0], 'd', 10, 10) : 0;
	}
	return (tab);
}

int		*setlim(char *str, int *i, va_list args)
{
	int	*tab;

	tab = setflag(str, i, (ft_memalloc(sizeof(int) * 9)));
	tab = setlim2(args, str, i, tab);
	if (str[*i] == '.')
	{
		tab[8] = 1;
		*i += 1;
	}
	if (str[*i] == '*')
	{
		tab[1] = va_arg(args, int);
		*i += 1;
	}
	else
	{
		tab[1] = ft_atoi(&str[*i]);
		tab[1] != 0 ? *i += ft_qtenb(tab[1], 'd', 10, 10) : 0;
	}
	return (tab);
}
