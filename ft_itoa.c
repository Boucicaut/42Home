#include "libft.h"

<<<<<<< HEAD
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
=======
int        nbDigits(int nb)
{

    int    i;

    i = 1;
    while ((nb / 10) > 0)
    {
        i++;
        nb = nb / 10;
    }
    return (i);
}

char    *fillStr(int n, char *str, int i, int neg)
{
	str[i--] = '\0';
    if (neg == -1)
        str[0] = '-';
    while (n > 0)
    {
        if ((n % 10) == 0)
        {
            str[i--] = '0';
            n = n / 10;
        }
        if (n > 9)
        {
            str[i--] = ((n % 10) + '0');
            n = (n - (n % 10)) / 10;
        }
        if (n <= 9)
        {
            str[i--] = (n + '0');
            n = 0;
        }
    }
    return (str);
}

char    *ft_itoa(int n)
{
    int        i;
    char    *str;
    int        neg;

    if (n == 0)
    {
        str = malloc(sizeof(char) * 2);
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    neg = 1;
    i = 1;
    if (n < 0)
    {
        i++;
        neg = -1;
        n = -n;
    }
    i = nbDigits(n);
    if ((str = malloc(sizeof(char) * i + 1)) == NULL)
        return (NULL);
    return (fillStr(n, str, i, neg));
>>>>>>> bbe1d56ff90addd1e430f5ebee91362e87f9b249
}
