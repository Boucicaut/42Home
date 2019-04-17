/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:34:43 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/13 21:18:35 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putbignbr(long long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n <= 9)
		ft_putchar(n + '0');
	if (n > 9)
	{
		ft_putbignbr(n / 10);
		ft_putbignbr(n % 10);
	}
}
