/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:01:37 by ahaloui           #+#    #+#             */
/*   Updated: 2022/11/11 10:32:39 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t					i;
	const unsigned char		*source;
	unsigned char			*destination;

	if (!dst && !src)
		return (NULL);
	i = 0;
	source = (const unsigned char *)src;
	destination = (unsigned char *)dst;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}
