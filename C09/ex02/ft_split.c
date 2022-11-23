/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boseo <boseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:55:05 by boseo             #+#    #+#             */
/*   Updated: 2022/02/24 18:12:49 by boseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str && is_charset(*str, charset))
			str++;
		else if (*str && !is_charset(*str, charset))
		{	
			count++;
			while (*str && !is_charset(*str, charset))
				str++;
		}
	}
	return (count);
}

char	*new_strcpy(char *dest, char *src, int start, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = 0;
	return (dest);
}

int	word_cpy(char *str, char *charset, char **arr)
{
	int	i;
	int	j;
	int	start;
	int	len;

	i = -1;
	j = -1;
	while (str[++i])
	{
		len = 0;
		while (str[i] && is_charset(str[i], charset))
			i++;
		start = i;
		while (str[i] && !is_charset(str[i], charset))
		{
			i++;
			len++;
		}
		arr[++j] = (char *)malloc(sizeof(char) * len + 1);
		if (arr[j] == 0)
			return (0);
		arr[j] = new_strcpy(arr[j], str, start, len);
	}
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		word_count;

	if (str == 0)
		return (0);
	word_count = count_word(str, charset);
	arr = (char **)malloc(sizeof(char *) * word_count + 1);
	if (!arr)
		return (0);
	if (word_cpy(str, charset, arr) != 1)
		return (0);
	arr[word_count] = 0;
	return (arr);
}
