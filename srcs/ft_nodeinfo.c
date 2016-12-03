/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:37:03 by jbateau           #+#    #+#             */
/*   Updated: 2016/12/03 15:37:25 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
 **Save piece's and map's board
*/

char	**ft_saveboard(int y)
{
	char	*line;
	char	**board;
	int		i;

	i = 0;
	line = NULL;
	board = (char **)malloc(sizeof(char *) * (y + 2));
	if (board)
	{
		while (i < y + 1 && get_next_line(0, &line) == 1)
		{
			board[i] = ft_strdup(line);
			ft_strdel(&line);
			i++;
		}
		board[i] = NULL;
	}
	return (board);
}

/*
 ** Received data cleaning
*/

char	**ft_normtab(char **tab, int y)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 1;
	tmp = (char **)malloc(sizeof(char *) * (y + 1));
	if (tmp)
	{
		while (i < y)
		{
			tmp[i] = ft_strdup(tab[j] + 4);
			ft_strdel(&tab[j]);
			i++;
			j++;
		}
		tmp[i] = NULL;
		ft_strdel(&tab[0]);
		free(tab);
	}
	return (tmp);
}

/*
 ** Save map's coordinates
*/

void	ft_mapchr(t_board **map)
{
	char	*line;

	get_next_line(0, &line);
	(*map)->x = ft_intchr(line, 1);
	(*map)->y = ft_intchr(line, 0);
	(*map)->board = ft_normtab(ft_saveboard((*map)->y), (*map)->y);
	ft_strdel(&line);
}

/*
 ** Save piece's coordinates
*/

void	ft_piecechr(t_board **piece)
{
	char	*line;

	get_next_line(0, &line);
	(*piece)->x = ft_intchr(line, 1);
	(*piece)->y = ft_intchr(line, 0);
	(*piece)->board = ft_saveboard((*piece)->y - 1);
	ft_strdel(&line);
}

/*
 ** Parse then save current turn's map and piece
*/

int		ft_nodeinfo(t_node **node)
{
	if ((*node)->map && (*node)->piece)
	{
		ft_mapchr(&(*node)->map);
		ft_piecechr(&(*node)->piece);
		return (1);
	}
	return (0);
}
