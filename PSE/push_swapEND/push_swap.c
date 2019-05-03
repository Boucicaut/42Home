/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:30:06 by bviollet          #+#    #+#             */
/*   Updated: 2019/04/28 15:20:31 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_piles	*pile;
	int		i;

	i = 0;
	if (pusherror(argv, argc))
	{
		ft_printf("Error\n");
		return (1);
	}
	pile = inittabs(argc, argv, 0);
	if (doublonerror(pile))
		ft_printf("Error\n");
	else
		gestionrecursive(pile);
	free(pile->a);
	free(pile->b);
	free(pile);
	return (0);
}

int		gestionrecursive(t_piles *pile)
{
	while (!issorted(pile, 0) || !issorted(pile, 1))
	{
		if (pile->asize < 8)
			sortshortlist(pile);
		while (issorted(pile, 0) == 0)
			quicksort(pile, mediumpivot(pile, 0));
		if (!issorted(pile, 0) || !issorted(pile, 1))
			quicksort2(pile, mediumpivot(pile, 1));
		intermediaire(pile);
		swapornot(pile, 1);
	}
	while (pile->bsize)
	{
		swapornot(pile, 1);
		pusha(pile, 1);
	}
	return (0);
}

int		intermediaire(t_piles *pile)
{
	while (issorted(pile, 0) && ((pile->bsize\
	&& pile->b[0] == biggest(pile, 1))\
	|| (pile->bsize > 1 && pile->b[1] == biggest(pile, 1))))
	{
		swapornot(pile, 1);
		if (pile->b[0] == biggest(pile, 1))
			pusha(pile, 1);
	}
	return (0);
}
