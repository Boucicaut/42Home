#include <stdio.h>
#include "includes/ft_printf.h"

int	main(void)
{
	int	i = 0;
	int tab[10] = {0};
	int	*tab2;

	tab2 = malloc(sizeof(int) * 10);

	printf("SIZEOF Tab(static) : %d\n", (int)sizeof(tab));
	printf("SIZEOF Tab(malloced) : %d\n", (int)sizeof(tab2));

printf("C : %c a\n", '\0');
printf("C : %sa\n", "abc\0d");
printf("C : %ca\n", 0);
printf("C : %-ca\n", 0);
printf("C : %5ca\n", 0);
printf("C : %-5ca\n", 0);
	/*
	printf("Res %s Qte : %d\n", ft_itoadouble((double)0.00000001,8, 80), (int)ft_strlen(ft_itoadouble((double)0.00000001,8, 80)));
	printf("Res %s Qte : %d\n", ft_itoadouble((double)0.00000001, 9, 80), (int)ft_strlen(ft_itoadouble((double)0.00000001, 9, 80)));
	printf("Res %s Qte : %d\n", ft_itoadouble((double)0.0000000, 3,80), (int)ft_strlen(ft_itoadouble((double)0.0000000, 3,80)));
	printf("Res %s Qte : %d\n", ft_itoadouble((double)0, 0,80), (int)ft_strlen(ft_itoadouble((double)0, 0,80)));
*/
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
