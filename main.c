#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "prototypes.h"

int	main(void)
{
	t_square	**board;

	board = fill_board();
	draw_board(board);
	board[4][4].owner = board[6][4].owner;
	board[4][4].piece = board[6][4].piece;
	board[6][4].owner = 0;
	board[6][4].piece = 0;
	erase_board();
	draw_board(board);
	free_board(board);
	return (0);
}
