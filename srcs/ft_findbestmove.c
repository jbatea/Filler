#include "../includes/filler.h"

int	ft_spawn(t_node *node, int i, int j)
{
	if (i < node->map->y / 2 && j < node->map->x / 2)
		return (9);
	if (i < node->map->y / 2 && j > node->map->x / 2)
		return (15);
	if (i > node->map->y / 2 && j < node->map->x / 2)
		return (3);
	if (i > node->map->y / 2 && j > node->map->x / 2)
		return (21);
	return (0);
}

int	ft_findspawn(t_node *node, char player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < node->map->y)
	{
		while (j < node->map->x)
		{
			if (node->map->board[i][j] && node->map->board[i][j] == player)
				return (ft_spawn(node, i, j));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	ft_findbestmove(t_node *node, char player)
{
	node->spawn = ft_findspawn(node, player);
	ft_playdir(node);
}
