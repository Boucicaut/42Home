/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_asmfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:53:30 by bviollet          #+#    #+#             */
/*   Updated: 2019/07/06 15:17:31 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/read_asmfile.h"
#include "../includes/parse_header.h"
#include "../includes/parse_content.h"
#include "../includes/free_and_quit.h"
#include "../includes/del_whitespaces.h"

static int		header_full_valid(t_champ *champ)
{
	if (!champ || !(champ->header))
		return (0);
	if (champ->header->prog_name[0] == '\0'\
		|| champ->header->comment[0] == '\0')
		return (0);
	return (1);
}

static t_champ	*init_champ(void)
{
	t_champ	*champ;

	champ = NULL;
	if (!(champ = (t_champ*)malloc(sizeof(t_champ))))
		free_and_quit("Init_champ failed\n", champ, NULL);
	champ->header = NULL;
	champ->ins = NULL;
	champ->label = NULL;
	if (!(champ->header = (t_header*)malloc(sizeof(t_header))))
		free_and_quit("Init_champ failed\n", champ, NULL);
	champ->header->magic = COREWAR_EXEC_MAGIC;
	champ->header->prog_name[0] = '\0';
	champ->header->prog_size = 0;
	champ->header->comment[0] = '\0';
	//if (!(champ->ins = (t_instruct*)malloc(sizeof(t_instruct))))
	//	free_and_quit("Init_champ failed\n", champ, NULL);
	//champ->ins->next = NULL;
	//champ->ins->prev = NULL;
	//if (!(champ->label = (t_label*)malloc(sizeof(t_label))))
	//	free_and_quit("Init_champ failed\n", champ, NULL);
	//champ->label->next = NULL;
	//champ->label->prev = NULL;
	//champ->label->name = NULL;
	champ->nb_line = 0;
	return (champ);
}

static int		is_comment_or_empty(char *line)
{
	if (line &&\
		(!*line || line[0] == COMMENT_CHAR\
		 || ft_strncmp(line, "\n", 1) == 0))
	{
		free(line);
		line = NULL;
		return (1);
	}
	return (0);
} 

t_champ *read_asmfile(int fd)
{
	char	*line;
	t_champ	*champ;

	if (!(champ = init_champ()))
		free_and_quit("Init_champ failed", champ, NULL);
	line = NULL;
printf("\tFile :\t\t(format : \"| line_content\")\n");
	while (get_next_line(fd, &line, 0, 0))
	{
		if (!line)
			free_and_quit("Get_next_line returned line == NULL", champ, NULL);
		champ->nb_line++;
printf("\t%d.|\t%s\n",champ->nb_line, line);
		line = del_whitespaces(line);
		if (is_comment_or_empty(line)) // line free here if 1 returned
			continue ;
		if (header_full_valid(champ) == 0\
	|| !(ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING))\
	|| !(ft_strncmp(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))))
		{
			parse_header(champ, line); // parse_header == -1 ?
if (header_full_valid(champ)){
printf("\t______________________________________\n\tHeader done :\n");
printf("\t\tName\t: %s|\n", champ->header->prog_name);
printf("\t\tComment\t: %s|\n", champ->header->comment);
printf("\t\tMagic\t: %#X\n\t______________________________________\n", champ->header->magic);}
		}
		else
			parse_content(champ, line);
		free(line);
		line = NULL;
	}
	if (header_full_valid(champ) == 0)
		free_and_quit("Invalid syntax", champ, NULL);
	return (champ);
}
