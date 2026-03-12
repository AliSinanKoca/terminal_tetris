#include "tetris.h"

/*typedef struct	game
{
	int	grid[20][20];
	int	piece[4][4];
	int	piece_x;
	int	piece_y;
	int	score;
} game; */

void	game_over(game *g)
{
	exit_game_mode();
	printf("\e[1;1H\e[2J");
	printf("\n\n GAME OVER \n\n");
	free(g);
	exit(0);
}

void	exit_protocol(game *g)
{
	exit_game_mode();
	printf("\e[1;1H\e[2J");
	printf("\n\n Error. \n\n");
	free(g);
	exit(1);
}

int	main(void)
{
	game	*g;

	g = malloc(sizeof(game));
	if (!g)
		exit_protocol(g);
	srand(time(NULL));
	enter_game_mode();
	create_grid(g->grid);
	spawn_piece(g);
	while (1)
	{
		check_input(g);
		apply_gravity(g);
		print_grid(g, g->grid);
		usleep(200000);
	}
	return (0);
}
