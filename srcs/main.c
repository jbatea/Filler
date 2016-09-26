#include "../includes/filler.h"

char	ft_playerchr(void) /*Use to find starting position*/
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

int	main(void) /*Main game's functions, save data then find best play each turn*/
{
	t_node	*node;
	int	i;
	char	player;

	node = NULL;

	i = 1;
	player = ft_playerchr();
	while (1)
	{	
		if ((node = ft_nodeinit()))
		{
			ft_nodeinfo(&node);
			ft_possiblemove(&node, player);
			ft_printall(node);
			ft_printf("8 %d\n", i);
			i++;
			ft_freenode(node);
		}
	}
	return (0);
}
