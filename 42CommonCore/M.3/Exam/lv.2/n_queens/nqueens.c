/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 09:19:13 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 16:08:22 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nqueens.h"

// check if it's safe to place a queen in this position
// keep in mind that 'board' stores the ROW position
// of the queen in each column
int	safe_placing(int row, int col, int *board)
{
	int	i;

	i = 0;
	// loop through each column
	while (i < col)
	{
		// check the line, the diagonal upward and then downward
		// CHECK 1 — Same row: row == board[i]
		// CHECK 2 — Upper-left diagonal: board[i] - row == col - i
		// CHECK 3 — Lower-left diagonal: row - board[i] == col - i
		if (row == board[i] || (board[i] - row == col - i) || (row
				- board[i] == col - i))
			return (0); // Conflict found — this position is NOT safe
		i++;
	}
	// safe to place
	return (1);
}

void	placing_queens(int col, int input, int *board)
{
	int	i;
	int	row;

	i = 0;
	row = 0;
	// if we have placed all the queens in each collomns => write the result
	if (col == input)
	{
		while (i < input)
		{
			if (i > 0)
				printf(" ");
			printf("%d", board[i]);
			i++;
		}
		printf("\n");
		return ;
	}
	// loop over each row looking for a safe place
	while (row < input)
	{
		if (safe_placing(row, col, board))
		{
			// if safe place, put the queen and go on
			board[col] = row;
			placing_queens(col + 1, input, board);
		}
		row++;
	}
}

int	main(int ac, char *av[])
{
	int	input;
	int	board[27];

	if (ac == 2)
	{
		input = atoi(av[1]);
		if (input <= 0)
			return (1);
		placing_queens(0, input, board);
		return (0);
	}
	else
		return (1);
}

/*
i = the column of an already-placed queen
board[i] = the row where that queen sits
*/