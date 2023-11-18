/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:01:19 by ahaloui           #+#    #+#             */
/*   Updated: 2022/11/06 21:27:46 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char	*s, unsigned int start, size_t	len)
{
	unsigned int	i;
	unsigned int	l_src;
	char			*destination;

	if (!s)
		return (NULL);
	l_src = ft_strlen(s);
	if (len > l_src)
		len = l_src;
	destination = (char *)malloc(sizeof(char) * (len + 1));
	if (!destination)
		return (NULL);
	i = 0;
	while (i < len && start <= l_src)
	{
		destination[i] = s[start];
		start++;
		i++;
	}
	destination[i] = '\0';
	return (destination);
}
