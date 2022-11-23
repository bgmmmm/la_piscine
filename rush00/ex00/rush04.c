/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsekan <minsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:02:50 by minsekan          #+#    #+#             */
/*   Updated: 2022/02/06 14:24:31 by minsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_char(int x, int y, int i, int j)
{
	if ((((i == 1 && j == 1) || (i == y && j == x)) && !(x == 1 && i == y)
			&& !(y == 1 && j == x)) || (x == 1 && y == 1))
		ft_putchar('A');
	else if (((i == 1 && j == x) || (i == y && j == 1)))
		ft_putchar('C');
	else if (!(i == 1 || i == y) && !(j == 1 || j == x))
		ft_putchar(' ');
	else
		ft_putchar('B');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x < 1 || y < 1)
		return ;
	i = 0;
	while (++i <= y)
	{
		j = 0;
		while (++j <= x)
		{
			print_char(x, y, i, j);
		}
		ft_putchar('\n');
	}
}
