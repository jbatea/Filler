#include "../includes/filler.h"

void	ft_freeboard(t_board *board)
{
	if (board)
	{
		ft_tabfree(board->board);
		ft_memdel((void *)&board);
	}
}

void	ft_freecoord(t_coord *coord)
{
	t_coord	*tmp;
	t_coord	*ptmp;
	
	tmp = coord;
	if (tmp && tmp->average)
		ft_memdel((void *)&(tmp->average));
	while (tmp)
	{
		ptmp = tmp->next;
		free(tmp);
		tmp = ptmp;
	}
	coord = NULL;
}

void	ft_freenode(t_node *node)/*Free all allocated memory*/
{
	if (node)
	{
		ft_freeboard(node->map);
		ft_freeboard(node->piece);
		ft_freecoord(node->move);
		ft_freecoord(node->my_spawn);
		ft_freecoord(node->op_spawn);
		ft_memdel((void *)&node);
	}
}
