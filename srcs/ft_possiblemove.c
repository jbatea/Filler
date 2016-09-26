#include "../includes/filler.h"

t_move	*ft_initmove(char *str)
{
	t_move	*move;

	move = (t_move *)malloc(sizeof(t_move));
	if (move)
	{
		move->str = ft_strdup(str);
		move->next = NULL;
	}
	return (move);
}

void	ft_addmove(t_node **node, char *str)
{
	t_move	*new;
	t_move	*tmp;

	tmp = (*node)->move;
	new = ft_initmove(str);
	if (new)
	{
		if (!tmp)
			(*node)->move = new;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

void	ft_possiblemove(t_node **node, char player)
{
	if (player)
	{
		if ((*node)->map && (*node)->piece)
		{
			ft_addmove(node, "8 1\n"); /*Check all possible pos in tab*/
			ft_addmove(node, "8 2\n"); /*Add them to move list*/
			/*Then check opponnent pos (N,S,E,W) and add the proper move to play str, and finally printf node->play*/
		}
	}
}
