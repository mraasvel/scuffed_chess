#ifndef PROTOTYPES_H
# define PROTOTYPES_H

#include "square.h"

/*
** fill_board.c
*/
t_square	**fill_board(void);
int			free_board(t_square **board);

/*
** output_utils.c
*/
void	ft_putint(int n);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);

/*
** draw_board.c
*/
void	draw_board(t_square **board);
void	erase_board(void);

/*
** check_utils.c
*/
int	is_alpha(char c);
int	is_num(char c);

/*
** check_if_move_is_valid.c
*/
int	check_if_input_is_valid(char *move);

#endif