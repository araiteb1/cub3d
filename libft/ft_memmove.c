/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:30:35 by ahaloui           #+#    #+#             */
/*   Updated: 2022/11/04 13:03:47 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destination;
	unsigned char	*source;

	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	if (src < dst)
	{
		while (len)
		{
			len--;
			destination[len] = source[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
