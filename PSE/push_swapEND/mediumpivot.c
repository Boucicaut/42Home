/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediumpivot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:29:27 by bviollet          #+#    #+#             */
/*   Updated: 2019/04/27 17:29:28 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		mediumpivot(t_piles *pile, int w)
{
	int	j;
	int	bigsort;

	j = smallest(pile, 0);
	if (w == 0)
	{
		if (pile->a[pile->asize - 1] == biggest(pile, 0))
		{
			if (pile->asize + pile->bsize < 200)
				bigsort = (rang(pile, 0, biggestsorted(pile, 0)) / 1.5);
			else
				bigsort = (rang(pile, 0, biggestsorted(pile, 0)) / 1.2);
			j = biggestsorted(pile, 0);
		}
		else
		{
			bigsort = pile->asize / 2;
			j = biggest(pile, 0);
		}
		while (w++ < bigsort)
			j = biggestafter(pile, 0, j);
	}
	else if (w == 1)
		j = mediumpivotb(pile);
	return (j);
}

int		mediumpivotb(t_piles *pile)
{
	int	bigsort;
	int	j;
	int	i;

	j = 0;
	if (pile->b[pile->bsize - 1] == smallest(pile, 1))
	{
		if (pile->asize + pile->bsize < 200)
			bigsort = (rang(pile, 1, biggestsorted(pile, 1)) / 1.8);
		else
			bigsort = (rang(pile, 1, biggestsorted(pile, 1)) / 1.9);
		j = biggestsorted(pile, 1);
	}
	else
	{
		bigsort = pile->bsize / 2;
		j = smallest(pile, 1);
	}
	i = 0;
	while (i++ < bigsort)
		j = biggestafter(pile, 1, j);
	return (j);
}
