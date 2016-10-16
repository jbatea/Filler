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

void		ft_playwest(t_node *node)
{
	t_move *move;
	int	x;
	int	y;

	move = node->move;
	x = node->move->x;
	y = node->move->y;
	while (move)
	{
		if (move->x < x)
		{
			x = move->x;
			y = move->y;
		}
		move = move->next;
	}
	node->x = x;
	node->y = y;
}

void		ft_playest(t_node *node)
{
	t_move *move;
	int	x;
	int	y;

	move = node->move;
	x = node->move->x;
	y = node->move->y;
	while (move)
	{
		if (move->x > x)
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
	if (node->spawn[0])
		ft_playnorth(node);
	if (node->spawn[1])
		ft_playsouth(node);
	if (node->spawn[2])
		ft_playwest(node);
	if (node->spawn[3])
		ft_playest(node);
}
