#ifndef TETRIS_H
# define TETRIS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <time.h>
# include <unistd.h>

extern int	pieces[7][4][4];

typedef struct game
{
	int	grid[20][16];
	int	piece[4][4];
	int	piece_x;
	int	piece_y;
	int	score;
}	game;

//TERMINAL CONTROL (term_cntl.c)
void	enter_game_mode(void);
void	exit_game_mode(void);

//GRID FUNCTIONS (grid.c)
int		is_piece_in_grid(game *g, int i, int j);
void	create_grid(int grid[20][16]);
void	print_grid(game *g, int grid[20][16]);

//LINE CLEARING AND SHIFTING (lines.c)
int		is_line_full(game *g, int j);
void	shift_lines(game *g, int j);
void	clear_top_line(game *g);
void	clear_shift_lines(game *g);

//GRAVITY AND COLLISION LOGIC (pieces_game.c)
int		check_collision(game *g, int mov_x, int mov_y);
void	spawn_piece(game *g);
void	lock_piece(game *g);
void	apply_gravity(game *g);

//PIECES MOVEMENT WITH USER INPUT (pieces_mov.c)
void	check_input(game *g);
void	rotate_piece(game *g);
void	copy_piece(int dest[4][4], int src[4][4]);

//PROGRAM END
void	game_over(game *g);
void	exit_protocol(game *g);

#endif
