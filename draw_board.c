#include <unistd.h>
#include "prototypes.h"

/*
** 1 = Pawn, 2 = Rook, 3 = Horse/knight, 4 = Bishop, 5 = Queen, 6 = King
*/
void	draw_piece(t_square square)
{
	if (square.piece == 0)
		return ;
	if (square.owner == 1)
		ft_putstr("\033[35mW");
	else if (square.owner == 2)
		ft_putstr("\033[30mB");
	if (square.piece == 1)
		write(1, "P", 1);
	else if (square.piece == 2)
		write(1, "R", 1);
	else if (square.piece == 3)
		write(1, "H", 1);
	else if (square.piece == 4)
		write(1, "B", 1);
	else if (square.piece == 5)
		write(1, "Q", 1);
	else if (square.piece == 6)
		write(1, "K", 1);
}

void	draw_board(t_square **board)
{
	int i;
	int j;

	i = 0;
	ft_putstr("  A B C D E F G H\n");
	ft_putstr(" ┌────────────────┐\n");
	while (i < 8)
	{
		ft_putint(8 - i);
		ft_putstr("│");
		j = 0;
		while (j < 8)
		{
			if (board[i][j].color == 1)
				ft_putstr("\033[42m");
			else
				ft_putstr("\033[47m");
			if (board[i][j].owner == 0)
				write(1, "  ", 2);
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
	ft_putstr(" └────────────────┘\n");
	ft_putstr("  A B C D E F G H\n");
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