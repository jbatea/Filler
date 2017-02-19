/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:37:28 by jbateau           #+#    #+#             */
/*   Updated: 2016/12/03 15:45:10 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_avgcmp(t_node *node, t_coord *move)
{
	int	min;
	int	cur;
	int	x;
	int	y;

	x = node->op_spawn->x;
	y = node->op_spawn->y;
	min = ft_abs(x - node->x) + ft_abs(y - node->y);
	cur = ft_abs(x - move->x) + ft_abs(y - move->y);
	if (cur <= min)
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
