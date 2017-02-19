/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:31:22 by jbateau           #+#    #+#             */
/*   Updated: 2016/12/03 15:46:41 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
 ** Use to find starting position
*/

char		ft_playerchr(void)
{
	char	player;
	char	*line;

	get_next_line(0, &line);
	if (ft_strchr(line, '1'))
		player = 'O';
	else
		player = 'X';
	ft_strdel(&line);
	return (player);
}

/*
 ** Play current move or exit program
*/

void		ft_output(t_node *node, int *n)
{
	if (node->move)
		ft_printf("%d %d\n", node->y, node->x);
	else
	{
		ft_printf("0 0\n");
		*n = 0;
	}
}

char		ft_op(char player)
{
	if (player == 'X')
		return ('O');
	return ('X');
}

/*
 ** Main game's functions, save data then find best play each turn
*/

int			main(void)
{
	t_node	*node;
	char	player;
	int		n;

	n = 1;
	node = NULL;
	player = ft_playerchr();
	while (n)
	{
		if ((node = ft_nodeinit()) && ft_nodeinfo(&node))
		{
			ft_possiblemove(node, player);
			if (node->move)
				ft_findspawn(node, &(node->op_spawn), ft_op(player));
			ft_play(node);
			ft_output(node, &n);
			ft_freenode(node);
		}
	}
	return (0);
}
