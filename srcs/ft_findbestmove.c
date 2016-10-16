#include "../includes/filler.h"

void	ft_spawn(t_node *node, int i, int j)
{
	if (i < node->map->y / 2)
		node->spawn[0]++;
	if (i > node->map->y / 2)
		node->spawn[1]++;
	if (j < node->map->x / 2)
		node->spawn[2]++;
	if (j > node->map->x / 2)
		node->spawn[3]++;
}

void	ft_findspawn(t_node *node, char player)
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
				ft_spawn(node, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

char	ft_opponent(char player)
{
	if (player == 'X')
		return ('O');
	return ('X');
}

void	ft_clearspawn(t_node *node, int j)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i != j)
			node->spawn[i] = 0;
		else
			node->spawn[i] = 1;
		i++;
	}
}

void	ft_spawncount(t_node *node)
{
	int	i;
	int	j;
	int	best;

	i = 0;
	j = i;
	best = node->spawn[i];
	while (i < 4)
	{
		if (node->spawn[i] < best)
		{
			j = i;
			best = node->spawn[i];
		}
		i++;
	}
	ft_clearspawn(node, j);
}

void	ft_findbestmove(t_node *node, char player)
{
	ft_findspawn(node, player);
	ft_spawncount(node);
	ft_playdir(node);
}
