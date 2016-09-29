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

void	ft_play(t_node *node, int *n) /*Play current move or exit program*/
{
	if (node->move)
		ft_printf("%d %d\n", node->x, node->y);
	else
	{
		ft_printf("0 0\n");
		*n = 0;
	}
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
		if ((node = ft_nodeinit()))
		{
			ft_nodeinfo(&node);
			ft_possiblemove(node, player);
			if (node->move)
				ft_findbestmove(node, player);
			ft_play(node, &n);
			ft_freenode(node);
		}
	}
	return (0);
}
