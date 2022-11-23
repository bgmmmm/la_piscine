/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boseo <boseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:13:33 by boseo             #+#    #+#             */
/*   Updated: 2022/02/13 19:50:34 by boseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *a)
{
	unsigned int	len;

	len = 0;
	while (*a != 0)
	{
		len++;
		a++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	destlen;
	unsigned int	srclen;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (destlen >= size)
		return (size + srclen);
	while (*dest != 0)
		dest++;
	while (size - destlen - 1 > 0 && *src != 0)
	{
		*dest = *src;
		src++;
		dest++;
		size--;
	}
	*dest = 0;
	return (destlen + srclen);
}
