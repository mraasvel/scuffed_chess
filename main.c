#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "prototypes.h"

int	main(void)
{
	t_square	**board;

	board = fill_board();
	draw_board(board);
	int d;
	d = check_pawn_move(board, "d7", "d5");
	printf("%d\n", d);
	free_board(board);
	return (0);
}
