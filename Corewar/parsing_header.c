/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:52:53 by bviollet          #+#    #+#             */
/*   Updated: 2019/07/03 15:56:29 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	free_and_quit(char *err_msg, t_champ *champ)
{
	t_instruct	*ins;
	t_label	*label;

	ins = NULL;
	ft_printf("ERROR : %s\n", err_msg);
	if (champ)
	{
		if (champ->header)
			free(champ->header);
		ins = champ->ins;
		while (ins)
		{
			champ->ins = champ->ins->next;
			free(ins);
			ins = champ->ins;
		}
		label = champ->label;
		while (label)
		{
			champ->label = champ->label->next;
			if (label->name)
				free(label->name);
			free(label);
			label = champ->label;
		}
	}
	exit(-1);
}

int		header_full_valid(t_champ *champ)
{
	if (!champ || !(champ->header))
		return (0);
	if (champ->header->prog_name[0] == '\0'\
		|| champ->header->comment[0] == '\0')
		return (0);
	return (1);
}

int		valid_header_name_comment(char *line)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (line && line[i] != '"')
		i++;
	len = ++i;
	while (line && line[i] != '"')
		i++;
	len = i++ - len;
	while (line && line[i])
		if (line[i++] == '"')
			return (0);
	if (!(ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING))))
		if (len <= PROG_NAME_LENGTH)
			return (1);
	if (!(ft_strncmp(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING))))
		if (len <= COMMENT_LENGTH)
			return (2);
	return (0);
}

int		parse_file(t_champ *champ, char *line)
{
	int	i;

	i = 0;
	if (!champ || !line)
		return (-1);
	if (header_full_valid(champ) == 0)
	{
		if ((i = valid_header_name_comment(line)) == 1)
			ft_strcpy(champ->header->prog_name, ft_strchr(line, '"'));
		else if (i == 2)
			ft_strcpy(champ->header->comment, ft_strchr(line, '"'));
	}
	else
	{
ft_printf("Else parse_file\n");
sleep(1);
	}
	return (0);
}

int		is_comment_or_empty(char *line)
{
	if (line &&\
		(ft_strncmp(line, "#", 1) == 0 || ft_strncmp(line, "\n", 1) == 0))
	{
		free(line);
		return (1);
	}
	return (0);
} 

t_champ	*init_champ(void)
{
	t_champ	*champ;

	champ = NULL;
	if (!(champ = (t_champ*)malloc(sizeof(t_champ))))
		free_and_quit("Init_champ failed\n", champ);
	champ->header = NULL;
	champ->ins = NULL;
	champ->label = NULL;
	if (!(champ->header = (t_header*)malloc(sizeof(t_header))))
		free_and_quit("Init_champ failed\n", champ);
	champ->header->magic = COREWAR_EXEC_MAGIC;
	champ->header->prog_name[0] = '\0';
	champ->header->prog_size = 0;
	champ->header->comment[0] = '\0';
	if (!(champ->ins = (t_instruct*)malloc(sizeof(t_instruct))))
		free_and_quit("Init_champ failed\n", champ);
	if (!(champ->label = (t_label*)malloc(sizeof(t_label))))
		free_and_quit("Init_champ failed\n", champ);
	return (champ);
}

t_champ *read_asmfile(int fd)
{
	char	*line;
	t_champ	*champ;

	if (!(champ = init_champ()))
		free_and_quit("Init_champ failed\n", champ);
	line = NULL;
	while (get_next_line(fd, &line, 0, 0) != -1)
	{
//free(line) somewhere!
		if (is_comment_or_empty(line)) // line free here if 1 returned
			continue ;
		parse_file(champ, line);
		free(line);
	}
	return (champ);
}

int	close_asmfile(int fd)
{
	if (close(fd) == -1)
		return (-1);
	return (0);
}

int	open_asmfile(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	return (fd);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_champ	*champ;

	fd = 0;
	champ = NULL;
	if (argc > 2)
		free_and_quit("Too many arguments\n", champ);
	if ((fd = open_asmfile(argv[1])) == -1)
		free_and_quit("File can't be found\n", champ);
	if ((champ = read_asmfile(fd)) == NULL)
		free_and_quit("Read_asmfile failed\n", champ);
	if (close_asmfile(fd) == -1)
		return (-1);

/* HERE WE GOT T_CHAMP FULFILLED, LET'S WRITE BYTECODE */

	return (0);
}
