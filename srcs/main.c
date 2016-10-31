#include "../includes/filler.h"

char	ft_playerchr(void) /*Use to find starting position*/
{
	char	player;
	char	*line;

	get_next_line(0, &line);
	if (ft_strchr(line, '1'))
		player = 'O';
	else
		player = 'X';
	ft_strdel(&line);
	return (player);
}

t_board	*ft_initboard(void)
{
	t_board	*new;

	new = (t_board *)malloc(sizeof(t_board));
	if (new)
	{
		new->x = 0;
		new->y = 0;
		new->board = NULL;
	}
	return (new);
}

t_node	*ft_nodeinit(void) /*Allocate memory for structures and init them*/
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node)
	{
		node->map = ft_initboard();
		node->piece = ft_initboard();
		node->my_spawn = NULL;
		node->op_spawn = NULL;
		node->move = NULL;
		node->cnt = 0;
		node->x = 0;
		node->y = 0;
	}
	return (node);
}

void	ft_output(t_node *node, int *n) /*Play current move or exit program*/
{
	if (node->move)
		ft_printf("%d %d\n", node->y, node->x);
	else
	{
		ft_printf("0 0\n");
		*n = 0;
	}
}

char	ft_op(char player)
{
	if (player == 'X')
		return ('O');
	return ('X');
}

int	main(void) /*Main game's functions, save data then find best play each turn*/
{
	t_node	*node;
	char	player;
	int	n;

	n = 1;
	node = NULL;
	player = ft_playerchr();
	while (n)
	{	
		if ((node = ft_nodeinit()) && ft_nodeinfo(&node))
		{
			ft_possiblemove(node, player);
			if (node->move)
				ft_findspawn(node, &(node->my_spawn), player);
			ft_findspawn(node, &(node->op_spawn), ft_op(player));
			ft_play(node);
			ft_output(node, &n);
			ft_freenode(node);
		}
	}
	return (0);
}
