#include "tetris.h"

//Checks if position of piece in grid is occupied.
//mov_x position offset for right or left, mov_y for up or down.
int	check_collision(game *g, int mov_x, int mov_y)
{
	int	x, y;
	int	i, j;
	int	px, py;

	px = g->piece_x;
	py = g->piece_y;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (g->piece[j][i] == 1)
			{
				x = px + i + mov_x;
				y = py + j + mov_y;
				if (y >= 20 || x < 0 || x >= 16)
					return (1);
				if (g->grid[y][x] == 2 || g->grid[y][x] == 1)
					return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
