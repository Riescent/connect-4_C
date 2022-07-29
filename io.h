/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vincent < >                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:34:14 by Vincent           #+#    #+#             */
/*   Updated: 2022/07/29 22:49:44 by Vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H
# include <stdio.h>

void	print_grid(char (*grid)[6][7])
{
	int	counter_1;
	int	counter_2;

	counter_1 = 0;
	counter_2 = 0;
	while (counter_1 < 6)
	{
		printf("-----------------------------\n");
		while (counter_2 < 7)
		{
			printf("| %c ", (*grid)[counter_1][counter_2]);
			counter_2++;
		}
		printf("|\n");
		counter_2 = 0;
		counter_1++;
	}
	printf("-----------------------------\n");
	printf("  1   2   3   4   5   6   7\n");
}

int	get_int(const char *print)
{
	int	return_integer;

	printf("%s", print);
	if (!scanf("%i", &return_integer))
	{
		printf("An error occured, make sure you input an integer. ");
		while (return_integer != '\n' && return_integer != EOF)
			return_integer = getchar();
		return_integer = get_int(print);
	}
	return (return_integer);
}

int	get_user_input(char player, int *last_y, int *last_x)
{
	char	print[24];
	int		return_value;

	sprintf(print, "It is player %c's turn: ", player);
	return_value = get_int(print);
	while (return_value < 1 || return_value > 7)
	{
		printf("Needs to be between 1 and 7\n");
		return_value = get_int(print);
	}
	return (return_value - 1);
}

#endif
