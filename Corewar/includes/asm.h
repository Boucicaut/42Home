/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:14:08 by bviollet          #+#    #+#             */
/*   Updated: 2019/07/06 18:09:02 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

# define ASM_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "op.h"

#include <stdio.h>

typedef struct	s_label
{
	char		*name;
	int			position; //(nb byte from start, written already in content)
	struct s_label	*next;
	struct s_label	*prev;
}				t_label;

typedef struct	s_instruct
{
	int			binaire;
	int			params[MAX_ARGS_NUMBER][2];
	char 		opcode;
	t_label		*label; // pas utile ?  du coup ptr dans t_champ a la place
	struct s_instruct	*next;
	struct s_instruct	*prev;
}				t_instruct;

typedef struct	s_champ
{
	unsigned int	total_size;
	unsigned int	nb_line;
	t_header	*header;
	t_instruct	*ins;
	t_label		*label;
}				t_champ;

typedef struct	s_op
{ 
	char		*op;
	int			nb_params;
	int			params[MAX_ARGS_NUMBER];
	int			id;
	int			nb_cycles;
	char		*desc;
	int			enc_byte;
	int			dir_size;
}				t_op;

#endif
