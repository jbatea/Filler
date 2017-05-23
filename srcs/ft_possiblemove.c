/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_possiblemove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:28:59 by jbateau           #+#    #+#             */
/*   Updated: 2017/05/23 16:44:20 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
 ** Check if new form can be placed
*/

void		ft_canfill(t_node *node, int i, int j, char player)
{
	int		x;
	int		y;
	char	piece;
	char	map;

	x = 0;
	y = 0;
	while (y < node->piece->y)
	{
		while (x < node->piece->x)
		{
			if (y + i < node->map->y && x + j < node->map->x)
			{
				map = node->map->board[y + i][x + j];
				piece = node->piece->board[y][x];
				if (piece == '*' && map && map == player)
					node->cnt++;
				if (piece == '*' && map && map != player && map != '.')
					node->cnt = 2;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int			ft_normy(t_node *node)
{
	int		y;
	int		i;

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

int			ft_trimx(char *str)
{
	int		i;

	i = ft_strlen(str) - 1;
	while (i > 0 && str[i] && str[i] == '.')
		i--;
	return (i + 1);
}

int			ft_normx(t_node *node)
{
	int		x;
	int		j;
	int		len;

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

/*
 ** List possible's move and choose one
*/

void		ft_possiblemove(t_node *node, char player)
{
	int		i;
	int		j;
	int		y;
	int		x;

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
