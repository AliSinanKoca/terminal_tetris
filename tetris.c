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

void	check_input(game *g)
{
	char	input;

	if (read(STDIN_FILENO, &input, 1) <= 0)
		return ;
	if (input == 'a' || input == 'A')
		if (!check_collision(g, -1, 0))
			g->piece_x--;
	if (input == 'd' || input == 'D')
		if (!check_collision(g, 1, 0))
			g->piece_x++;
	if (input == 's' || input == 'S')
		if (!check_collision(g, 0, 1))
			g->piece_y++;
	/*if (input == 'w' || input == 'W")
		g->piece = rotate_piece(g); */
	if (input == ' ')
	{
		while (!check_collision(g, 0, 1))
			g->piece_y++;
		lock_piece(g);
	}
	if (input == 'q' || input == 'Q')
	{
		exit_game_mode();
		exit(0);
	}
}

void	game_over(void)
{
	exit_game_mode();
	printf("\e[1;1H\e[2J");
	printf("\n\n GAME OVER \n\n");
	exit(0);
}

int	main(void)
{
	game	*g;

	g = malloc(sizeof(game));
	if (!g)
		return (1);
	srand(time(NULL));
	enter_game_mode();
	create_grid(g->grid);
	spawn_piece(g);
	while (1)
	{
		apply_gravity(g);
		check_input(g);
		print_grid(g, g->grid);
		usleep(200000);
	}
	return (0);
}
