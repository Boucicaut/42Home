/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:13:02 by bviollet          #+#    #+#             */
/*   Updated: 2019/04/27 17:23:48 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	rotatea(t_piles *pile, int print)
{
	int	tmp;
	int	i;

	if (pile->asize < 2)
		return (0);
	if (print)
		ft_printf("ra\n");
	tmp = pile->a[0];
	i = 0;
	while (++i < pile->asize)
		pile->a[i - 1] = pile->a[i];
	pile->a[i - 1] = tmp;
	return (1);
}

int	rotateb(t_piles *pile, int print)
{
	int	tmp;
	int	i;

	if (pile->bsize < 2)
		return (0);
	if (print)
		ft_printf("rb\n");
	tmp = pile->b[0];
	i = 0;
	while (++i < pile->bsize)
		pile->b[i - 1] = pile->b[i];
	pile->b[i - 1] = tmp;
	return (1);
}

int	rotateab(t_piles *pile, int print)
{
	if (print)
		ft_printf("rr\n");
	rotatea(pile, 0);
	rotateb(pile, 0);
	return (0);
}

int	swapornot(t_piles *pile, int i)
{
	if ((pile->a[0] > pile->a[1] || pile->b[0] < pile->b[1]))
	{
		if (pile->asize > 1 && pile->bsize > 1\
		&& pile->a[0] > pile->a[1] && pile->b[0] < pile->b[1])
			swapab(pile, 1);
		else if (i && pile->asize > 1 && pile->a[0] > pile->a[1])
			swapa(pile, 1);
		else if (i && pile->bsize > 1 && pile->b[0] < pile->b[1])
			swapb(pile, 1);
		return (1);
	}
	return (0);
}

int	checkvalue(t_piles *pile)
{
	int	i;
	int	k;

	k = 0;
	i = -1;
	while (++i < pile->asize)
	{
		if (pile->a[i] < 0)
			k++;
	}
	return (k);
}
