/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:10:02 by bviollet          #+#    #+#             */
/*   Updated: 2019/05/18 16:26:44 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_piles	*pile;
	char	*ins;

	if (pusherror(argv, argc))
		return (1);
	pile = inittabs(argc, argv, 0);
	if (pile->asize == 0 && pile->bsize == 0)
	{
		freechecker(NULL, pile);
		return (0);
	}
	if (doublonerror(pile))
	{
		ft_printf("Error\n");
		freechecker(NULL, pile);
		return (1);
	}
	ins = NULL;
	return (execute_ins(pile, ins));
}

int	execute_ins(t_piles *pile, char *ins)
{
	while (get_next_line(0, &ins, 0))
	{
		if (!ins || !ins[0])
		{
			ft_putstr_fd("Error\n", 2);
			freechecker((!ins ? NULL : ins), pile);
			return (1);
		}
		if (checkerope(ins, pile))
			return (1);
		free(ins);
		ins = NULL;
	}
	if (issorted(pile, 0) && pile->bsize == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	freechecker(NULL, pile);
	return (0);
}

int	checkerope(char *ins, t_piles *pile)
{
	if (!ft_strcmp("pa", ins))
		pusha(pile, 0);
	else if (!ft_strcmp("pb", ins))
		pushb(pile, 0);
	else if (!ft_strcmp("sa", ins))
		swapa(pile, 0);
	else if (!ft_strcmp("sb", ins))
		swapb(pile, 0);
	else if (!ft_strcmp("ss", ins))
		swapab(pile, 0);
	else if (!ft_strcmp("ra", ins))
		rotatea(pile, 0);
	else if (!ft_strcmp("rb", ins))
		rotateb(pile, 0);
	else if (!ft_strcmp("rr", ins))
		rotateab(pile, 0);
	else
		return (checkerope2(ins, pile));
	return (0);
}

int	checkerope2(char *ins, t_piles *pile)
{
	if (!ft_strcmp("rra", ins))
		revrotatea(pile, 0);
	else if (!ft_strcmp("rrb", ins))
		revrotateb(pile, 0);
	else if (!ft_strcmp("rrr", ins))
		revrotateab(pile, 0);
	else
	{
		ft_putstr_fd("Error\n", 2);
		freechecker(ins, pile);
		return (1);
	}
	return (0);
}

int	freechecker(char *ins, t_piles *pile)
{
	free(ins);
	free(pile->a);
	free(pile->b);
	free(pile);
	return (0);
}
