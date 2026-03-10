#include "tetris.h"

void	create_grid(int grid[20][16])
{
	int	i, j;

	j = 0;
	while (j < 19)
	{
		i = 0;
		while (i < 16)
		{
			if (i > 0 && i < 15)
				grid[j][i] = 0;
			else
				grid[j][i] = 1;
			i++;
		}
		j++;
	}
	i = 0;
	while (i < 16)
		grid[j][i++] = 2;
}

int	is_piece_in_grid(game *g, int i, int j)
{
	int	pi;
	int	pj;
	int	px;
	int	py;

	px = g->piece_x;
	py = g->piece_y;
	pj = 0;
	while (pj < 4)
	{
		pi = 0;
		while (pi < 4)
		{
			if (g->piece[pj][pi] == 1)
				if (py + pj == j && px + pi == i)
					return (1);
			pi++;
		}
		pj++;
	}
	return (0);
}

void	print_grid(game *g, int grid[20][16])
{
	int	i = 0;
	int	j = 0;

	printf("\e[1;1H\e[2J");
	while (j < 20)
	{
		i = 0;
		while (i < 16)
		{
			if (i == 0 || i == 15)
				printf("|");
			else if (is_piece_in_grid(g, i, j) == 1)
				printf("#");
			else if (grid[j][i] == 2)
				printf("#");
			else
				printf(" ");
			i++;
		}
		printf("\n");
		j++;
	}
	printf("\n");
}
