#include <unistd.h>
#include "prototypes.h"

#ifndef USE_UNICODE
char *pieces[] = {
	"P",
	"R",
	"H",
	"B",
	"Q",
	"K",
	"P",
	"R",
	"H",
	"B",
	"Q",
	"K"
};
#else
char *pieces[] = {
	"♙",
	"♖",
	"♘",
	"♗",
	"♕",
	"♔",
	"♟︎",
	"♜",
	"♞",
	"♝",
	"♛",
	"♚"
};
#endif

/*
** 1 = Pawn, 2 = Rook, 3 = Horse/knight, 4 = Bishop, 5 = Queen, 6 = King
*/
void	draw_piece(t_square square)
{
	if (square.piece == 0)
		return ;
#ifndef USE_UNICODE
	// unicode unsupported: render piece color depending on owner
	if (square.owner == 1)
		ft_putstr("\033[34m");
	else if (square.owner == 2)
		ft_putstr("\033[30m");
#else
	// unicode supported: render everything as black
	ft_putstr("\033[30m");
#endif
	ft_putstr(" ");
	ft_putstr(pieces[(square.piece - 1) + (square.owner - 1) * 6]);
	ft_putstr(" ");
}

void	draw_board(t_square **board)
{
	int i;
	int j;

	i = 0;
	ft_putstr("   A  B  C  D  E  F  G  H\n");
	ft_putstr(" ┌────────────────────────┐\n");
	while (i < 8)
	{
		ft_putint(8 - i);
		ft_putstr("│");
		j = 0;
		while (j < 8)
		{
			if (board[i][j].color == 1)
				ft_putstr("\033[42m\033[1m");
			else
				ft_putstr("\033[47m\033[1m");
			if (board[i][j].owner == 0)
				ft_putstr("   ");
			else
				draw_piece(board[i][j]);
			ft_putstr("\033[0m");
			j++;
		}
		ft_putstr("│");
		ft_putint(8 - i);
		write(1, "\n", 1);
		i++;
	}
	ft_putstr(" └────────────────────────┘\n");
	ft_putstr("   A  B  C  D  E  F  G  H\n");
}

void	erase_board(void)
{
	int i;

	ft_putstr("\33[A");
	i = 0;
	while (i < 11)
	{
		ft_putstr("\33[2K\33[A");
		i++;
	}
}