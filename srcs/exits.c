#include "tetris.h"

//free() here.
void	game_over(game *g)
{
	exit_game_mode();
	printf("\e[1;1H\e[2J");
	printf("\n\n GAME OVER \n\n");
	free(g);
	exit(0);
}

//In case of error. free() here.
void	exit_protocol(game *g)
{
	exit_game_mode();
	printf("\e[1;1H\e[2J");
	printf("\n\n Error. \n\n");
	free(g);
	exit(1);
}
