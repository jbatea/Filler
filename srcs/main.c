#include "../includes/filler.h"

t_node	*ft_nodeinit(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->player = '*';
	node->map = NULL;
	node->piece = NULL;
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
		free(node);
	}
	return (0);
}
