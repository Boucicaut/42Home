#include "../includes/ft_printf.h"

/* 
	lim[0] : width	|	lim[1] : precision	|	2: '0' | 3: '+' | 4: '-' | 5: ' ' | 6: '#' | 8: '.' lim1
*/


int		signandbase(char *res, int neg, int *lim, char c)
{
	int	i;

	i = 0;
	if (neg)
		res[i++] = '-';
	if (lim[3] && c != 's')	// si '+' ' ', print '+'
		res[i++] = '+';
	if (lim[5] && c != 's')	/* SPECIFIER LES % OU NON, exemple %s */
		res[i++] = ' ';
		return (i);
}

int		putend(char *res, int *lim, int *qtenb, char c)
{
	int	i;

	i = 0;
	if (c == 'f' && lim[6] && qtenb[1] <= 0)	// ajoute le '.' si 'f' et lim[6]
	{
		res[i++] = '.'; // !!! doit etre ajouter a qtenb[0] du coup !!
		qtenb[1]++;	 // du coup un nb[1] de plus
	}
	while (c == 'f' && lim[1] > (qtenb[1] < 0 ? 0 : qtenb[1]))	// lim[1] '0' si == 'f'
	{
		qtenb[1]++;
		res[i++] = '0';
	}
	while (lim[4] && lim[0] > qtenb[0])		// lim[0] >, print 0 ou ' ' APRES
	{
		qtenb[0]++;
		res[i++] = lim[2] ? '0' : ' ';
	}
	return (i);
}

int		putbeginning(char *res, int *lim, int *qtenb, char c)
{
	int	i;

	i = 0;
(void)res;
(void)lim;
(void)qtenb;
(void)c;
	return (i);
}

int		doshittythings(int *lim, char *nb, int neg, char c)
{
//printf("INITIAL Lim0 : %d || Lim1 : %d\n", lim[0], lim[1]);
	char	*res;
	int		*qtenb;
	int		i;
	int		b;

	b = 1;
	lim[7] = neg ? 1 : 0;
	qtenb = preqte(lim, c, neg, nb);
	if (c == 'f')
		res = ft_strnew(sizeof(char) * (lim[0] > qtenb[0] ? lim[0] : qtenb[0]));
	else
		res = ft_strnew(sizeof(char) * 1 + (1 + (qtenb[0] > lim[0] ? qtenb[0] : lim[0])));
	i = 0;

	if (lim[0] > qtenb[0] && !lim[4] && ((c == 'f' && lim[2]) || (lim[1] == 0 && lim[2] && !lim[8]) || (lim[2] && lim[1] < 0)))
	{
		i+=signandbase(res + i, lim[7], lim, c);
		b = 0;
	 }
//(!lim[4] && lim[0] > qtenb[0]) /*|| (!lim[4] && !lim[1] && !lim[8]) */|| (!lim[4] && lim[1] < 0) ? b = 0, i += signandbase(res + i, lim[7], lim, c) : 0;
//printf("Lim[0] : %d, lim[1] : %d, lim[2] : %d, lim[4] : %d, lim[8] : %d\n", lim[0], lim[1], lim[2], lim[4], lim[8]);
	while (!lim[4] && lim[0] > qtenb[0])		// lim[0] >, print 0 ou ' ' AVANT
	{
		qtenb[0]++;
		res[i++] = (c != 's') && ((c == 'f' && /*!lim[8] &&*/ lim[2]) || (lim[1] == 0 && lim[2] && !lim[8]) || (lim[2] && lim[1] < 0)) ? '0' : ' ';
		//res[i++] = (c != 's') && !lim[5] && ((c == 'f' && lim[2]) || (lim[1] < 0 && lim[2]) || (!lim[1] && !lim[8])) ? '0' : ' ';
	}
	i += b ? signandbase(res + i, lim[7], lim, c) : 0; /* lim[1] > 0  !!!! */

/* OX A PART DU SIGN AND BASE */
	if (lim[6] && (c == 'o' || ft_issamealpha(c, 'x')))	/* GERE LE 0x*/
		res[i++] = '0';
	if (lim[6] && ft_issamealpha(c, 'x'))
		res[i++] = c;
/********************************/
	while (c != 'f' && lim[1] > qtenb[1])	// lim[1] '0' si != 'f'
	{
		qtenb[1]++;
		res[i++] = lim[2] ? '0' : '0';
	}

//printf("'+' Res i : %d  == %s FIN\n",i, res);
//printf("Before lim[1]..  lim[1] : %d, qte : %d\n", lim[1], qtenb[1]);
//printf("'0' Res i : %d  == %s FIN\n",i, res);


	res = ft_strcat(res, nb);	// concatene les deux chaines
//printf("Current res : %s\n", res);
	i += ft_strlen(nb);

	i += putend(res + i, lim, qtenb, c);
	ft_putstr(res);
	i = (int)ft_strlen(res);
	free(qtenb);
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
//printf("\nStr[i] : %c , lim[2] : %d\n", str[*i], tab[2]);
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

	//tab = ft_memalloc(8);
	if (!(tab = (int*)malloc(sizeof(int) * 9)))
		return (NULL);
	ft_bzero(tab, sizeof(int) * 9);
//printf("Str before set flag : %c\n", str[*i]);
	tab = setflag(str, i, tab);
//printf("Str after set flag : %c\n", str[*i]);
//printf("\nAfter-Flag Tab : %d %d %d %d %d %d %d %d\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6], tab[7]);
//printf("\nStr : %s\n", str + *i); // on se situe sur le 1er %
	if (str[*i] == '*')
	{
		tab[0] = va_arg(args, int);
		tab[0] < 0 ? tab[0] = -tab[0], tab[4] = 1 : 0;
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
	{
		tab[8] = 1;
		*i += 1;
	}
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
