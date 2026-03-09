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

void	apply_gravity(game *g)
{
	if (g->piece_y < 20)
		g->piece_y++;
}

void	move_piece(game *g)
{
	spawn_piece(g);
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
	while (i < 20)
	{
		create_grid(g->grid);
		spawn_piece(g);
		j = 0;
		while (j < 20)
		{
			apply_gravity(g);
			print_grid(g, g->grid);
			j++;
			usleep(200000);
		}
		i++;
		usleep(200000);
	}
	return (0);
}
