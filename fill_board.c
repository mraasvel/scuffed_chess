#include <stdlib.h>
#include "prototypes.h"

void		fill_in_white_pieces(t_square **board)
{
	int i;

	i = 0;
	while (i < 8)
	{
		board[6][i].owner = 1;
		board[7][i].owner = 1;
		board[6][i].piece = 1;
		i++;
	}
	board[7][0].piece = 2;
	board[7][1].piece = 3;
	board[7][2].piece = 4;
	board[7][3].piece = 5;
	board[7][4].piece = 6;
	board[7][5].piece = 4;
	board[7][6].piece = 3;
	board[7][7].piece = 2;
}

void		fill_in_black_pieces(t_square **board)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		board[1][i].owner = 2;
		board[0][i].owner = 2;
		board[1][i].piece = 1;
		i++;
	}
	board[0][0].piece = 2;
	board[0][1].piece = 3;
	board[0][2].piece = 4;
	board[0][3].piece = 5;
	board[0][4].piece = 6;
	board[0][5].piece = 4;
	board[0][6].piece = 3;
	board[0][7].piece = 2;
}

void		fill_in_empty_line(t_square *board, int type)
{
	int i;

	i = 0;
	if (type == 1)
	{
		while (i < 8)
		{
			board[i].piece = 0;
			board[i].color = 1;
			board[i].owner = 0;
			board[i + 1].piece = 0;
			board[i + 1].color = 2;
			board[i + 1].owner = 0;
			i += 2;
		}
	}
	else
	{
		while (i < 8)
		{
			board[i].piece = 0;
			board[i].color = 2;
			board[i].owner = 0;
			board[i + 1].piece = 0;
			board[i + 1].color = 1;
			board[i + 1].owner = 0;
			i += 2;
		}
	}
}

t_square	**fill_board(void)
{
	t_square	**board;
	int			i;

	board = (t_square**)malloc(8 * sizeof(t_square*));
	i = 0;
	while (i < 8)
	{
		board[i] = (t_square*)malloc(8 * sizeof(t_square));
		if (i % 2 == 0)
			fill_in_empty_line(board[i], 1);
		else
			fill_in_empty_line(board[i], 2);
		i++;
	}
	fill_in_black_pieces(board);
	fill_in_white_pieces(board);
	return (board);
}

int			free_board(t_square **board)
{
	int i;

	i = 0;
	while (i < 8)
	{
		free(board[i]);
		i++;
	}
	free(board);
	return (0);
}