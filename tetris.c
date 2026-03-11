#include "tetris.h"

/*typedef struct	game
{
	int	grid[20][20];
	int	piece[4][4];
	int	piece_x;
	int	piece_y;
	int	score;
} game; */

/*void	apply_gravity(game *g)
{
	if (!check_collisions(g))
		g->piece_y++;
	else
	{
		lock_piece(g);
		clear_shift_lines(g);
		spawn_piece(g);
		if (check_game_over(g))
			game_over();
	}
} */

void	game_over(void)
{
//	exit_game_mode();
	printf("\e[1;1H\e[2J");
	printf("\n\n GAME OVER \n\n");
	exit(0);
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
