#include <stdio.h>

int	main(void)
{
	int	i = 3;

	printf("%+1.0d\n", 42);
	printf("%+10.0d\n", 42);
printf("\n");
	printf("%+10.0da\n", 42);
	printf("%010.2db\n", 42);
	printf("%010.2dc\n", 42);
	printf("%-10.2dd\n", 42);
	printf("%+10.2de\n", 42);
	printf("% 010.2df\n", 42);
printf("\n");
	printf("%#10.0f\n", (double)42);
	printf("%10.0f\n", (double)42);
printf("\n");
	printf("%p", &i);
	return (0);
}
