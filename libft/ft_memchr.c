/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:29:05 by ahaloui           #+#    #+#             */
/*   Updated: 2022/11/10 17:34:37 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*source;
	unsigned int	i;

	source = (unsigned char *)s;
	i = 0;
	while (i < n && source[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (NULL);
	return ((char *)(source + i));
}
