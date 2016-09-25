#include "../includes/filler.h"

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

char	**ft_saveboard(int y)
{
	char	*line;
	char	**board;
	int	i;

	i = 0;
	board = (char **)malloc(sizeof(char *) * (y + 2));
	if (board)
	{
		while (i < y + 1 && get_next_line(0, &line) == 1)
		{
			board[i] = ft_strdup(line);
			ft_strdel(&line);
			i++;
		}
		board[i] = NULL;
	}
	return (board);
}

void	ft_mapchr(t_map **map)
{
	char	*line;

	get_next_line(0, &line);
	(*map)->x = ft_intchr(line, 1);
	(*map)->y = ft_intchr(line, 0);
	(*map)->board = ft_saveboard((*map)->y);
}

void	ft_piecechr(t_piece **piece)
{
	char	*line;

	get_next_line(0, &line);
	(*piece)->x = ft_intchr(line, 1);
	(*piece)->y = ft_intchr(line, 0);
	(*piece)->board = ft_saveboard((*piece)->y);
}

void	ft_nodeinfo(t_node **node)
{
	if ((*node)->map && (*node)->piece)
	{
		(*node)->player = ft_playerchr();
		ft_mapchr(&(*node)->map);
		ft_piecechr(&(*node)->piece);
	}
}
