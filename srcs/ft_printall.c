#include "../includes/filler.h"

void	ft_printmap(char **board)
{
	int	i;

	i = 0;
	while (board[i])
	{
		fprintf(stderr, "board[%2d] = %s\n", i, board[i]);
		i++;
	}
}

void	ft_printmove(t_node *node)
{
	t_move	*tmp;
	
	tmp = node->move;
	if (tmp)
	{
		while (tmp)
		{
			fprintf(stderr, "move = %d %d\n", tmp->x, tmp->y);
			tmp = tmp->next;
		}
	}
}

void	ft_printall(t_node *node)
{
	fprintf(stderr, "map->x = %d\nmap->y = %d\n", node->map->x, node->map->y);
	ft_printmap(node->map->board);
	fprintf(stderr, "piece->x = %d\npiece->y = %d\n", node->piece->x, node->piece->y);
	ft_printmap(node->piece->board);
	ft_printmove(node);
}
