/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusherror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:19:25 by bviollet          #+#    #+#             */
/*   Updated: 2019/04/28 15:20:52 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	pusherror(char **s, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < (int)ft_strlen(s[i]))
		{
			while (s[i][j] && s[i][j] == ' ')
				j++;
			if ((strmaxint(s[i])) || (s[i][j] == '-' && ((s[i][j + 1]\
			&& s[i][j + 1] == '-') || !s[i][j + 1] || s[i][j + 1] == ' '))\
			|| (s[i][j] >= '0' && s[i][j] <= '9' && s[i][j + 1]\
			&& s[i][j + 1] == '-'))
				return (1);
			if (s[i][j] && s[i][j] != '-' && (s[i][j] < '0' || s[i][j] > '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	doublonerror(t_piles *pile)
{
	int	i;
	int	j;

	i = -1;
	while (++i < pile->asize)
	{
		j = i;
		while (++j < pile->asize)
			if (pile->a[i] == pile->a[j])
				return (1);
	}
	return (0);
}
