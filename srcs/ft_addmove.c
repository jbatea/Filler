#include "../includes/filler.h"

t_move	*ft_initmove(int x, int y) /*Init new node with the proper move*/
{
	t_move	*move;

	move = (t_move *)malloc(sizeof(t_move));
	if (move)
	{
		move->x = x;
		move->y = y;
		move->next = NULL;
	}
	return (move);
}

void	ft_addmove(t_node **node, int x, int y) /*Add new node to linked list's moves*/
{
	t_move	*new;
	t_move	*tmp;

	tmp = (*node)->move;
	new = ft_initmove(x, y);
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
