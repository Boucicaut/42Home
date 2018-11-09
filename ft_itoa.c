#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		neg;

	neg = 1;
	i = 0;
	if (n < 0)
	{	
		i++;
		neg = -1;
		n = -n;
	}
	while ((n / 10) > 0)
	{
		i++;
		n = n / 10;
	}
	if ((str = malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	printf("i = %d", i);
	str[i] = '\0';
	if (neg == -1)
		str[0] = '-';
	while (n > 0)
	{
		if ((n % 10) == 0)
			str[i--] = '0';
		if (n > 9)
		{
			str[i--] = ((n % 10) - '0');
			n = (n - (n % 10)) / 10;
		}
		if (n < 9)
		{
			str[i--] = (n - '0');
			n = 0;
		}
	}
	return (str);
}
