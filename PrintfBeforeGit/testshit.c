#include <stdio.h>

int	main(void)
{
	int	i = 3;

	printf("%-+10.3d A\n", -42); // first print : lim3 lim0 lim2 

	printf("%010.2o B\n", -42);

	printf("%-10.2dd\n", -42);
	printf("%+10.2de\n", -42);
	printf("% 010.2df\n", -42);
printf("\n");
	printf("%#10.0f\n", (double)-42);
	printf("%10.0f\n", (double)-42);
printf("\n");
	printf("%p", &i);
	return (0);
}
