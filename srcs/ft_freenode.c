#include "../includes/filler.h"

void	ft_freeboard(t_board *board)
{
	ft_tabfree(board->board);
	free(board);
	board = NULL;
}

void	ft_freecoord(t_coord *coord)
{
	t_coord	*tmp;
	t_coord	*ptmp;
	
	tmp = coord;
	while (tmp)
	{
		ptmp = tmp->next;
		free(tmp);
		tmp = ptmp;
	}
}

void	ft_freenode(t_node *node)/*Free all allocated memory*/
{
	if (node)
	{
		if (node->map)
			ft_freeboard(node->map);
		if (node->piece)
			ft_freeboard(node->piece);
		if (node->move)
		{
			ft_freecoord(node->move);
			node->move = NULL;
		}
		if (node->spawn)
		{
			ft_freecoord(node->spawn);
			node->spawn = NULL;
		}
	}
	free(node);
	node = NULL;
}
