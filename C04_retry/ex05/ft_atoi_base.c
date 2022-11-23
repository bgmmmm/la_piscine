/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boseo <boseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:23:47 by boseo             #+#    #+#             */
/*   Updated: 2022/02/20 18:23:49 by boseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		else if (*base == '\t' || *base == '\n' || *base == '\v'
			|| *base == '\f' || *base == '\r' || *base == ' ')
			return (0);
		base++;
	}
	return (1);
}

int	find_idx(char *str)
{
	int	minus;
	int	i;

	minus = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	if (minus % 2 == 1)
		i *= -1;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	minus;
	int	result;

	if (!(is_valid(base) && not_duplicate(base)))
		return (0);
	i = find_idx(str) - 1;
	result = 0;
	minus = 1;
	if (i < 0)
	{
		i = -i - 2;
		minus = -1;
	}
	while (str[++i])
	{
		j = 0;
		while (base[j] && str[i] != base[j])
			j++;
		if (base[j] == 0)
			break ;
		result = result * ft_strlen(base) + j;
	}
	return (result * minus);
}
