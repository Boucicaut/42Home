# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bviollet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/14 14:35:04 by bviollet          #+#    #+#              #
#    Updated: 2019/04/15 14:53:30 by bviollet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEPUSH = push_swap
NAMECHECK = checker

SRCPUSH = formatargpushswap.c printpile.c set_1.c set_2.c set_3.c comparetests.c push_swap.c pusherror.c
SRCCHECK = checker.c printpile.c set_1.c set_2.c set_3.c comparetests.c pusherror.c

CC = gcc
CFLAGS = -Werror -Wall -Wextra
OBJ = $(SRCPUSH:.c=.o) $(SRCCHECK:.c=.o)
LIBFT = libft.a
LIBFT_PATH = ~/Documents/42Home_Git/libft_full/libft

all : $(NAMEPUSH) $(NAMECHECK)

$(NAMEPUSH): $(OBJ)
			# @$(MAKE) -C $(LIBFT_PATH)
			$(CC) $(FLAGS) $(LIBFT) $(SRCPUSH) -o $(NAMEPUSH)
$(NAMECHECK): $(OBJ)
			# @$(MAKE) -C $(LIBFT_PATH)
			$(CC) $(FLAGS) $(LIBFT) $(SRCCHECK) -o $(NAMECHECK)
clean:
		@make clean -C $(LIBFT_PATH)
		@rm -f $(OBJ)
fclean: clean
		@rm -f $(NAMEPUSH) $(NAMECHECK)
re: fclean all

.PHONY: all clean fclean re
