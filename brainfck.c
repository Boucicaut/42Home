/*Assignment name  : brainfuck
Expected files   : *.c, *.h
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a Brainfuck interpreter program.
The source code will be given as first parameter.
The code will always be valid, with no more than 4096 operations.
Brainfuck is a minimalist language. It consists of an array of bytes 
(in our case, let's say 2048 bytes) initialized to zero, 
and a pointer to its first byte.

Every operator consists of a single character :
- '>' increment the pointer ;
- '<' decrement the pointer ;
- '+' increment the pointed byte ;
- '-' decrement the pointed byte ;
- '.' print the pointed byte on standard output ;
- '[' go to the matching ']' if the pointed byte is 0 (while start) ;
- ']' go to the matching '[' if the pointed byte is not 0 (while end).

Any other character is a comment.

Examples:

$>./brainfuck "++++++++++[>+++++++>++++++++++>+++>+<<<<-]
>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>." | cat -e
Hello World!$
$>./brainfuck "+++++[>++++[>++++H>+++++i<<-]>>>++\n<<<<-]>>--------.>+++++.>." | cat -e
Hi$
$>./brainfuck | cat -e*/

#include <stdlib.h>
#include <stdio.h>

void	brainfuck(char *str, char *ptr, int k)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+')
			(*ptr)++;
		else if (str[i] == '-')
			(*ptr)--;
		else if (str[i] == '>')
			ptr++;
		else if (str[i] == '<')
			ptr--;
		else if (str[i] == '.')
			printf("%c", (char)*(ptr));
		else if (str[i] == '[')
		{
			k = 0;
			if ((char)*ptr == (char)0)
			{
				i++;
				while (str[i] && str[i] != ']' && k != 0)
				{
					if (str[i] == '[')
						k++;
					if (str[i] == ']' && k != 0)
						k--;
					i++;
				}
				i++;
			}
		}
		if (str[i] == ']')
		{
			k = 0;
			i--;
			while (i > 0 && str[i] != '[' && k == 0)
			{
				if (str[i] == ']')
					k++;
				if (str[i] == '[' && k != 0)
					k--;
				i--;
			}
			i--;
		}
		i++;
	}
	return ;
}
#include <string.h>
#include <unistd.h>
void	ft_brainfuck(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char*)malloc(sizeof(ptr) * 2048);
	while (str[i] != 0)
	{
		*ptr += str[i] == '+' ? 1 : 0;
		*ptr -= str[i] == '-' ? 1 : 0;
		ptr += str[i] == '>' ? 1 : 0;
		ptr -= str[i] == '<' ? 1 : 0;
		if (str[i] == '[' && *ptr == 0)
			while (str[i] != ']')
				i++;
		if (str[i] == ']' && *ptr != 0)
			while (str[i] != '[')
				i--;
		if (str[i] == '.')
			write(1, ptr, 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*ptr;

	if (!(ptr = (char*)malloc(2048)))
		return (0);
	ptr = memset(ptr, 0, 2048);
	if (argc < 2)
		return (0);
	ft_brainfuck(argv[1]);
getchar();
	brainfuck(argv[1], ptr, 0);
	free(ptr);
	return (0);
}
