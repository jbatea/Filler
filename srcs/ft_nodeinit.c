/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:46:26 by jbateau           #+#    #+#             */
/*   Updated: 2016/12/03 15:50:36 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_board		*ft_initboard(void)
{
	t_board	*new;

	new = (t_board *)malloc(sizeof(t_board));
	if (new)
	{
		new->x = 0;
		new->y = 0;
		new->board = NULL;
	}
	return (new);
}

/*
 **Allocate memory for structures and init them
*/

t_node		*ft_nodeinit(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node)
	{
		node->map = ft_initboard();
		node->piece = ft_initboard();
		node->op_spawn = NULL;
		node->move = NULL;
		node->cnt = 0;
		node->x = 0;
		node->y = 0;
	}
	return (node);
}
