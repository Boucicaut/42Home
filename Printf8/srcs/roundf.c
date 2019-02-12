/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roundf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:51:19 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/10 18:16:08 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		arrondi(long double vl, int max)
{
	while (max-- > 0)
		vl *= (long double)10;
	if (vl > (unsigned long long int)1000000000000000000)
		return (0);
	return ((unsigned long long int)vl % 10);
}

void	roundednine(char *str, int i)
{
	int		ii;

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

void	roundit(char *nbchar, int lim2, int z, int arrondi)
{
	int		i;
	int		fullzero;

	fullzero = 1;
	i = 0;
	while (nbchar[i] && nbchar[i] != '.')
		i++;
	i++;
	while (nbchar[i])
	{
		if (nbchar[i] != '.' && nbchar[i] != '0')
			fullzero = 0;
		i++;
	}
	i--;
	if (nbchar[i] != '0' && lim2 < z && ((lim2 == 6 && z <= 6) ||\
!ft_strchr(nbchar, '.')))
		return ;
	if (nbchar[i] && !fullzero && lim2 < 16 && nbchar[i] == '9' && arrondi >= 5)
		roundednine(nbchar, i);
	else if (arrondi >= 5)
		nbchar[i]++;
}

int		*preqte(int *lim, char c, int neg, char *nb)
{
	int		*qtenb;

	if (!(qtenb = (int*)malloc(sizeof(int) * 2)))
		return (NULL);
	if (c == 'u' || ft_issamealpha(c, 'x') || c == 'o' || neg)
		lim[5] = 0;
	if (c == 'u' || ft_issamealpha(c, 'x') || c == 'o' || neg)
		lim[3] = 0;
	if ((c == 'p' || c == 's' || c == 'c') && (c != 'f'))
		lim[2] = 0;
	if (c == 'd' || c == 'i' || c == 'u' || c == 'c' || c == 's')
		lim[6] = 0;
	qtenb[1] = (int)ft_strlen(nb);
	if (c == 'f')
		qtenb[1] = (int)ft_strlen(ft_strchr(nb, '.')) - 1;
	qtenb[1] += c == 'o' ? lim[6] * 1 : 0;
	qtenb[0] = c != 'f' && qtenb[1] > lim[1] ? qtenb[1] : lim[1];
	if (c == 'f')
		qtenb[0] = (int)ft_strlen(nb);
	qtenb[0] += neg ? 1 : 0;
	qtenb[0] += (lim[3] || lim[5]) ? 1 : 0;
	qtenb[0] += c == 'p' || ft_issamealpha(c, 'x') ? lim[6] * 1 : 0;
	qtenb[0] += ft_issamealpha(c, 'x') ? lim[6] * 1 : 0;
	qtenb[0] += c == 'f' && lim[6] && qtenb[1] ? 1 : 0;
	return (qtenb);
}
