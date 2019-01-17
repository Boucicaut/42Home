#include "../includes/ft_printf.h"

/* 
	lim[0] : width	|	lim[1] : precision	|	2: '0' | 3: '+' | 4: '-' | 5: ' ' | 6: '#'
*/
int		doshittythings(int *lim, char *nb, int neg, char c)
{
//printf("INITIAL Lim0 : %d || Lim1 : %d\n", lim[0], lim[1]);
	char	*res;
	int		qtenb[2];
	int		i;

	if (c == 'u' || c == 'd' || ft_issamealpha(c, 'x') || c == 'o' || neg)	// ignore '+', ' ' si  u x o ou < 0
		lim[5] = 0;
	if (c == 'u' || ft_issamealpha(c, 'x') || c == 'o' || neg)	// ignore '+', ' ' si  u x o ou < 0
		lim[3] = 0;
	if (c == 'p' || c == 's' || c == 'c' || lim[1]) // ignore '0' si psc ou lim[1] prec. int
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
		qtenb[0] = (int)ft_strlen(res);// + 1 + lim[1] - ((int)ft_strlen(ft_strchr(res, '.'))); DEJA FAIT !
//printf("Qte0 : %d || Qte1 : %d\n", qtenb[0], qtenb[1]);
	qtenb[0] += neg ? 1 : 0;
	qtenb[0] += (lim[3] || lim[5]) ? 1 : 0;
	qtenb[0] += c == 'p'/*|| c == 'o'*/ || ft_issamealpha(c, 'x') ? lim[6] * 1 : 0;
	qtenb[0] += ft_issamealpha(c, 'x') ? lim[6] * 1 : 0;
	qtenb[0] += c == 'f' && lim[6] && qtenb[1] ? 1 : 0;

//printf("Qte0 : %d || Qte1 : %d\n", qtenb[0], qtenb[1]);
//printf("Lim0 : %d || Lim1 : %d\n", lim[0], lim[1]);
//printf("Nb : %s\n", nb);
/* a priori qtenb ne compte pas le signe ni 0x ? */
//printf("Size malloced : Qte %d ou Lim %d\n", qtenb[0], lim[0]);
	if (c == 'f')
		res = ft_strnew(sizeof(char) * (lim[0] > qtenb[0] ? lim[0] : qtenb[0]));
	else
		res = ft_strnew(sizeof(char) * 1 + (1 + (qtenb[0] > lim[0] ? qtenb[0] : lim[0])));
	i = 0;

	while (!lim[2] && !lim[4] && lim[0] > qtenb[0])		// lim[0] >, print 0 ou ' ' AVANT
	{
		qtenb[0]++;
		res[i++] = lim[2] ? '0' : ' ';
	}

	if (lim[6] && (c == 'o' || ft_issamealpha(c, 'x') || c == 'p')) // Si ' ' avant 
		res[i++] = '0';
	if (lim[6] && (c == 'x' || c == 'p'))
		res[i++] = 'x';
	if (lim[6] && c == 'X')
		res[i++] = 'X';

	while (lim[2] && !lim[4] && lim[0] > qtenb[0])		// lim[0] >, print 0 ou ' ' AVANT
	{
		qtenb[0]++;
		res[i++] = lim[2] ? '0' : ' ';
	}

	if (neg)
		res[i++] = '-';
//printf("'-' Res i : %d  == %s FIN\n",i, res);
	if (lim[3] || lim[5])	// si '+' ' ', print '+'
		res[i++] = '+';
//printf("'+' Res i : %d  == %s FIN\n",i, res);
//printf("Before lim[1]..  lim[1] : %d, qte : %d\n", lim[1], qtenb[1]);
	while (c != 'f' && lim[1] > qtenb[1])	// lim[1] '0' si != 'f'
	{
		qtenb[1]++;
		res[i++] = '0';
	}
//printf("'0' Res i : %d  == %s FIN\n",i, res);


	res = ft_strcat(res, nb);	// concatene les deux chaines
	i += ft_strlen(nb);
//printf("STRCAT Res i : %d  == %s FIN\n",i, res);

	if (c == 'f' && lim[6] && qtenb[1] < 0)	// ajoute le '.' si 'f' et lim[6]
		res[i++] = '.'; // !!! doit etre ajouter a qtenb[0] du coup !!
	while (c == 'f' && lim[1] > qtenb[1])	// lim[1] '0' si == 'f'
	{
		qtenb[1]++;
		res[i++] = '0';
	}

//printf("Res intermediate : %s FIN\n", res);
//printf("lim[2] : %d || lim[4] : %d ||   lim[0] : %d, qte[0] : %d\n", lim[2], lim[4], lim[0], qtenb[0]);
	while (lim[4] && lim[0] > qtenb[0])		// lim[0] >, print 0 ou ' ' APRES
	{
//printf("Res intermediate : %s FIN\n", res);
		qtenb[0]++;
		res[i++] = lim[2] ? '0' : ' ';
	}
	ft_putstr(res);
	i = (int)ft_strlen(res);
	free(res);
	return (i);
//	qtenb = c == 'f' ? ft_strlen(ft_strchr(nb, '.')) : ft_strlen(nb); // concerne 'f' et lim[1]
}

int		*setflag(char *str, int *i, int *tab)
{
	//*i -= 1;
	while (str[*i] && (str[*i] == '0' || str[*i] == '+' || str[*i] == '-' ||
str[*i] == ' ' || str[*i] == '#'))
	{
		//i += 1;
		str[*i] == '0' /*&& !ft_isdigit(str[*i + 1])*/ ? tab[2] = 1, *i += 1 : 0;
		str[*i] == '+' ? tab[3] = 1, *i += 1 : 0;
		str[*i] == '-' ? tab[4] = 1, *i += 1 : 0;
		str[*i] == ' ' ? tab[5] = 1, *i += 1 : 0;
		str[*i] == '#' ? tab[6] = 1, *i += 1 : 0;
	}
/*	tab [2] == '0' || tab[3] == '+' || tab[4] == '-' || tab[5] == ' ' || tab[6] == '#'	*/

	tab[5] = tab[5] == 1 && tab[3] == 1 ? 0 : tab[5];
	tab[2] = tab[4] == 1 && tab[2] == 1 ? 0 : tab[2]; // Prends le dessus ? Flag '0' ou '-' ??
//printf("\nTab : %d %d %d %d %d %d %d\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6]);
	return (tab);
}

int		*setlim(char *str, int *i, va_list args)
{
	int	*tab;

	if (!(tab = (int*)malloc(sizeof(int) * 7)))
		return (NULL);
	ft_bzero(tab, sizeof(int) * 7);
	tab = setflag(str, i, tab);
//printf("\nAfter-Flag Tab : %d %d %d %d %d %d %d\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6]);
//printf("\nStr : %s\n", str + *i); // on se situe sur le 1er %
	if (str[*i] == '*')
	{
		tab[0] = va_arg(args, int);
		*i += 1;
	}
	else
	{
//printf("Actuel STR[i] : %s\n", &str[*i]);
		tab[0] = ft_atoi(&str[*i]);
		tab[0] != 0 ? *i += ft_qtenb(tab[0], 'd', 10, 10) : 0;
//printf("Tab[0] : %d et Qte : %d\n", tab[0], ft_qtenb(tab[0], 'd', 10, 10));
	}
	if (str[*i] == '.')
		*i += 1;
	if (str[*i] == '*')
	{
//printf("Actuel STR[i] : %s\n", &str[*i]);
		tab[1] = va_arg(args, int);
		*i += 1;
	}
	else
	{
		tab[1] = ft_atoi(&str[*i]);
		tab[1] != 0 ? *i += ft_qtenb(tab[1], 'd', 10, 10) : 0;
	}
//printf("\nAfter-Lim Tab : %d %d\n", tab[0], tab[1]);
//printf("tab %d %d %d %d %d %d %d \n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6]);
	return (tab);
}
