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
	char	**board;
}			t_piece;

typedef struct		s_move
{
	int		x;
	int		y;
	struct s_move	*next;
}			t_move;

typedef struct		s_node
{
	t_map	*map;
	t_piece	*piece;
	t_move	*move;
	int	cnt;
	int	x;
	int	y;
	int	spawn;
}			t_node;

t_node	*ft_nodeinit(void);
void	ft_nodeinfo(t_node **node);
void	ft_freenode(t_node *node);
void	ft_printall(t_node *node);
void	ft_possiblemove(t_node *node, char player);
void	ft_addmove(t_node **node, int x, int y);
void	ft_printmap(char **board);
void	ft_findbestmove(t_node *node, char player);
void	ft_playdir(t_node *node);

#endif
