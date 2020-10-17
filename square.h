#ifndef SQUARE_H
# define SQUARE_H

/*
** Pieces: 1: 'P' (pawn) 2: 'R' (rook) 3: 'H' (knight/horse) 4: 'B' (bishop) 5: 'Q' (queen) 6: 'K' (king)
** Black empty square = ',' ; white empty square = '.'
** Owner: empty: 0, white: 1, black: 2
** color square: white: 1, black: 2
*/
typedef struct	s_square
{
	int	piece;
	int	owner;
	int	color;
}				t_square;

#endif