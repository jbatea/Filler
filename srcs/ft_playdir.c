#include "../includes/filler.h"

void		ft_playnorthest(t_node *node)
{
	t_move *move;
	int	x;
	int	y;

	move = node->move;
	x = node->move->x;
	y = node->move->y;
	while (move)
	{
		if (move->y < y && move->x > x)
		{
			x = move->x;
			y = move->y;
		}
		move = move->next;
	}
	node->x = x;
	node->y = y;
}

void		ft_playsouthest(t_node *node)
{
	t_move *move;
	int	x;
	int	y;

	move = node->move;
	x = node->move->x;
	y = node->move->y;
	while (move)
	{
		if (move->y > y && move->x > x)
		{
			x = move->x;
			y = move->y;
		}
		move = move->next;
	}
	node->x = x;
	node->y = y;
}

void		ft_playsouthwest(t_node *node)
{
	t_move *move;
	int	x;
	int	y;

	move = node->move;
	x = node->move->x;
	y = node->move->y;
	while (move)
	{
		if (move->y > y && move->x < x)
		{
			x = move->x;
			y = move->y;
		}
		move = move->next;
	}
	node->x = x;
	node->y = y;
}

void		ft_playnorthwest(t_node *node)
{
	t_move *move;
	int	x;
	int	y;

	move = node->move;
	x = node->move->x;
	y = node->move->y;
	while (move)
	{
		if (move->y < y && move->x < x)
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
	fprintf(stderr, "node->spawn = %d\n", node->spawn);
	if (node->spawn == 3)
		ft_playnorthest(node);
	else if (node->spawn == 9)
		ft_playsouthest(node);
	else if (node->spawn == 15)
		ft_playsouthwest(node);
	else
		ft_playnorthwest(node);
}
