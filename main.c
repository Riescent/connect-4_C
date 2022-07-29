/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vincent < >                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:34:22 by Vincent           #+#    #+#             */
/*   Updated: 2022/07/29 21:34:23 by Vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void    print_grid(char (*grid)[6][7])
{
        int     counter_1;
        int     counter_2;

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

void	play(char (*grid)[6][7], char player)
{
	int played_row;

	printf("Player %c: ", player);
	scanf
}

int	main(void)
{
	char	grid[6][7];

	create_grid(&grid);
	print_grid(&grid);

}
