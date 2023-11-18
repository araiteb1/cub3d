/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:52:11 by ahaloui           #+#    #+#             */
/*   Updated: 2022/11/12 15:04:17 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	size_needle;
	size_t	i;
	size_t	count;
	int		tmp;

	if (!haystack && !len && needle != NULL)
		return (NULL);
	size_needle = ft_strlen(needle);
	if ((char *)needle == (char *)haystack || size_needle == 0 || !needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		count = 0;
		tmp = i;
		while (haystack[i] == needle[count] && count < size_needle && i < len)
		{
			count++;
			i++;
		}
		if (count == size_needle)
			return ((char *)(haystack + tmp));
		i = ++tmp;
	}
	return (NULL);
}
