#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Libft/libft.h"

char	*ft_strrev(char *str)
{
	int	i;
	int	len;
	char	*strev;

	i = 0;
	len = ft_strlen(str) - 1;
	strev = ft_strnew(len);
	while (str[i])
	{
		strev[len] = str[i];
		len--;
		i++;
	}
	return (strev);
}
	

int	main(int argc, char **argv)
{
	double	nb = atof(argv[1]);
	double	nb2;
	int64_t	*rep;
	int64_t	r;
	int		i;
	int		j;
	char	*str;

// 23bits mantisse	8 exposant		1 signe	< single
// 52bits mantisse	11 exposant		1 signe	< double
	str = ft_strnew(64);
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
		str[j++] = (*rep & 0x01) + '0';
		*rep >>= 1;
	}
	str = ft_strrev(str);
	printf("%s", str);
printf("\n1100000100011011111011010010100010011110000110110010001101110010\n");	//-457546.1544004	
printf("\n11000001 00011011 11101101 00101000 10011110 00011011 00100011 01110010");	//-457546.1544004	
printf("\n01000000 00010001 10011001 10011001 10011001 10011001 10011001 10011010");	// 4
printf("\n11000000 00010001 10011001 10011001 10011001 10011001 10011001 10011010");	// -4

	(void)argc;
	return (0);
}
