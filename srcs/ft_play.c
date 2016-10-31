#include "../includes/filler.h"

int	ft_opspawn(t_node *node, t_coord *op_spawn, t_coord *move)
{
	int	min;
	int	cur;

	min = ft_abs(op_spawn->average->x - node->x) + ft_abs(op_spawn->average->y - node->y);
	cur = ft_abs(op_spawn->average->x - move->x) + ft_abs(op_spawn->average->y - move->y);
	if (cur >= min)
		return (1);
	return (0);
}

void	ft_avgcmp(t_node *node, t_coord *move)
{
	int	min;
	int	cur;

	min = ft_abs(node->my_spawn->x - node->x) + ft_abs(node->my_spawn->y - node->y);
	cur = ft_abs(node->my_spawn->x - move->x) + ft_abs(node->my_spawn->y - move->y);
	if (cur >= min /*|| (cur == min && node->op_spawn && ft_opspawn(node, node->op_spawn, move))*/)
	{
		node->y = move->y;
		node->x = move->x;
	}
}

void	ft_play(t_node *node)
{
	t_coord	*move;

	move = node->move;
	if (move)
	{
		node->y = move->y;
		node->x = move->x;
		while (move)
		{
			ft_avgcmp(node, move);
			move = move->next;
		}
	}
}
