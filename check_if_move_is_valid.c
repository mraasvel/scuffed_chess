#include "prototypes.h"

void	put_input_error(char *move)
{
	ft_putstr("The input: '");
	ft_putstr(move);
	ft_putstr("' is not valid\n");
	ft_putstr("Please use the format 'letter-num-space-letter-num-space' (start then end position)\n");
	ft_putstr("Example: 'E2 E4'\n");
}

/*
** if input is valid, returns the number related to which piece is to be moved
** 0: pawn, 1: rook, 2: knight(H - horse) 3: bishop, 4: Queen, 5: King.
** if input is invalid, return (-1) and output error message
*/
int	check_if_input_is_valid(char *move)
{
	int x;
	int y;

	if (ft_strlen(move) != 5 || move[2] != ' ' || is_alpha(move[0]) == 0 || is_alpha(move[3]) == 0 || is_num(move[1]) == 0 || is_num(move[4]) == 0)
	{
		put_input_error(move);
		return (-1);
	}
	return (0);
}

int	check_knight_moves(char *move)
{
}
