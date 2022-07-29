/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vincent < >                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:50:40 by Vincent           #+#    #+#             */
/*   Updated: 2022/07/29 23:09:40 by Vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include <stdbool.h>
# include <stdlib.h>

void	play(char (*grid)[6][7], char player, int *last_y, int *last_x)
{
	int	user_input;
	int	counter;

	user_input = get_user_input(player);
	counter = 5;
	while (counter >= 0)
	{
		if ((*grid)[counter][user_input] == ' ')
		{
			(*grid)[counter][user_input] = player;
			*last_x = user_input;
			*last_y = counter;
			return ;
		}
		counter--;
	}
	printf("Column is full, try another.\n");
	play(grid, player, last_y, last_x);
}

bool	is_draw(char (*grid)[6][7])
{
	if ((*grid)[0][6] != ' ' && (*grid)[0][5] != ' '
		&& (*grid)[0][4] != ' ' && (*grid)[0][3] != ' '
		&& (*grid)[0][2] != ' ' && (*grid)[0][1] != ' '
		&& (*grid)[0][0] != ' ')
		return (true);
	return (false);
}

bool	player_won(char (*grid)[6][7], int last_y, int last_x)
{

}

bool	is_game_over(char (*grid)[6][7], char player, int last_y, int last_x)
{
	if (player_won(grid, last_y, last_x))
	{
		printf("Player %c won the game!", player);
		exit(0);
	}
	if (is_draw(grid))
	{

		printf("Draw.");
		exit(0);
	}
	return (false);
}

#endif
