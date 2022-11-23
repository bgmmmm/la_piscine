/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boseo <boseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:26:12 by boseo             #+#    #+#             */
/*   Updated: 2022/02/13 19:51:14 by boseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;		

	i = 0;
	while (dest[i] != 0)
		i++;
	while (nb > 0 && *src != 0)
	{
		dest[i] = *src;
		src++;
		i++;
		nb--;
	}
	dest[i] = 0;
	return (dest);
}
