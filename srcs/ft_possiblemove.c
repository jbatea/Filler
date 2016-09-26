#include "../includes/filler.h"

void	ft_possiblemove(t_node **node, char player) /*List possible's move and choose one*/
{
	if (player)
	{
		if ((*node)->map && (*node)->piece)
		{
			ft_addmove(node, 8, 1); /*Check all possible pos in tab*/
			ft_addmove(node, 8, 2); /*Add them to move list*/
			/*Then check opponnent pos (N,S,E,W) and add the proper move to play str, and finally printf node->play*/
		}
	}
}
