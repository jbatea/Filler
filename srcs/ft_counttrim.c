#include "../includes/filler.h"

void	ft_lencmp(int *cnt, int *ret, int *min)
{
	if (*cnt < *ret && *cnt < *min)
		*ret = *cnt;
	if (*cnt < *ret)
	 	*min = *cnt;
	*cnt = 0;
}

int	ft_counttrim(t_node *node)
{
	int	x;
	int	y;
	int	cnt;
	int	ret;
	int	min;

	x = 0;
	y = 0;
	cnt = 0;
	ret = ft_strlen(node->piece->board[y]);
	min = ret;
	while (y < node->piece->y)
	{
		while (x < node->piece->x && node->piece->board[y][x] && node->piece->board[y][x] == '.')
		{
			cnt++;
			x++;
		}
		ft_lencmp(&cnt, &ret, &min);
		x = 0;
		y++;
	}
	return (ret);
}
