/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vincent < >                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:50:40 by Vincent           #+#    #+#             */
/*   Updated: 2022/07/29 22:42:23 by Vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include <stdbool.h>
# include <stdlib.h>

void	play(char (*grid)[6][7], char player)
{
	int	user_input;

	user_input = get_user_input(player);
	if ((*grid)[5][user_input] == ' ')
		(*grid)[5][user_input] = player;
	else if ((*grid)[4][user_input] == ' ')
		(*grid)[4][user_input] = player;
	else if ((*grid)[3][user_input] == ' ')
		(*grid)[3][user_input] = player;
	else if ((*grid)[2][user_input] == ' ')
		(*grid)[2][user_input] = player;
	else if ((*grid)[1][user_input] == ' ')
		(*grid)[1][user_input] = player;
	else if ((*grid)[0][user_input] == ' ')
		(*grid)[0][user_input] = player;
	else
	{
		printf("Column is full, please try another.\n");
		play(grid, player);
	}
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

char	player_won(char (*grid)[6][7], last_played_y, last_played_x)
{

}

bool	is_game_over(char (*grid)[6][7])
{
	char	winning_player;

	winning_player = player_won(grid);
	if (winning_player != ' ')
	{
		printf("Player %c won the game!", winning_player);
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
