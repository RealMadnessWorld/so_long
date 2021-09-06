NAME	= so_long
OS		= $(shell uname)

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -g

# directories
SRCDIR	= ./srcs/
OBJDIR	= ./objs/
INCDIR	= ./includes/

# files
SRCS	= main.c so_long.c key_handler.c image_put.c map_dealing.c
HEADER	= so_long.h
OBJ		= $((addprefix $(OBJDIR)/,SRCS:.c=.o))

# libft
LIBFT	= ./libft/libft.a
LIB_INC	= -I ./includes/libft

# mlx library
ifeq ($(OS), Linux)
	MLX		= ./miniLibX_X11/
	MLX_LNK	= -L $(MLX) -l mlx -lXext -lX11 -lm -lz
else
	MLX		= ./miniLibX/
	MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit
endif

MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX),libmlx_linux.a)

all:	obj $(LIBFT) $(MLX_LIB) $(NAME)

obj:
				@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
				@$(CC) $(CFLAGS) -I $(INCDIR) $(MLX_INC) $(LIB_INC) -o $@ -c $<

$(LIBFT):
				@$(MAKE) bonus -C libft

$(MLX_LIB):
				@$(MAKE) -C $(MLX)

$(NAME):	$(OBJ)
				@$(CC) -o $(NAME) $(CFLAGS) $(addprefix $(SRCDIR),$(SRCS)) -I $(INCDIR) $(OBJ) $(MLX_LNK) $(LIBFT)
				@echo "\x1b[32mCongrats!!!! It compiled!!!😊\x1b[0m"

clean:
				@rm -rf $(OBJDIR)
				@$(MAKE) clean -C libft
				@$(MAKE) clean -C $(MLX)
				@echo "\x1b[31mI'm gone\x1b[0m"

fclean: clean
				@$(RM) $(NAME)
				@$(RM) *.bpm
				@$(MAKE) fclean -C libft
				@echo "\x1b[31mBye bitches!\x1b[0m"

re: fclean all

.PHONY: all, clean, fclean, re, obj