/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:19:32 by ahaloui           #+#    #+#             */
/*   Updated: 2022/11/25 14:23:24 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < (dstsize - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_length;
	size_t	src_length;

	i = 0;
	if ((!dst && !dstsize))
		return (0);
	dest_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (dstsize <= dest_length)
		return (src_length + dstsize);
	while (i < dstsize - dest_length - 1 && src[i] != '\0')
	{
		dst[i + dest_length] = src[i];
		i++;
	}
	dst[i + dest_length] = '\0';
	return (dest_length + src_length);
}

char	*ft_strjoin(char *stash, char *buff)
{
	char	*str;
	int		len;

	if (!stash)
	{
		stash = malloc(1);
		stash[0] = '\0';
	}
	if (!stash || !buff)
		return (NULL);
	len = ft_strlen(stash) + ft_strlen(buff);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, stash, ft_strlen(stash) + 1);
	ft_strlcat(str, buff, (ft_strlen(stash) + ft_strlen(buff) + 1));
	str[len] = '\0';
	return (free(stash), str);
}
