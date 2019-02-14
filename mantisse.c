#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	double	nb = atof(argv[1]);
	double	nb2;
	int64_t	*rep;
	int64_t	r;
	int		i;
	int		j;
	char	str[70];

// 23bits mantisse	8 exposant		1 signe	< single
// 52bits mantisse	11 exposant		1 signe	< double
	j = 0;
	i = -1;
	r = 0;
	rep = &r;
	printf("Nb : %f\n", nb);
	printf("Sizeof Int64_t : %zu || Double : %zu\n", sizeof(int64_t), sizeof(double));
	memcpy((void*)rep, (void*)&nb, sizeof(double));
	memcpy((void*)&nb2, (void*)rep, sizeof(double));
	printf("Nb2 : %f\n", (double)nb2);
write(1, "\n", 1);
	while (++i < 64)
	{
		if (i % 8 == 0)
			str[j++] = ' ';
		str[j++] = (*rep & 0x01) + '0';
		*rep >>= 1;
	}
	j = (int)strlen(str) - 1;
	while (j)
		printf("%c", str[--j]);
printf("\n11000001 00011011 11101101 00101000 10011110 00011011 00100011 01110010\n");	//-457546.1544004	
printf("\n01000000 00010001 10011001 10011001 10011001 10011001 10011001 10011010");	// 4
printf("\n11000000 00010001 10011001 10011001 10011001 10011001 10011001 10011010");	// -4

	(void)argc;
	return (0);
}
