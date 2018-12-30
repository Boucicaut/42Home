#include "libft.h"
#include <stdio.h>

double		ft_rounded(int i)
{
	double 	nb;
	int		j;

	j = 12;
	nb = 0;
	while (i-- >= 0 && j-- > 0)
	{
		nb = nb / 10 + 0.9;
	}
	return (nb);
}

char	*ft_itoadouble(double nb)
{
	char	*str;
	int		qte;
	int		dot;
	int		tmp;
	int		i;
	double	nb2;

	nb2 = nb;
	i = 0;
	dot = sizenbchar(10, 0, nb, 'z');
	qte = sizenbchar(10, 0, nb, 'f');
	if (!(str = malloc(sizeof(char) * qte + 2)))
		return (NULL);
	str[qte + 1] = '\0';
	str[qte - dot] = '.';
	i = qte - dot - 1;
printf("Qte : %d, dot : %d, i : %d\n", qte, dot, i);
	while (i >= 0)
	{
		tmp = nb;
		str[i] = (tmp % 10) + '0';
printf("() str[%d] : %c\n", i, str[i]);
		tmp = nb / 10;
printf("Tmp1 : %d\n", tmp);
printf("Nb : %f\n", nb);
		nb = tmp;
		i--;
	}

printf("\n\n");
	nb = nb2;
	i = qte - dot + 1;
	nb = nb * ft_tento(10, dot);
	nb = nb - (ft_atoi(str) * ft_tento(10, dot));
printf("Nb : %f\n", nb);
	i = qte;
	while (i > qte - dot)
	{
		tmp = nb;
		printf("ROUNDED : %f\n", ft_rounded(qte - 1));
		str[i] = ((int)(tmp + 1 - ft_rounded(qte - dot)) % 10) + '0';
printf("Tmp : %d\n", tmp);
printf("() str[%d] : %c\n", i, str[i]);
		tmp = nb / 10;
printf("Tmp : %d\n", tmp);
printf("Nb : %f\n", nb);
		nb = tmp;
		i--;
	}
printf("\n\n");
printf("str : %s, qte : %d, i : %d\n", str, qte, i);
	i = qte - dot - 1;

/*
	while (str[i] != '\0')
	{
printf("Str[%d] : %c\n", i, str[i]);
		if (str[i++] == '0')
			return (str);
	}
	str[qte] = str[qte] + 1;*/

	return (str);
}
/*
int	main(int argc, char **argv)
{
(void)argc;
	printf("S : %s\n", ft_itoadouble(atof(argv[1])));
	printf("Z : %s\n", argv[1]);
	return (0);
}*/
