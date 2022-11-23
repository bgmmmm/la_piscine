/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boseo <boseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:12:15 by boseo             #+#    #+#             */
/*   Updated: 2022/02/21 11:19:08 by boseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

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

char	*ft_strdup(char *src)
{
	char	*arr;
	int		srclen;
	int		i;

	srclen = ft_strlen(src);
	arr = (char *)malloc((sizeof(char) * srclen) + 1);
	if (arr == 0)
		return (0);
	i = 0;
	while (src[i])
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char**av)
{
	int			i;
	t_stock_str	*tab;

	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
		return (0);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}
