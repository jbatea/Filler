#include "../includes/filler.h"

void		ft_playnorth(t_node *node)
{
	t_move *move;
	int	x;
	int	y;

	move = node->move;
	x = node->move->x;
	y = node->move->y;
	while (move)
	{
		if (move->y < y)
		{
			x = move->x;
			y = move->y;
		}
		move = move->next;
	}
	node->x = x;
	node->y = y;
}

void		ft_playsouth(t_node *node)
{
	t_move *move;
	int	x;
	int	y;

	move = node->move;
	x = node->move->x;
	y = node->move->y;
	while (move)
	{
		if (move->y > y)
		{
			x = move->x;
			y = move->y;
		}
		move = move->next;
	}
	node->x = x;
	node->y = y;
}

void	ft_playdir(t_node *node)
{
	if (node->spawn == 'N')
		ft_playnorth(node);
	else
		ft_playsouth(node);
}
