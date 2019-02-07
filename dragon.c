#include <stdio.h>
#include "includes/ft_printf.h"
#include <math.h>

int	frexptry(void)
{
	double vl;
	int	*exp = (int*)malloc(10);

	vl = 23.12345;

	printf("%f\n", vl);
	vl = frexp(vl,exp);
	printf("%f\n", vl);
printf("\n\n");

	printf("Exp : %d\n", *exp);
	printf("Exp : %d\n", *exp + 1);
	printf("Exp : %d\n", *exp + 2);
	return (0);
}

/*	AND &		OR |		^ XOR		~ complement		>> shift left  	<< shift right */	

int		add(int a, int b)
{
	if (b == 0)
		return (a);
	else
		return (add(a ^ b, (a & b) << 1));
}

int		sub(int a, int b)
{
	if (b == 0)
		return (a);
	else
		return (sub(a ^ b, (~a & b) << 1));
}

int		mul(int a, int b)
{
	int	res;
	res = 0;
	while (b > 0)
	{
		if (b & 0x1)
			res = add(res, a);
		a <<= 1;
		b >>= 1;
	}
	return (res);
}

int		divd(int a, int b)
{
	int	res;
	int	sign;

	sign = a < 0 ^ b < 0 ? -1 : 1;
	res = 0;
	a = ABSS(a);
	b = ABSS(b);
	while (a >= b)
	{
		res = add(res, 1);
		a = sub(a, b);
	}

	/*tmp = 0;
	int	i;
	int	tmp;
	i = 31;
	while ((i = sub(i,1)) > 0)
	{
printf("Tmp : %d, a : %d, b : %d, res : %d\n", tmp, a, b, res);
		if (tmp + (b << i) <= a)
		{
			tmp += b << i;
			res |= 1LL << i;
		}
	}*/
	return (sign < 0 ? -res : res);
}

int		mod(int a, int b)
{
	return (sub(a,mul(b, divd(a, b)))); 
}

/*
 * 0000
 * 0001
 * 0010
 * 0011
 * 0100 OK
 * 0101
 * 0110
 * 0111
 * 1000 OK
 * 1001
 * 1010
 * 1011
 * 1100 OK*/

void	printbits(long long int vl, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i++ < size)
	{
		vl & 0x1 ? write(1, "1", 1) : write(1, "0", 1);
		tmp = i;
		!mod(i, 4) ? write(1, " ", 1) : 0;
		vl >>= 1;
	}
}

int	main(void)
{
	printf("\n---------\n");
	printbits((int)4, sizeof(int) * 8);
	printf("\n---------\n");
	printf("Mod : %d\n\n", mod(8,4));
	printf("Mul : %d\n\n", mul(8,4));
	printf("Add : %d\n\n", add(10,1));
	printf("Div : %d\n\n", divd(8,4));
	printf("\n---------\n");
	printf("%d\n", sub(10,5));
	return (0);
}
