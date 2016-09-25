#include "../includes/filler.h"

t_map	*ft_initmap(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map)
	{
		map->x = 0;
		map->y = 0;
		map->board = NULL;
	}
	return (map);
}

t_piece	*ft_initpiece(void)
{
	t_piece	*piece;

	piece = (t_piece *)malloc(sizeof(t_piece));
	if (piece)
	{
		piece->x = 0;
		piece->y = 0;
		piece->board = NULL;
	}
	return (piece);
}

t_node	*ft_nodeinit(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->player = '*';
	node->map = ft_initmap();
	node->piece = ft_initpiece();
	return (node);
}

void	ft_printmap(char **board)
{
	int	i;

	i = 0;
	while (board[i])
	{
		fprintf(stderr, "board[i] = %s\n", board[i]);
		i++;
	}
}

int	main(void)
{
	char	*line;
	t_node	*node;

	line = NULL;
	if ((node = ft_nodeinit()))
	{
		ft_nodeinfo(&node);
		fprintf(stderr, "player = %c\nmap->x = %d\nmap->y = %d\n", node->player, node->map->x, node->map->y);
		ft_printmap(node->map->board);
		fprintf(stderr, "piece->x = %d\npiece->y = %d\n", node->piece->x, node->piece->y);
		ft_printmap(node->piece->board);
		free(node);
	}
	return (0);
}
