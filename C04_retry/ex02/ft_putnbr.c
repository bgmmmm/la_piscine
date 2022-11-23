/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boseo <boseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:48:27 by boseo             #+#    #+#             */
/*   Updated: 2022/02/14 11:48:31 by boseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	num;
	int	tmp;
	int	i;

	num = nb;
	if (nb < 0)
		ft_putchar('-');
	i = 1;
	tmp = num;
	while (tmp > 9 || tmp < -9)
	{
		tmp /= 10;
		i *= 10;
	}
	while (i >= 1)
	{
		if (nb < 0)
			ft_putchar(-(num / i) + '0');
		else
			ft_putchar(num / i + '0');
		num = num % i;
		i /= 10;
	}
}
