# Name of the library
NAME = libftprintf.a

OBJDIR = obj/

# Folders of the source files (*.c)
SRC_DIR = srcs/
LIB_DIR = libft/

# Source files
SRC_FILES = ft_printf.c pourcentd.c pourcentf.c pourcento.c pourcentp.c setlim.c initmatchpat.c\
			pourcentu.c pourcentx.c roundf.c setflaglim.c pourcentb.c colors.c pourcenta.c\

LIBNAME = libft/libft.a
LIBFT_FILES = ft_tento.c ft_putbignbr.c ft_qtebignb.c ft_convertbase.c ft_bigitoa.c\
		 converttosignedchar.c ft_issamealpha.c ft_itoadouble.c ft_qtenb.c ft_strchrcol.c \
		 ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
		 ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		 ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
		 ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		 ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
		 ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
		 ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		 ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
		 ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_findreplace.c \
		 ft_freeptr.c ft_freestr.c ft_swap.c ft_runthrough.c get_next_line.c hexatoupper.c\
		 convunsigned.c\


# Source files path
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
LIBFT = $(addprefix $(LIB_DIR), $(LIBFT_FILES))

# Objects
OBJ = $(SRC:.c=.o) $(LIBFT:.c=.o)

# Flags
INC = -Iincludes/
FLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

$(OBJDIR)%.o: %.c
		$(CC) $(FLAGS) -o %.c -c $<

$(NAME): $(OBJ)
	gcc -c -g $(FLAGS) $(SRC) $(LIBFT) $(INC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
# echo "=====[$(NAME) generated!]====="

clean:
	rm -f $(OBJ)
	rm -f *.o
	rm -f $(SRC_DIR)*.o
	rm -f $(LIBFT_DIR)*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBNAME)

re: fclean all

.PHONY: all clean fclean re
