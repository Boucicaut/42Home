# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkettani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 14:15:50 by jkettani          #+#    #+#              #
#    Updated: 2019/07/06 18:36:49 by bviollet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----- VARIABLES -----

NC =            \x1b[0m
OK_COLOR =      \x1b[32;01m
ERR_COLOR =     \x1b[31;01m
WARN_COLOR =    \x1b[34;01m
QUIET :=        @
ECHO :=         @echo
ifneq ($(QUIET),@)
ECHO :=         @true
endif
SHELL =         /bin/sh
MAKEFLAGS +=    --warn-undefined-variables
NAME_PATH =     .
NAME = 			$(NAME_PATH)/my_asm
SRC_PATH =      srcs
INC_PATH =      includes
OBJ_PATH =      .obj
RM =            rm -f
RMDIR =         rmdir
AR =            ar
ARFLAGS =       -rcs
CC =            gcc
CFLAGS =        -g3 -Werror -Wall -Wextra
LFT_PATH = 		libft
LFT_INC_PATH =  $(LFT_PATH)
LFT_NAME =      libft.a
LFT =           $(LFT_PATH)/$(LFT_NAME)
LFT_FLAGS =     -L$(LFT_PATH) -lft
#CPPFLAGS =      -I$(INC_PATH) -I$(LFT_INC_PATH)
DEPFLAGS =      -MT $@ -MMD -MP -MF $(OBJ_PATH)/$*.d
COMPILE.c =     $(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c
POSTCOMPILE =   touch $@
SRC_NAME =      main_asm read_asmfile parse_header parse_content \
				del_whitespaces free_and_quit get_next_line identify_op
SRC =           $(addprefix $(SRC_PATH)/, $(addsuffix .c, $(SRC_NAME)))
OBJ =           $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))
DEP =           $(addprefix $(OBJ_PATH)/, $(SRC:.c=.d))
OBJ_TREE =      $(shell find $(OBJ_PATH) -type d -print 2> /dev/null | sort -r \
				2> /dev/null)

.SUFFIXES: .c .o .h

# ----- RULES -----

.PHONY: all
all: $(NAME)

.PRECIOUS: $(OBJ_PATH)%/. $(OBJ_PATH)/. 
$(OBJ_PATH)/. $(OBJ_PATH)%/.: 
	$(ECHO) "Making directory $(WARN_COLOR)$@$(NC)..."
	$(QUIET) mkdir -p $@

$(OBJ_PATH)/%.d: ;

.SECONDEXPANSION:

$(OBJ): $(OBJ_PATH)/%.o: %.c $(OBJ_PATH)/%.d | $$(@D)/.
	$(ECHO) "Compiling $(WARN_COLOR)$<$(NC)..."
	$(QUIET) $(COMPILE.c) $< -o $@
	$(QUIET) $(POSTCOMPILE)

$(LFT): force_rule
	$(ECHO) "Compiling $(WARN_COLOR)$(LFT)$(NC) if necessary..."
	$(QUIET) make -C $(LFT_PATH)

force_rule:

$(NAME): $(OBJ) $(LFT)
	$(ECHO) "Compiling $(WARN_COLOR)$@$(NC)..."
	$(QUIET) $(CC) $(CFLAGS) $(CPPFLAGS) $(LFT_FLAGS) $(OBJ) -o $@

.PHONY: norminette
norminette:
	$(ECHO) "$(WARN_COLOR)Checking norminette on .h files...$(NC)"
	$(QUIET) norminette $(INC_PATH)
	$(ECHO) "$(WARN_COLOR)Checking norminette on .c files...$(NC)"
	$(QUIET) norminette $(SRC_PATH)
	$(ECHO) "$(WARN_COLOR)Checking norminette on libft files...$(NC)"
	$(QUIET) norminette $(LFT_PATH)/srcs
	$(QUIET) norminette $(LFT_PATH)/includes

.PHONY: clean
clean:
	$(ECHO) "Cleaning object files..."
	$(QUIET) $(RM) $(OBJ)
	$(ECHO) "Cleaning dependency files..."
	$(QUIET) $(RM) $(DEP)
	$(ECHO) "Cleaning obj tree..."
	$(QUIET) echo $(OBJ_TREE) 2> /dev/null | xargs $(RMDIR) 2> /dev/null || true
	@if [ -d $(OBJ_PATH) ]; \
		then echo "$(ERR_COLOR)-> Could not clean obj directory.$(NC)"; \
		else echo "$(OK_COLOR)-> Obj directory succesfully cleaned.$(NC)"; fi

.PHONY: fclean
fclean: clean
	$(ECHO) "Cleaning $(NAME)..."
	$(QUIET) $(RM) $(NAME)
	@if [ -f $(NAME) ]; \
		then echo "$(ERR_COLOR)-> Could not clean $(NAME).$(NC)"; \
		else echo "$(OK_COLOR)-> $(NAME) succesfully cleaned.$(NC)"; fi

.PHONY: re
re: fclean all

# ----- INCLUDES -----

-include $(DEP)
