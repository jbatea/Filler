/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findspawn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:40:55 by jbateau           #+#    #+#             */
/*   Updated: 2016/12/03 15:41:12 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		ft_average(t_coord *coord)
{
	t_coord	*cur;

	cur = coord;
	while (cur)
	{
		coord->average->x = coord->average->x + cur->x;
		coord->average->y = coord->average->y + cur->y;
		cur = cur->next;
	}
	coord->average->x = coord->average->x / coord->average->nb;
	coord->average->y = coord->average->y / coord->average->nb;
}

int			ft_averageinit(t_coord *coord)
{
	t_average	*new;

	new = NULL;
	if (!(coord->average))
	{
		new = (t_average *)malloc(sizeof(t_average));
		if (!new)
			return (0);
		new->x = 0;
		new->y = 0;
		new->nb = 0;
		coord->average = new;
	}
	return (1);
}

void		ft_findspawn(t_node *node, t_coord **coord, char player)
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
				ft_addcoord(coord, x, y);
				if (ft_averageinit(*coord))
					(*coord)->average->nb = (*coord)->average->nb + 1;
			}
			x++;
		}
		x = 0;
		y++;
	}
	ft_average(*coord);
}
