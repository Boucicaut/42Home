#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*
char	*ft_strcpy(char *dest, char *src)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (src[i] != '\0')
		i++;
	while (j <= i)
	{
		dest[j] = src[j];
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
*/
char	*ft_strncpy(char *dest2, char *src, int nb)
{
	int i;

	i = 0;
	while ((src[i] != '\0') && (i < nb))
	{
		dest2[i] = src[i];
		i++;
	}
	while (i < nb)
	{
		dest2[i] = '\0';
		i++;
	}
	return (dest2);
}

int	main(void)
{
	char tab3[5] = "hello";
	char tab4[5] = "hello";
	/*
	char tab[5] = "hello";
	char tab2[5] = "hello";

	printf("%s\n", ft_strcpy(tab, "kerou"));
	printf("%s\n", strcpy(tab2, "kerou"));*/
	printf("%s\n", ft_strncpy(tab3, "kerou", 5));
	printf("%s\n", strncpy(tab4, "kerou", 5));
	return (0);
}
