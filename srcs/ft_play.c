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

int		ft_opspawn(t_node *node, t_coord *op_spawn, t_coord *move)
{
	int	min;
	int	cur;
	int	op_x;
	int	op_y;

	op_x = op_spawn->average->x;
	op_y = op_spawn->average->y;
	min = ft_abs(op_x - node->x) + ft_abs(op_y - node->y);
	cur = ft_abs(op_x - move->x) + ft_abs(op_y - move->y);
	if (cur <= min)
		return (1);
	return (0);
}

void	ft_avgcmp(t_node *node, t_coord *move)
{
	int	min;
	int	cur;
	int	x;
	int	y;

	x = node->my_spawn->x;
	y = node->my_spawn->y;
	min = ft_abs(x - node->x) + ft_abs(y - node->y);
	cur = ft_abs(x - move->x) + ft_abs(y - move->y);
	if (cur >= min || (cur == min && node->op_spawn &&
				ft_opspawn(node, node->op_spawn, move)))
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
