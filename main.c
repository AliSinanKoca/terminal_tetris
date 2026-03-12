#include "tetris.h"

void	print_commands(void)
{
	printf("LEFT: A  RIGHT: D  DOWN: S  ROTATE: W  QUIT: Q\nHARD DROP: SPACE\n");
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
	g->score = 0;
	while (1)
	{
		check_input(g);
		apply_gravity(g);
		print_grid(g, g->grid);
		printf("SCORE: %d \n", g->score);
		print_commands();
		usleep(250000);
	}
	return (0);
}
