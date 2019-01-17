#include <stdio.h>
#include "includes/ft_printf.h"

int	main(void)
{
	int	i = 0;

printf("\n");
	//ft_printf("%#10.3x A\n", 42); // first print : lim3 lim0 lim2 
	printf("%#10.3o A\n", 2); // first print : lim3 lim0 lim2 
	printf("%#10.3x A\n", 42); // first print : lim3 lim0 lim2 
/*
printf("\n");
	ft_printf("%010.2o B\n", -42);
	printf("%010.2o B\n", -42);

printf("\n");
	ft_printf("%-10.2dd\n", -42);
	printf("%-10.2dd\n", -42);

printf("\n");
	ft_printf("%+10.2de\n", -42);
	printf("%+10.2de\n", -42);*/
(void)i;
	return (0);
}
