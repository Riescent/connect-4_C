/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_test.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vincent < >                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:28:15 by Vincent           #+#    #+#             */
/*   Updated: 2022/07/30 00:31:28 by Vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIN_TEST_H
# define WIN_TEST_H
# include <stdbool.h>

char	grid_test(char (*grid)[6][7], int y, int x)
{
	if (y < 0 || y > 5 || x < 0 || x > 6)
		return ('\0');
	return ((*grid)[y][x]);
}

bool	win_vertical(char (*grid)[6][7], int y, int x)
{
	if (grid_test(grid, y, x) == grid_test(grid, y - 1, x)
		&& grid_test(grid, y, x) == grid_test(grid, y - 2, x)
		&& grid_test(grid, y, x) == grid_test(grid, y - 3, x))
		return (true);
	if (grid_test(grid, y, x) == grid_test(grid, y + 1, x)
		&& grid_test(grid, y, x) == grid_test(grid, y + 2, x)
		&& grid_test(grid, y, x) == grid_test(grid, y + 3, x))
		return (true);
	if (grid_test(grid, y, x) == grid_test(grid, y + 1, x)
		&& grid_test(grid, y, x) == grid_test(grid, y - 1, x)
		&& grid_test(grid, y, x) == grid_test(grid, y - 2, x))
		return (true);
	if (grid_test(grid, y, x) == grid_test(grid, y - 1, x)
		&& grid_test(grid, y, x) == grid_test(grid, y + 1, x)
		&& grid_test(grid, y, x) == grid_test(grid, y + 2, x))
		return (true);
	return (false);
}

bool	win_horizontal(char (*grid)[6][7], int y, int x)
{
	if (grid_test(grid, y, x) == grid_test(grid, y, x - 1)
		&& grid_test(grid, y, x) == grid_test(grid, y, x - 2)
		&& grid_test(grid, y, x) == grid_test(grid, y, x - 3))
		return (true);
	if (grid_test(grid, y, x) == grid_test(grid, y, x + 1)
		&& grid_test(grid, y, x) == grid_test(grid, y, x + 2)
		&& grid_test(grid, y, x) == grid_test(grid, y, x + 3))
		return (true);
	if (grid_test(grid, y, x) == grid_test(grid, y, x + 1)
		&& grid_test(grid, y, x) == grid_test(grid, y, x - 1)
		&& grid_test(grid, y, x) == grid_test(grid, y, x - 2))
		return (true);
	if (grid_test(grid, y, x) == grid_test(grid, y, x - 1)
		&& grid_test(grid, y, x) == grid_test(grid, y, x + 1)
		&& grid_test(grid, y, x) == grid_test(grid, y, x + 2))
		return (true);
	return (false);
}

bool	win_diagonal_slash(char (*grid)[6][7], int y, int x)
{
	if (grid_test(grid, y, x) == grid_test(grid, y + 1, x - 1)
		&& grid_test(grid, y, x) == grid_test(grid, y + 2, x - 2)
		&& grid_test(grid, y, x) == grid_test(grid, y + 3, x - 3))
		return (true);
	if (grid_test(grid, y, x) == grid_test(grid, y - 1, x + 1)
		&& grid_test(grid, y, x) == grid_test(grid, y - 2, x + 2)
		&& grid_test(grid, y, x) == grid_test(grid, y - 3, x + 3))
		return (true);
	if (grid_test(grid, y, x) == grid_test(grid, y - 1, x + 1)
		&& grid_test(grid, y, x) == grid_test(grid, y + 1, x - 1)
		&& grid_test(grid, y, x) == grid_test(grid, y + 2, x - 2))
		return (true);
	if (grid_test(grid, y, x) == grid_test(grid, y + 1, x - 1)
		&& grid_test(grid, y, x) == grid_test(grid, y - 1, x + 1)
		&& grid_test(grid, y, x) == grid_test(grid, y - 2, x + 2))
		return (true);
	return (false);
}

bool	win_diagonal_anti_slash(char (*grid)[6][7], int y, int x)
{
	if (grid_test(grid, y, x) == grid_test(grid, y + 1, x + 1)
		&& grid_test(grid, y, x) == grid_test(grid, y + 2, x + 2)
		&& grid_test(grid, y, x) == grid_test(grid, y + 3, x + 3))
		return (true);
	if (grid_test(grid, y, x) == grid_test(grid, y - 1, x - 1)
		&& grid_test(grid, y, x) == grid_test(grid, y - 2, x - 2)
		&& grid_test(grid, y, x) == grid_test(grid, y - 3, x - 3))
		return (true);
	if (grid_test(grid, y, x) == grid_test(grid, y + 1, x + 1)
		&& grid_test(grid, y, x) == grid_test(grid, y - 1, x - 1)
		&& grid_test(grid, y, x) == grid_test(grid, y - 2, x - 2))
		return (true);
	if (grid_test(grid, y, x) == grid_test(grid, y - 1, x - 1)
		&& grid_test(grid, y, x) == grid_test(grid, y + 1, x + 1)
		&& grid_test(grid, y, x) == grid_test(grid, y + 2, x + 2))
		return (true);
	return (false);
}

#endif
