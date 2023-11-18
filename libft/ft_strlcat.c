/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:13:16 by ahaloui           #+#    #+#             */
/*   Updated: 2022/11/05 22:31:36 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	l_dst;
	size_t	l_src;

	if (!dstsize)
		return (ft_strlen(src));
	l_src = ft_strlen(src);
	l_dst = ft_strlen(dst);
	len = l_dst;
	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	while (dstsize - 1 - len && *src)
	{
		dst[len] = *src++;
		dst[len + 1] = '\0';
		len++;
	}
	return (l_src + l_dst);
}
