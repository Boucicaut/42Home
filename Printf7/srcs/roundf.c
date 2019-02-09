/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roundf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:51:19 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/09 21:03:21 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		arrondi(long double vl, int max)
{
//printf("OO\n");
	while (max-- > 0)
		vl *= (long double)10;
	if (vl > (unsigned long long int)1000000000000000000)
		return (0);
	return ((unsigned long long int)vl % 10);
}

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
void	roundit(char *nbchar, int lim2, int z, int d, int arrondi)
{
	int	i;
	int	fullzero;

	fullzero = 1;
	i = 0;
//printf("Z : %d  ||   D : %d   ||  Lim2 : %d\n", z,d, lim2);
//printf("Nbchar : %s\n", nbchar);
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
	//if ((lim2 == 6 && z <= 6) || !ft_strchr(nbchar, '.'))
	if (nbchar[i] != '0' && lim2 < z && ((lim2 == 6 && z <= 6) || !ft_strchr(nbchar, '.')))
		return ;
//printf("i : %d - %c,  fullzero : %d\n", i,nbchar[i], fullzero);
	//if (i-- > 15)		// SI I PLUS DE 15 C'EST DU RANDOM DONC PAS D'ARRONDI ????????
	//	return ;
	if (nbchar[i] && !fullzero && lim2 < 16 && nbchar[i] == '9')
		roundednine(nbchar, i);
	//else if (nbchar[i] && nbchar[i] != '0' && z > lim2 && !fullzero && ((z + d < 16 && lim2 == 6) || (lim2 < z)))
	//NEW 08.02 enlever else if (z + d < 16 && nbchar[i] && nbchar[i] != '0' && nbchar[i] != '9' && !fullzero && (z > lim2 && nbchar[i] > '4'))
	else if (arrondi >= 5)
		nbchar[i]++;

	(void)d;
/* 				RAJOUTER UN compteur pour le nb de chiffre dans res apres la decimal et faire des trucs avec
 *  			exemple du 3.9999 (derniers tests maintest), ou z : 4 mais realz > 15 donc arrondi
 *  			*/




	//else if (nbchar[i] && !fullzero && z + d <= 16 && lim2 < z + d && lim2 != 6)
	//		nbchar[i]++;
	/*else if (nbchar[i] && !fullzero && lim2 == 6 && z > 6 && z < 15)
	{
		printf("222ICI\n");
			nbchar[i]++;
	}*/
	//else if (nbchar[i] && !fullzero && (i <= z + lim2 || lim2 < z))

/* PROBLEME ICI POUR LE CALCUL DE Z, ex z : 10 alors que z = 23, c'est dans qtenb lorsque vl*10 on perd la precision */
}

/*void	roundit(char *nbchar, int lim2, int z, int d)
{
	int	i;
	int	fullzero;

	fullzero = 1;
	i = 0;
printf("\nnbchar : %s, z : %d, lim2 : %d, i : %d\n", nbchar, z, lim2, i);
//printf("Nbchar : %s\n", nbchar);
	if (lim2 == 6 || !ft_strchr(nbchar, '.'))
		return ;
	while (nbchar[i])
		i++;
	i--;
	if (i > 15)		// SI I PLUS DE 15 C'EST DU RANDOM DONC PAS D'ARRONDI ????????
		return ;
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
printf("i : %d, fullzero : %d\n", i, fullzero);
}*/

int	*preqte(int *lim, char c, int neg, char *nb)
{
	int	*qtenb;

	if (!(qtenb = (int*)malloc(sizeof(int) * 2)))
		return (NULL);
	if (c == 'u' || /*c == 'd' ||*/ ft_issamealpha(c, 'x') || c == 'o' || neg)	//  ' ' si  u x o ou < 0
		lim[5] = 0;
	if (c == 'u' || ft_issamealpha(c, 'x') || c == 'o' || neg)	// ignore '+', ' ' si  u x o ou < 0
		lim[3] = 0;
	if ((c == 'p' || c == 's' || c == 'c'/* || lim[1]*/) && (c != 'f')) // ignore '0' si psc ou lim[1] prec. int
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
//printf("Qte returned pour c = %c, 0 : %d et 1 : : %d\n\n", c, qtenb[0], qtenb[1]);
	return (qtenb);
}
