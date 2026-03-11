#include "tetris.h"

void	spawn_piece(game *g)
{
	int	i = 0;
	int	j = 0;
	int	idx = rand() % 7;

	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			g->piece[j][i] = pieces[idx][j][i];
			i++;
		}
		j++;
	}
	g->piece_x = 6;
	g->piece_y = 0;
}

//Checks if position of piece in grid is occupied.
//mov_x position offset for right or left, mov_y for up or down.
int	check_collision(game *g, int mov_x, int mov_y)
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
			if (g->piece[pj][pi] == 1
				&& g->grid[py + pj + mov_y][px + pi + mov_x] == 2)
					return (1);
			pi++;
		}
		pj++;
	}
	return (0);
}

//Write piece in grid. (Grid directly modified here).
void	lock_piece(game *g)
{
	int	i;
	int	j;
	int	px;
	int	py;

	px = g->piece_x;
	py = g->piece_y;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (g->piece[j][i] == 1)
				g->grid[py + j][px + i] = 2;
			i++;
		}
		j++;
	}
}

//If next position down is empty move down automatically.
//If after spawning position is already occupied: game_over.
void	apply_gravity(game *g)
{
	if (!check_collision(g, 0, 1))
		g->piece_y++;
	else
	{
		lock_piece(g);
		clear_shift_lines(g);
		spawn_piece(g);
		if (check_collision(g, 0, 0))
			game_over();
	}
}
