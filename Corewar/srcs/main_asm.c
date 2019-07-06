/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:52:53 by bviollet          #+#    #+#             */
/*   Updated: 2019/07/06 14:10:01 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/free_and_quit.h"
#include "../includes/read_asmfile.h"

static int	close_asmfile(int fd)
{
	if (close(fd) == -1)
		return (-1);
	return (0);
}

static int	open_asmfile(char *filename)
{
	int	fd;

	fd = -1;
	fd = open(filename, O_RDONLY);
	return (fd);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_champ	*champ;

	fd = -1;
	champ = NULL;
	if (argc != 2)
	{
		printf("Usage: ./asm filename\n");
		return (-1);
	}
	if ((fd = open_asmfile(argv[1])) == -1)
	{
		printf("ERROR : Bad filename \"%s\"\n", argv[1]);
		return (-1);
	}
	if ((champ = read_asmfile(fd)) == NULL)
		free_and_quit("Read_asmfile failed\n", champ, NULL);
	if (close_asmfile(fd) == -1)
		return (-1);

printf("TO_DO : Translate into bytecode\n\t%d lines read\n", champ->nb_line);
/* HERE WE GOT T_CHAMP FULFILLED, LET'S WRITE BYTECODE */
free_and_quit("End until more work is done", champ, NULL);

	ft_strchr(argv[1], '.')[0] = '\0';
	printf("Writing output program to %s.cor\n", argv[1]);
	return (0);
}
