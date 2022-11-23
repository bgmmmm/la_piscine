/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boseo <boseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:19:08 by boseo             #+#    #+#             */
/*   Updated: 2022/02/13 19:51:30 by boseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*i;
	char	*j;

	if (*to_find == 0)
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			i = str;
			j = to_find;
			while (*j != 0 && *i == *j)
			{
				i++;
				j++;
			}
			if (*j == 0)
				return (str);
		}
		str++;
	}
	return (0);
}
