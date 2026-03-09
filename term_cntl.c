#include "tetris.h"

static struct termios original_term;

void	enter_game_mode(void)
{
	struct termios  term;

	tcgetattr(STDIN_FILENO, &original_term);
	term = original_term;
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

	fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

void	exit_game_mode(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &original_term);
}
