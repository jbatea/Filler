#include "../includes/filler.h"

void	ft_avgcmp(t_node *node, t_coord *move)
{
	int	min;
	int	cur;

	min = ft_abs(node->xavg + node->yavg - (node->x + node->y));
	cur = ft_abs(node->xavg + node->yavg - (move->x + move->y));
	if (cur >= min)
	{
		node->y = move->y;
		node->x = move->x;
	}
}

void	ft_playavg(t_node *node)
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

void	ft_average(t_node *node)
{
	t_coord	*spawn;

	spawn = node->spawn;
	while (spawn)
	{
		node->xavg = node->xavg + spawn->x;
		node->yavg = node->yavg + spawn->y;
		spawn = spawn->next;
	}
	node->xavg = node->xavg / node->nb;
	node->yavg = node->yavg / node->nb;
	ft_playavg(node);
}

void	ft_findspawn(t_node *node, char player)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < node->map->y)
	{
		while (x < node->map->x)
		{
			if (node->map->board[y][x] && node->map->board[y][x] == player)
			{
				ft_addcoord(&(node->spawn), x, y);
				node->nb = node->nb + 1;
			}
			x++;
		}
		x = 0;
		y++;
	}
	ft_average(node);
}
