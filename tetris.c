#include "tetris.h"

/*typedef struct	game
{
	int	grid[20][20];
	int	piece[4][4];
	int	piece_x;
	int	piece_y;
	int	score;
} game; */

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

int	check_collisions(game *g)
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
			{
				if (g->grid[py + pj + 1][px + pi] == 2)
					return (1);
			}
			pi++;
		}
		pj++;
	}
	return (0);
}

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

void	apply_gravity(game *g)
{
	if (!check_collisions(g))
		g->piece_y++;
	else
	{
		lock_piece(g);
		spawn_piece(g);
	}
}

int	main(void)
{
	int	i = 0;
	int	j = 0;
	game	*g;

	g = malloc(sizeof(game));
	if (!g)
		return (1);
	srand(time(NULL));
	create_grid(g->grid);
	spawn_piece(g);
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			apply_gravity(g);
			print_grid(g, g->grid);
			j++;
			usleep(200000);
		}
		i++;
	}
	return (0);
}
