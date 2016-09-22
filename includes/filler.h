#ifndef FILLER_H
#define FILLER_H
#include "../libft/srcs/includes/libft.h"

#define NAME "jbateau.filler"

typedef struct		s_map
{
	int	x;
	int	y;
	char	**board;
}			t_map;

typedef struct		s_piece
{
	int	x;
	int	y;
	char	**map;
}			t_piece;

typedef struct		s_node
{
	char	player;
	t_map	*map;
	t_piece	*piece;
}			t_node;

void	ft_nodeinfo(t_node **node);
#endif
