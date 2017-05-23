/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addcoord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:43:35 by jbateau           #+#    #+#             */
/*   Updated: 2017/05/23 13:25:11 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
 ** Init new node with the proper move
*/

t_coord		*ft_initcoord(int x, int y)
{
	t_coord	*new;

	new = (t_coord *)malloc(sizeof(t_coord));
	if (new)
	{
		new->x = x;
		new->y = y;
		new->average = NULL;
		new->next = NULL;
	}
	return (new);
}

/*
 ** Add new node to linked list's moves
*/

void		ft_addcoord(t_coord **coord, int x, int y)
{
	t_coord	*new;
	t_coord	*tmp;

	tmp = *coord;
	new = ft_initcoord(x, y);
	if (new)
	{
		if (!tmp)
			*coord = new;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}
