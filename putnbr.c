#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nbr)
{
	if (nbr == (-2147483648))
	{
		ft_putchar('-');
		ft_putchar(2);
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr < 9)
		ft_putchar(nbr + '0');
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

int main(void) 
{
	int nbr;
	nbr = -4587962;
	ft_putnbr(nbr);
	return (0);
}
