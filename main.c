/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vincent < >                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:34:22 by Vincent           #+#    #+#             */
/*   Updated: 2022/07/29 22:40:48 by Vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "game.h"

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

	create_grid(&grid);
	while (1)
	{
		print_grid(&grid);
		play(&grid, 'X');
		print_grid(&grid);
		is_game_over(&grid);
		play(&grid, 'O');
		is_game_over(&grid);
	}
}
