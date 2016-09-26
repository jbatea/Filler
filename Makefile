NAME =		jbateau.filler

NAMEBASE =	$(shell basename $(NAME))
MAKE = 		make -C
CC =		clang
FLAGS =		-Wall -Werror -Wextra
SRCS =		srcs/
INCLUDES =	includes/
LIBFT =		libft/
OBJDIR = 	objs
FT_INCLUDES =	$(LIBFT)/srcs/includes

COMPILED =	main.o \
		ft_nodeinfo.o \
		ft_freenode.o \
		ft_printall.o \
		ft_nodeinit.o \
		ft_possiblemove.o \
		ft_addmove.o \

.SILENT:

all: 		$(NAME)
		echo "\033[38;5;44m☑️  ALL    $(NAMEBASE) is done\033[0m\033[K"

$(NAME): 	$(COMPILED)
		$(MAKE) $(LIBFT)
		@$(CC) $(FLAGS) -o $(NAME) -L $(LIBFT) -lft $(COMPILED)
		echo -en "\r\033[38;5;22m☑️  MAKE   $(NAMEBASE)\033[0m\033[K"

$(COMPILED): 	%.o: $(SRCS)%.c
		@$(CC) -c $(FLAGS) -I $(FT_INCLUDES) -I $(INCLUDES) $< -o $@
		echo "\r\033[38;5;11m⌛  MAKE   $(NAMEBASE) please wait ...\033[0m\033[K"

clean:
		$(MAKE) $(LIBFT) clean
		@-/bin/rm -f $(COMPILED)
		echo "\r\033[38;5;11m⌛  CLEAN  $(NAMEBASE) please wait ...\033[0m\033[K"

fclean: 	clean
		$(MAKE) $(LIBFT) fclean
		@-/bin/rm -f $(NAME)
		echo "\r\033[38;5;11m⌛  FCLEAN $(NAMEBASE) please wait ...\033[0m\033[K"

re: 		fclean all

.PHONY:		fclean clean re
