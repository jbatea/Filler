#include "../includes/filler.h"

t_coord		*ft_initcoord(int x, int y) /*Init new node with the proper move*/
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

void	ft_addcoord(t_coord **coord, int x, int y) /*Add new node to linked list's moves*/
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
