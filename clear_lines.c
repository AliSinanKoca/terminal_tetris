#include "tetris.h"

int	is_line_full(game *g, int j)
{
	int	i;

	i = 1;
	while (i < 15)
	{
		if (g->grid[j][i] == 0)
			return (0);
		i++;
	}
	return (1);
}

//Shifts from cleared line up to the top, overwriting the full line.
void	shift_lines(game *g, int j)
{
	int	i;

	i = 0;
	while (j > 0)
	{
		i = 1;
		while (i < 15)
		{
			g->grid[j][i] = g->grid[j - 1][i];
			i++;
		}
		j--;
	}
}

void	clear_top_line(game *g, int j)
{
	int	i;

	i = 1;
	while (i < 15)
	{
		g->grid[0][i] = 0;
		i++;
	}
}

//Main line clearing and shifting function.
void	clear_shift_lines(game *g)
{
	int	j;

	j = 0;
	while (j < 20)
	{
		if (is_line_full(g, j))
		{
			shift_lines(g, j);
			clear_top_line(g, j);
			if (j > 0)
				j--;
		}
		j++;
	}
}
