#include "../includes/filler.h"

void	ft_freemap(t_map *map)
{
	ft_tabfree(map->board);
	free(map);
	map = NULL;
}

void	ft_freepiece(t_piece *piece)
{
	ft_tabfree(piece->board);
	free(piece);
	piece = NULL;
}

void	ft_freemove(t_move *move)
{
	t_move	*tmp;
	t_move	*ptmp;
	
	tmp = move;
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
			ft_freemap(node->map);
		if (node->piece)
			ft_freepiece(node->piece);
		if (node->move)
		{
			ft_freemove(node->move);
			node->move = NULL;
		}
	}
	free(node);
	node = NULL;
}
