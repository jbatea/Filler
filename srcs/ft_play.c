/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:41:00 by jbateau           #+#    #+#             */
/*   Updated: 2017/05/23 16:39:42 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_avgcmp(t_node *node, t_coord *move)
{
	int		min;
	int		cur;
	int		x;
	int		y;

	x = node->map->x / 2;
	y = node->map->y / 2;
	min = ft_abs(x - node->x) + ft_abs(y - node->y);
	cur = ft_abs(x - move->x) + ft_abs(y - move->y);
	if (cur <= min)
	{
		node->x = move->x;
		node->y = move->y;
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
