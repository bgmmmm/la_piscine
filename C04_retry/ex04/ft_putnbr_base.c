/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boseo <boseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:40:18 by boseo             #+#    #+#             */
/*   Updated: 2022/02/17 12:02:03 by boseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	not_duplicate(char *base)
{
	int	baselen;
	int	i;
	int	j;

	baselen = ft_strlen(base);
	i = 0;
	while (i < baselen - 1)
	{
		j = i + 1;
		while (j < baselen)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid(char *base)
{
	int	baselen;

	baselen = ft_strlen(base);
	if (baselen < 2)
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (0);
		base++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	num;
	int	i;
	int	baselen;

	baselen = ft_strlen(base);
	if (!(is_valid(base) && not_duplicate(base)))
		return ;
	if (nbr < 0)
		ft_putchar('-');
	num = nbr;
	i = 1;
	while ((nbr > 0 && num >= baselen) || (nbr < 0 && num <= -baselen))
	{
		num /= baselen;
		i *= baselen;
	}
	while (i >= 1)
	{
		if (nbr < 0)
			ft_putchar(base[-(nbr / i)]);
		else
			ft_putchar(base[nbr / i]);
		nbr = nbr % i;
		i /= baselen;
	}
}
