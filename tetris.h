#ifndef TETRIS_H
# define TETRIS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <time.h>
# include <unistd.h>

typedef struct	game
{
	int	grid[20][16];
	int	piece[4][4];
	int	piece_x;
	int	piece_y;
	int	score;
}	game;

//GRID FUNCTIONS
void    create_grid(int grid[20][16]);
void    print_grid(game *g, int grid[20][16]);

//temporariliy here:
extern int	pieces[7][4][4];
void	print_piece(game *g);

#endif
