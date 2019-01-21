/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcento.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:46:43 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/21 18:16:25 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	octprintall(int j, int *lim, char *res)
{
	int						jj;

//printf("Lim : %d %d %d %d %d %d\n", lim[0], lim[1], lim[2], lim[3], lim[4], lim[5]);
	jj = j;
	lim[1] = lim[1] > 0 ? lim[1] : jj;
	if (lim[4])
	{
		lim[5] == 1 ? ft_putchar(' ') : 0;
		lim[3] == 1 && *res != '-' ? ft_putchar('+') : 0;
		ft_putstr(res);
	}
	while (j++ + (lim[1] - jj) + lim[5] < lim[0])
		lim[2] == 1 ? ft_putchar('0') : ft_putchar(' ');
	while (lim[1]-- - jj > 0)
		ft_putchar('0');
	if (!lim[4])
	{
		lim[5] == 1 ? ft_putchar(' ') : 0;
		lim[3] == 1 && *res != '-' ? ft_putchar('+') : 0;
		ft_putstr(res);
	}
}

void	pourcentonoll(va_list args, char *str, int *tab, int *i)
{
	int						nb;
	char					*res;
	int						j;

	j = *i;
	nb = va_arg(args, int);
	res = ft_convertbase(nb, 8);
	j++;
	while (str[j] && (ft_isdigit(str[j]) || str[j] == '.'))
		j++;
	octprintall(ft_qtenb(nb, 'd', 8, 16), tab, res);
}

void	pourcentoll(va_list args, char *str, int *tab, int *i)
{
	unsigned long long int	nb;
	char					*res;
	int						j;

	j = *i;
	nb = va_arg(args, unsigned long long int);
	res = ft_convertbase(nb, 8);
	j++;
	while (str[j] && (ft_isdigit(str[j]) || str[j] == '.'))
		j++;
	octprintall(ft_qtebignb(nb, 8), tab, res);
}

int		pourcento(va_list args, char *str, int *lim, int *i)
{
	int						j;
	unsigned long long int	nb;
	char					*res;
	int						printed;

	printed = 0;
	j = *i;
	nb = va_arg(args, unsigned long long int);
	res = ft_convertbase(nb, 8);
	if ((lim[6] || lim[0] || lim[1]) && res[0] == '0' && !res[1])
		res[0] = '\0';
	res = checkzero(res);
	//lim[6] == 1 ? lim[0] -= 1, lim[1] -= 1 : 0;
	*i = j;
	while (str[j] != '%')
	{
		if (str[j--] == '.')
			printed = 1;
	}
	if (printed && res[0] == '0')
		res[0] = '\0';

	printed = doshittythings(lim, res, 0, 'o');
	//	lim[6] == 1 ? ft_putchar('0') : 0;
	//ft_putstr(res);
	free(lim);
	free(res);
	return (printed);
/*	while (str[*i] == '.' || str[*i] == '*' || ft_isdigit(str[*i]))
		*i = *i + 1;
	if (str[*i] == 'l')
	{
		*i = j;
		pourcentoll(args, str, lim, i);
	}
	else
	{
		*i = j;
		pourcentonoll(args, str, lim, i);
	}*/
}
