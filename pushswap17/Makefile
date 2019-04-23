# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bviollet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/14 14:35:04 by bviollet          #+#    #+#              #
#    Updated: 2019/04/15 18:25:20 by bviollet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEPUSH = push_swap
NAMECHECK = checker

SRCPUSH = printpile.c set_1.c set_2.c set_3.c comparetests.c push_swap.c pusherror.c comparetests2.c mediumpivot.c quicksort.c petittri.c
SRCCHECK = checker.c printpile.c set_1.c set_2.c set_3.c comparetests.c pusherror.c comparetests2.c mediumpivot.c quicksort.c petittri.c

CC = gcc
CFLAGS = -Werror -Wall -Wextra
OBJCHECK = $(SRCCHECK:.c=.o)
OBJPUSH = $(SRCPUSH:.c=.o)
LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

all : $(NAMEPUSH) $(NAMECHECK)

$(NAMEPUSH): $(OBJPUSH)
			$(MAKE) -C $(LIBFT_PATH)
			$(CC) $(FLAGS) $(LIBFT) $(SRCPUSH) -o $(NAMEPUSH)
$(NAMECHECK): $(OBJCHECK)
			$(MAKE) -C $(LIBFT_PATH)
			$(CC) $(FLAGS) $(LIBFT) $(SRCCHECK) -o $(NAMECHECK)
clean:
		@make clean -C $(LIBFT_PATH)
		@rm -f $(OBJ)
fclean: clean
		@rm -f $(NAMEPUSH) $(NAMECHECK) $(LIBFT)
re: fclean all

.PHONY: all clean fclean re
