#ifndef FILLER_H
#define FILLER_H
#include "../libft/srcs/includes/libft.h"

typedef struct		s_board
{
	int	x;
	int	y;
	char	**board;
}			t_board;

typedef struct		s_coord
{
	int		x;
	int		y;
	struct s_coord	*next;
}			t_coord;

typedef struct		s_node
{
	t_board	*map;
	t_board	*piece;
	t_coord	*move;
	t_coord	*spawn;
	int	cnt;
	int	x;
	int	y;
	int	nb;
	int	xavg;
	int	yavg;
}			t_node;

int	ft_nodeinfo(t_node **node);
void	ft_freenode(t_node *node);
void	ft_possiblemove(t_node *node, char player);
void	ft_addcoord(t_coord **coord, int x, int y);
void	ft_findspawn(t_node *node, char player);
int	ft_counttrim(t_node *node);

#endif
