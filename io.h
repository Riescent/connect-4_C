/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ****** <************************>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:34:14 by ******            #+#    #+#             */
/*   Updated: 2022/07/30 12:34:16 by ******           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H
//print_center
# include <stdio.h>
# include <string.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <stdarg.h>

void	printf_center(const char *format, ...)
{
	va_list			args;
	char			print_me[1000];
	struct winsize	window_size;
	int				spaces_to_write;
	int				counter;

	va_start(args, format);
	vsnprintf(print_me, sizeof(print_me) / sizeof(print_me[0]), format, args);
	va_end(args);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size);
	spaces_to_write = window_size.ws_col / 2 - strlen(print_me) / 2;
	counter = 0;
	while (counter < spaces_to_write)
	{
		printf(" ");
		counter++;
	}
	printf("%s", print_me);
}

void	center_grid(void)
{
	struct winsize	window_size;
	int				counter;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size);
	counter = 0;
	while (counter < window_size.ws_row / 2 - 8)
	{
		printf("\n");
		counter++;
	}
}

void	print_grid(char (*grid)[6][7])
{
	int	counter_1;

	printf("\e[1;1H\e[2J");
	center_grid();
	counter_1 = 0;
	while (counter_1 < 6)
	{
		printf_center("-----------------------------\n");
		printf_center("| %c | %c | %c | %c | %c | %c | %c |\n",
			(*grid)[counter_1][0], (*grid)[counter_1][1], (*grid)[counter_1][2],
			(*grid)[counter_1][3], (*grid)[counter_1][4], (*grid)[counter_1][5],
			(*grid)[counter_1][6]);
		counter_1++;
	}
	printf_center("-----------------------------\n");
	printf_center("  1   2   3   4   5   6   7  \n\n");
}

int	get_int(const char *print)
{
	int	return_integer;

	printf_center("%s", print);
	if (!scanf("%i", &return_integer))
	{
		printf_center("An error occured, make sure you input an integer. ");
		while (return_integer != '\n' && return_integer != EOF)
			return_integer = getchar();
		return_integer = get_int(print);
	}
	return (return_integer);
}

int	get_user_input(char player)
{
	char	print[24];
	int		return_value;

	sprintf(print, "It is player %c's turn: ", player);
	return_value = get_int(print);
	while (return_value < 1 || return_value > 7)
	{
		printf_center("Needs to be between 1 and 7\n");
		return_value = get_int(print);
	}
	return (return_value - 1);
}

#endif
