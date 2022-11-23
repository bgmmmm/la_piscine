/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boseo <boseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:16:47 by boseo             #+#    #+#             */
/*   Updated: 2022/02/16 16:07:49 by boseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(unsigned char c)
{
	int		num;
	int		i;
	char	*arr;
	char	hex[10];

	num = c;
	arr = "0123456789abcdef";
	i = 0;
	if (num < 16)
		ft_putchar('0');
	while (num > 0)
	{
		hex[i] = arr[num % 16];
		num /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_putchar(hex[i]);
	}
}		

void	ft_putstr_non_printable(char *str)
{
	if (*str == 0)
		return ;
	while (*str != 0)
	{
		if (!(*str >= ' ' && *str <= '~'))
		{
			ft_putchar('\\');
			print_hex(*str);
		}
		else
			ft_putchar(*str);
		str++;
	}
}
