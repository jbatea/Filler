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

int	*ft_initspawn(void)
{
	int	*spawn;
	int	i;

	i = 0;
	spawn = (int *)malloc(sizeof(int) * (4));
	if (!spawn)
		return (NULL);
	while (i < 4)
	{
		spawn[i] = 0;
		i++;
	}
	return (spawn);
}

t_node	*ft_nodeinit(void) /*Allocate memory for structures and init them*/
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->map = ft_initmap();
	node->piece = ft_initpiece();
	node->spawn = ft_initspawn(); 
	node->move = NULL;
	node->cnt = 0;
	node->x = 0;
	node->y = 0;
	return (node);
}
