/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:52:42 by jbateau           #+#    #+#             */
/*   Updated: 2017/05/16 18:10:06 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
#include <stdio.h>

typedef struct		s_board
{
	int		x;
	int		y;
	char	**board;
}					t_board;

typedef struct		s_average
{
	int		x;
	int		y;
	int		nb;
}					t_average;

typedef struct		s_coord
{
	int					x;
	int					y;
	struct s_average	*average;
	struct s_coord		*next;
}					t_coord;

typedef struct		s_node
{
	t_board	*map;
	t_board	*piece;
	t_coord	*move;
	t_coord	*save_move;
	t_coord	*my_spawn;
	int		cnt;
	int		x;
	int		y;
}					t_node;

int					ft_nodeinfo(t_node **node);
t_node				*ft_nodeinit(void);
void				ft_freenode(t_node *node);
void				ft_possiblemove(t_node *node, char player);
void				ft_addcoord(t_coord **coord, int x, int y);
void				ft_findspawn(t_node *node, t_coord **coord, char player);
void				ft_play(t_node *node);
int					ft_counttrim(t_node *node);

#endif
