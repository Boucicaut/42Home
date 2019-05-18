/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparetests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:09:54 by bviollet          #+#    #+#             */
/*   Updated: 2019/04/27 17:15:49 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		smallest(t_piles *pile, int w)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (w == 0)
	{
		j = pile->a[0];
		while (++i < pile->asize)
			j = j > pile->a[i] ? pile->a[i] : j;
	}
	else if (w == 1)
	{
		j = pile->b[0];
		while (++i < pile->bsize)
			j = j > pile->b[i] ? pile->b[i] : j;
	}
	return (j);
}

int		biggest(t_piles *pile, int w)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (w == 0 && pile->asize)
	{
		j = pile->a[0];
		while (++i < pile->asize)
			j = j < pile->a[i] ? pile->a[i] : j;
	}
	else if (w == 1 && pile->bsize)
	{
		j = pile->b[0];
		while (++i < pile->bsize)
			j = j < pile->b[i] ? pile->b[i] : j;
	}
	return (j);
}

int		smallestsorted(t_piles *pile, int w)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (w == 0)
	{
		j = pile->a[0];
		while (i++ < pile->asize && j < pile->a[i])
			j = pile->a[i];
	}
	else if (w == 1)
	{
		i = pile->bsize - 1;
		j = pile->b[pile->bsize - 1];
		while (i-- < 0)
			j = pile->b[i];
	}
	return (j);
}
