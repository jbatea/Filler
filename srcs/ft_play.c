/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:37:28 by jbateau           #+#    #+#             */
/*   Updated: 2017/05/16 18:15:45 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_find_mid(t_node *node)
{
	//TODO: while savemove find mid
	//	node->y = move->y;
	//	node->x = move->x;
}

void	ft_avgcmp(t_node *node, t_coord *move)
{
	int		min;
	int		cur;
	int		x;
	int		y;

	x = node->my_spawn->x;
	y = node->my_spawn->y;
	min = ft_abs(x - node->x) + ft_abs(y - node->y);
	cur = ft_abs(x - move->x) + ft_abs(y - move->y);
	if (cur <= min)
		ft_addcoord(&(node->save-move), move->x, move->y);
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
		ft_find_mid(node);
	}
}
