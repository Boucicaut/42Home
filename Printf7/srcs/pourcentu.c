/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcentu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:45:31 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/03 21:31:56 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	uprintall(char *res, int *tab, int qtenb)
{
	tab[1] = tab[1] > qtenb ? tab[1] : qtenb;
	if (tab[4])
	{
		tab[5] == 1 ? ft_putchar(' ') : 0;
		tab[3] == 1 && *res != '-' ? ft_putchar('+') : 0;
		ft_putstr(res);
	}
	while (tab[0]-- > tab[1] + tab[5])
		tab[2] == 1 ? ft_putchar('0') : ft_putchar(' ');
	while (tab[1]-- > qtenb)
		ft_putchar('0');
	if (!tab[4])
	{
		tab[5] == 1 ? ft_putchar(' ') : 0;
		tab[3] == 1 && *res != '-' ? ft_putchar('+') : 0;
		ft_putstr(res);
	}
}

void	fillcharu(unsigned long long int nb, char *str, int j)
{
	while (nb > 9)
	{
		str[j] = (nb % 10) + '0';
		nb = (nb - (nb % 10)) / 10;
		j--;
	}
	str[j] = (nb % 10) + '0';
}

int		pourcentu(va_list args, char *str, int *lim, int *i)
{
	int						j;
	unsigned long long int	nb;
	char					*res;
	int						qtenb;

	j = *i;
//printf("\nStr[%d] : |%s|\n", j, &(str[j]));
	nb = va_arg(args, unsigned long long int);
//printf("Nb : %llu\n", nb);
	nb = !(islongornot(str, *i, 'u')) && nb > 4294967295 ? 0 : nb;
	qtenb = nb == 0 ? 1 : ft_qtebignb(nb, 10);
//printf("Nb : %llu || qtenb : %dn", nb, qtenb);
//printf("Malloced a : %d\n", (int)(sizeof(char) * (qtenb + 1)));
	res = ft_strnew(qtenb);
	res[qtenb] = '\0';
//printf("Res : %s || Qtenb : %d\n", res, qtenb);
	if (qtenb > 1)
	{
		fillcharu(nb, res, qtenb - 1);
		res = checkzero(res);
	}
	else
		fillcharu(nb, res, 0);
	while (str[j] && str[j] != '.' && str[j] != '%')
		j--;
//printf("\nCHAR J : %c\n", str[j]);
//printf("Res charu : %s\n", res);
	/*if (str[j] == '.' && !lim[1] && nb == 0)
		res[0] = '\0';*/
	res[0] = str[j] == '.' && !lim[1] && nb == 0 ? '\0' : res[0]; // reduir eligne en haut
//printf("Res charu : %s\n", res);
	j = doshittythings(lim, res, 0, 'u'); // j = printed
//printf("Printed : %d\n", printed);
//printf("Lim : %d %d %d %d %d %d %d || Qtenb : %d || Res : %s || printed : %d\n", lim[0], lim[1], lim[2], lim[3], lim[4], lim[5], lim[6], qtenb, res, printed);
	//ft_putstr(res);
	free(res);
	free(lim);
	return (j);
}