/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vincent < >                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:34:22 by Vincent           #+#    #+#             */
/*   Updated: 2022/07/30 00:32:18 by Vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "game.h"
#define PLAYER_X 'X'
#define PLAYER_O 'O'

void	create_grid(char (*grid)[6][7])
{
	int	counter_1;
	int	counter_2;

	counter_1 = 0;
	counter_2 = 0;
	while (counter_1 < 6)
	{
		while (counter_2 < 7)
		{
			(*grid)[counter_1][counter_2] = ' ';
			counter_2++;
		}
		counter_2 = 0;
		counter_1++;
	}
}

int	main(void)
{
	char	grid[6][7];
	int		last_y;
	int		last_x;

	create_grid(&grid);
	print_grid(&grid);
	while (1)
	{
		play(&grid, PLAYER_X, &last_y, &last_x);
		print_grid(&grid);
		is_game_over(&grid, PLAYER_X, last_y, last_x);
		play(&grid, PLAYER_O, &last_y, &last_x);
		print_grid(&grid);
		is_game_over(&grid, PLAYER_O, last_y, last_x);
	}
}
