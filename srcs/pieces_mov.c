#include "tetris.h"

void	copy_piece(int dest[4][4], int src[4][4])
{
	int	i;
	int	j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			dest[j][i] = src[j][i];
			i++;
		}
		j++;
	}
}

//Also does a bit of wall-kicking.
void	rotate_piece(game *g)
{
	int	i;
	int	j;
	int	temp[4][4];
	int	backup[4][4];

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			backup[j][i] = g->piece[j][i];
			temp[j][i] = g->piece[3 - i][j];
			i++;
		}
		j++;
	}
	copy_piece(g->piece, temp);
	if (check_collision(g, 0, 0))
	{
		if (!check_collision(g, 1, 0))
			g->piece_x++;
		else if (!check_collision(g, -1, 0))
			g->piece_x--;
		else
			copy_piece(g->piece, backup);
	}
}

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
	if (input == 'w' || input == 'W')
		rotate_piece(g);
	if (input == ' ')
	{
		while (!check_collision(g, 0, 1))
			g->piece_y++;
		lock_piece(g);
	}
	if (input == 'q' || input == 'Q')
		game_over(g);
}
