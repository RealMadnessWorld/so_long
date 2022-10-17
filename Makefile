NAME	= so_long
OS		= $(shell uname)

MAKEFLAGS += -s

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -f

# directories
SRCDIR	= ./srcs/
OBJDIR	= ./objs/
INCDIR	= ./includes/

# files
SRCS	= main.c so_long.c key_handler.c image_put.c map_dealing.c enemy_move.c
HEADER	= so_long.h
OBJ		= $((addprefix $(OBJDIR)/,SRCS:.c=.o))

# libft
LIBFT	= ./libft/libft.a
LIB_INC	= -I ./includes/libft

# mlx library
ifeq ($(OS), Linux)
	LIBS	= -lm -L./libft -lft -lmlx -lX11 -lbsd -lXext
	_RED	= \e[31;5;184m
	_GREEN	= \e[38;5;46m
	_YELLOW	= \e[38;5;184m
	_RESET	= \e[0m
else
	LIBS	= -lm -L./libft -lft -lmlx -framework OpenGL -framework AppKit
	_RED	= \x1b[31m
	_GREEN	= \x1b[32m
	_YELLOW	= \x1b[33m
	_RESET	= \x1b[0m
endif

all:	obj $(LIBFT) $(NAME)

obj:
				@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
				@$(CC) $(CFLAGS) -I $(INCDIR) $(LIBS) $(LIB_INC) -o $@ -c $<

$(LIBFT):
				@$(MAKE) bonus -C libft

$(NAME):	$(OBJ)
				@$(CC) -o $(NAME) $(CFLAGS) $(addprefix $(SRCDIR),$(SRCS)) -I $(INCDIR) $(OBJ) $(LIBS) $(LIBFT)
				@echo "$(_GREEN)Congrats!!!! It compiled!!!😊$(_RESET)"

clean:
				@rm -rf $(OBJDIR)
				@$(MAKE) clean -C libft
				@echo "$(_YELLOW)I'm gone$(_RESET)"

fclean: clean
				@$(RM) $(NAME)
				@$(RM) *.bpm
				@$(MAKE) fclean -C libft
				@echo "$(_RED)Bye suckers!$(_RESET)"

re: fclean all

.PHONY: all, clean, fclean, re, obj