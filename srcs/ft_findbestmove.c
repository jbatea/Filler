#include "../includes/filler.h"

char	ft_bot(char player)
{
	if (player == 'X')
		return ('O');
	return ('X');
}

char	ft_spawn(t_node *node, int i)
{
	if (i < node->map->y / 2)
		return ('N');
	return ('S');
}

char	ft_findspawn(t_node *node, char bot)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < node->map->y)
	{
		while (j < node->map->x)
		{
			if (node->map->board[i][j] && ft_toupper(node->map->board[i][j]) == bot)
				return (ft_spawn(node, i));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	ft_findbestmove(t_node *node, char player)
{
	node->spawn = ft_findspawn(node, ft_bot(player));
	ft_playdir(node);
}
