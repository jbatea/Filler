/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freenode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:42:27 by jbateau           #+#    #+#             */
/*   Updated: 2017/05/23 16:43:25 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_freeboard(t_board *board)
{
	if (board)
	{
		ft_tabfree(board->board);
		ft_memdel((void *)&board);
	}
}

void	ft_freecoord(t_coord *coord)
{
	t_coord	*tmp;
	t_coord	*ptmp;

	tmp = coord;
	if (tmp && tmp->average)
		ft_memdel((void *)&(tmp->average));
	while (tmp)
	{
		ptmp = tmp->next;
		free(tmp);
		tmp = ptmp;
	}
	coord = NULL;
}

/*
 ** Free all allocated memory
*/

void	ft_freenode(t_node *node)
{
	if (node)
	{
		ft_freeboard(node->map);
		ft_freeboard(node->piece);
		ft_freecoord(node->move);
		ft_memdel((void *)&node);
	}
}
