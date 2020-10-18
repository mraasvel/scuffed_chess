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

int	check_knight_moves(t_square **board, char *starting_pos, char *target_pos)
{
	int ciX;
	int ciY;

	ciX = starting_pos[0] - target_pos[0];
	ciY = starting_pos[1] - target_pos[1];
	if (ft_abs(ciX - ciY) == 1)
		return (1);
	if (ft_abs(ciX - ciY) == 3)
		return (1);
	return (0);
}

int	check_pawn_move(t_square **board, char *starting_pos, char *target_pos)
{
	int ownera;
	int ownerb;
	int ownerc;
	int	constant;

	ownera = board[starting_pos[1] - '0' - 1][starting_pos[0] - 'A' - 1].owner;
	ownerb = board[target_pos[1] - '0' - 1][target_pos[0] - 'A' - 1].owner;
	ownerc = board[target_pos[1] - '0' - 2][target_pos[0] - 'A' - 1].owner;
	constant = 1;
	if (ownera == 2)
		constant = -1;
	if ((starting_pos[0] - target_pos[0]) * constant == 1)
		if (ft_abs(starting_pos[1] - target_pos[1]) == 1 && ownerb != 0 && ownerb != ownera)
			return (1);
	if (starting_pos[0] != target_pos[0])
		return (0);
	
	
	return (0);
}
