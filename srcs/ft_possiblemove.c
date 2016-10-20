#include "../includes/filler.h"

void	ft_canfill(t_node *node, int i, int j, char player) /*Check if new form can be placed*/
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < node->piece->y)
	{
		while (x < node->piece->x)
		{
			if (node->piece->board[y][x] == '*' && node->map->board[y + i][x + j] && node->map->board[y + i][x + j] == player)
				node->cnt++;
			if (node->piece->board[y][x] == '*' && node->map->board[y + i][x + j] && node->map->board[y + i][x + j] != player && node->map->board[y + i][x + j] != '.')
				node->cnt = 2;
			x++;
		}
		x = 0;
		y++;
	}
}

int	ft_normy(t_node *node)
{
	int	y;
	int	i;

	i = node->piece->y - 1;
	y = node->piece->y;
	while (i > 0)
	{
		if (ft_strchr(node->piece->board[i], '*'))
			return (y);
		else
			y--;
		i--;
	}
	return (y);
}

int	ft_trimx(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i > 0 && str[i] && str[i] == '.')
		i--;
	return (i + 1);
}

int	ft_normx(t_node *node)
{
	int	x;
	int	j;
	int	len;

	j = 1;
	x = ft_trimx(node->piece->board[0]);
	while (j < node->piece->y)
	{
		len = ft_trimx(node->piece->board[j]);
		if (len > x)
			x = len;
		j++;
	}
	return (x);
}

void	ft_possiblemove(t_node *node, char player) /*List possible's move and choose one*/
{
	int	i;
	int	j;
	int	y;
	int	x;

	i = 0;
	j = 0;
	y = ft_normy(node) - 1;
	x = ft_normx(node) - 1;
	while (i < node->map->y - y)
	{
		while (j < node->map->x - x)
		{
			node->cnt = 0;
			ft_canfill(node, i, j - ft_counttrim(node), player);
			if (node->cnt == 1)
				ft_addcoord(&(node->move), j - ft_counttrim(node), i);
			j++;
		}
		j = 0;
		i++;
	}
}
