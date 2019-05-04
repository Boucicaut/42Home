/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:29:18 by bviollet          #+#    #+#             */
/*   Updated: 2019/05/04 19:09:13 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		printtab(t_piles *pile)
{
	int		i;
	int		j;

	j = pile->bsize - 1;
	i = pile->asize - 1;
	ft_printf("\t\t    |A|\t\t\t|B|\n");
	while (i >= 0 || j >= 0)
	{
		if (j >= 0 && i >= 0)
			ft_printf("\t[%2d] :\t ||  %2d  ||\t\t||  %2d  ||\n"\
			, i, pile->a[i], pile->b[j]);
		else if (i >= 0)
			ft_printf("\t[%2d] :\t ||  %2d  ||\n", i, pile->a[i]);
		else if (j >= 0)
			ft_printf("\t[%2d] :\t\t\t\t||  %2d  ||\n", j, pile->b[j]);
		i--;
		j--;
	}
	return (0);
}

t_piles	*inittabs(int argc, char **argv, int k)
{
	int		i;
	int		j;
	t_piles	*pile;

	if (!(pile = (t_piles*)malloc(sizeof(t_piles))))
		exit(1);
	i = 0;
	while (i++ < argc)
	{
		j = 0;
		while (j < (int)ft_strlen(argv[i]))
		{
			if (argv[i][j] && (argv[i][j] == '-' || ft_isdigit(argv[i][j])))
				k++;
			while (argv[i][j] && (argv[i][j] == '-' || ft_isdigit(argv[i][j])))
				j++;
			while (argv[i][j] && (argv[i][j] == ' '))
				j++;
		}
	}
	if (!(pile->a = (int*)malloc(sizeof(int) * (k))))
		exit(1);
	if (!(pile->b = (int*)malloc(sizeof(int) * (k))))
		exit(1);
	return (inittabs2(k, argv, argc, pile));
}

t_piles	*inittabs2(int k, char **argv, int argc, t_piles *pile)
{
	int	i;
	int	j;

	pile->a = ft_memset(pile->a, 0, (sizeof(int) * (k)));
	pile->b = ft_memset(pile->b, 0, (sizeof(int) * (k)));
	pile->asize = k;
	pile->bsize = 0;
	i = 0;
	k = 0;
	while (++i < argc)
	{
		j = 0;
		while (j < (int)ft_strlen(argv[i]))
		{
			while (argv[i][j] && (argv[i][j] == ' '))
				j++;
			if (argv[i][j] && (argv[i][j] == '-' || ft_isdigit(argv[i][j])))
				pile->a[k++] = ft_atoi(&argv[i][j++]);
			while (argv[i][j] && (argv[i][j] == '-' || ft_isdigit(argv[i][j])))
				j++;
		}
	}
	return (pile);
}

int		issorted(t_piles *pile, int w)
{
	int	i;
	int	j;

	i = -1;
	if (w == 0 && pile->asize)
	{
		j = pile->a[0];
		while (++i < pile->asize)
		{
			if (j > pile->a[i])
				return (0);
			j = pile->a[i];
		}
	}
	else if (w == 1 && pile->bsize)
	{
		j = pile->b[0];
		while (++i < pile->bsize)
		{
			if (j < pile->b[i])
				return (0);
			j = pile->b[i];
		}
	}
	return (1);
}
