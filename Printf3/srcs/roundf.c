/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roundf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:51:19 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/24 19:25:57 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	roundednine(char *str, int i)
{
	int	ii;

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

void	roundit(char *nbchar, int lim2, int z, int d)
{
	int	i;
	int	fullzero;

	fullzero = 1;
	i = 0;
	if (!ft_strchr(nbchar, '.'))
		return ;
	while (nbchar[i])
		i++;
	i--;
	if (i > 15)		// SI I PLUS DE 15 C'EST DU RANDOM DONC PAS D'ARRONDI ????????
		return ;
//printf("\nnbchar : %s, z : %d, lim2 : %d, i : %d\n", nbchar, z, lim2, i);
	if (nbchar[i] != '0')
		fullzero = 0;
	if (nbchar[i] && fullzero == 0 && d > 15)
		nbchar[i] = fullzero == 1 ? nbchar[i] : nbchar[i]++;
	else if (nbchar[i] && nbchar[i] == '9')
		roundednine(nbchar, i);
	//else if (fullzero == 0 && i > 14 && z > 15 && z+d >= 16 && z > 0 && lim2 < 16)
	//	nbchar[i]++;
	else if (nbchar[i] && fullzero == 0 && i <= z + lim2)
		nbchar[i]++;
}

int	*preqte(int *lim, char c, int neg, char *nb)
{
	int	*qtenb;

	if (!(qtenb = (int*)malloc(sizeof(int) * 2)))
		return (NULL);
	if (c == 'u' || /*c == 'd' ||*/ ft_issamealpha(c, 'x') || c == 'o' || neg)	//  ' ' si  u x o ou < 0
		lim[5] = 0;
	if (c == 'u' || ft_issamealpha(c, 'x') || c == 'o' || neg)	// ignore '+', ' ' si  u x o ou < 0
		lim[3] = 0;
	if ((c == 'p' || c == 's' || c == 'c' || lim[1]) && (c != 'f')) // ignore '0' si psc ou lim[1] prec. int
		lim[2] = 0;
	if (c == 'd' || c == 'i' || c == 'u' || c == 'c' || c == 's') // ignore '#' si diucs
		lim[6] = 0;

	// eliminer flag inutile sauf #, + et ' ' pour les ajouter a qte //

/*			CALCUL DE QTENB[1]		*/
	qtenb[1] = (int)ft_strlen(nb);
	if (c == 'f')
		qtenb[1] = (int)ft_strlen(ft_strchr(nb, '.')) - 1;
	qtenb[1] += c == 'o' ? lim[6] * 1 : 0;
	//qtenb[1] += c == 'o' || ft_issamealpha(c, 'x') ? lim[6] * 1 : 0;
	//qtenb[1] += ft_issamealpha(c, 'x') ? lim[6] * 1 : 0;
	//qtenb[1] = qtenb[1] > lim[1] ? qtenb[1] : lim[1];	// !! on perd qtenb si lim[1] superieur, a recalculer donc

/*			CALCUL DE QTENB[0]		*/
	qtenb[0] = c != 'f' && qtenb[1] > lim[1] ? qtenb[1] : lim[1];
	if (c == 'f')
		qtenb[0] = (int)ft_strlen(nb);// + 1 + lim[1] - ((int)ft_strlen(ft_strchr(res, '.'))); DEJA FAIT !
//printf("Qte0 : %d || Qte1 : %d\n", qtenb[0], qtenb[1]);
	qtenb[0] += neg ? 1 : 0;
	qtenb[0] += (lim[3] || lim[5]) ? 1 : 0;
	qtenb[0] += c == 'p'/*|| c == 'o'*/ || ft_issamealpha(c, 'x') ? lim[6] * 1 : 0;
	qtenb[0] += ft_issamealpha(c, 'x') ? lim[6] * 1 : 0;
	qtenb[0] += c == 'f' && lim[6] && qtenb[1] ? 1 : 0;
	return (qtenb);
}
