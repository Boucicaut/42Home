/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:21:59 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/10 18:30:49 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_matchpat	*initmatchpat2(t_matchpat *tab)
{
	tab[10].pattern = 'b';
	tab[10].f = &pourcentb;
	tab[11].pattern = 'a';
	tab[11].f = &pourcenta;
	return (tab);
}

t_matchpat	*initmatchpat(void)
{
	t_matchpat	*tab;

	if (!(tab = malloc(sizeof(t_matchpat) * MAXPOURCENT + 2)))
		return (NULL);
	tab[0].pattern = 'd';
	tab[0].f = &pourcentd;
	tab[2].pattern = 'i';
	tab[2].f = &pourcentd;
	tab[6].pattern = 'o';
	tab[6].f = &pourcento;
	tab[7].pattern = 'u';
	tab[7].f = &pourcentu;
	tab[5].pattern = 'x';
	tab[5].f = &pourcentx;
	tab[1].pattern = 'f';
	tab[1].f = &pourcentf;
	tab[3].pattern = 's';
	tab[3].f = &pourcents;
	tab[4].pattern = 'c';
	tab[4].f = &pourcentc;
	tab[8].pattern = 'p';
	tab[8].f = &pourcentp;
	tab[9].pattern = '%';
	tab[9].f = &pourcentpourcent;
	return (initmatchpat2(tab));
}
