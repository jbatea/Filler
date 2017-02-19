NAME		=	jbateau.filler

SRC_NAME	=	main.c	\
			ft_addcoord.c \
			ft_counttrim.c \
			ft_findspawn.c \
			ft_freenode.c \
			ft_nodeinfo.c \
			ft_nodeinit.c \
			ft_play.c \
			ft_possiblemove.c	\

SRC		=	$(addprefix srcs/, $(SRC_NAME))

OBJ		=	$(SRC:srcs/%.c=.obj/%.o)

CC		=	gcc

FLAGS		= 	-Wall -Werror -Wextra

LIB		= 	-L libft -lft

INCLUDE		= 	-I includes

all: 		$(NAME)

$(NAME): 	lib $(OBJ)
		$(CC) $(OBJ) $(INCLUDE) $(FLAGS) $(LIB) -o $@

.obj/%.o: 	srcs/%.c
		@mkdir -p .obj/
		$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
		@rm -rf .obj/
		@make clean -C libft/

fclean: 	clean
		@rm -rf $(NAME)
		@make fclean -C libft/

re: 		fclean all

lib:
		@make -C libft
