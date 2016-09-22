#include "../includes/filler.h"

char	**ft_saveboard(t_map *map)
{
	char	*line;
	char	**board;
	int	i;

	i = 0;
	board = (char **)malloc(sizeof(char *) * (map->y + 1));
	if (board)
	{
		while (get_next_line(0, &line) == 1 && i < map->y + 1)
		{
			board[i] = ft_strdup(line);
			ft_strdel(&line);
			i++;
		}
		board[i] = NULL;
	}
	return (board);
}

char	ft_playerchr(void)
{
	char	player;
	char	*line;

	get_next_line(0, &line);
	if (ft_strchr(line, '1'))
		player = 'O';
	else
		player = 'X';
	ft_strdel(&line);
	return (player);
}

t_map	*ft_mapchr(void)
{
	t_map	*map;
	char	*line;

	map = (t_map *)malloc(sizeof(t_map));
	if (map)
	{
		get_next_line(0, &line);
		map->x = ft_intchr(line, 1);
		map->y = ft_intchr(line, 0);
		map->board = ft_saveboard(map);
	}
	return (map);
}

/*t_piece	*ft_piecechr(void)
{

}*/

void	ft_nodeinfo(t_node **node)
{
	(*node)->player = ft_playerchr();
	(*node)->map = ft_mapchr();
	fprintf(stderr, "map->x = %d\nmap->y = %d\n", (*node)->map->x, (*node)->map->y);
	/**(node->piece) = ft_piecechr();*/
}
