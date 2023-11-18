/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:55:44 by ahaloui           #+#    #+#             */
/*   Updated: 2022/11/12 13:45:55 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trim;
	size_t	i;
	size_t	pos_s;
	size_t	pos_e;

	if (!s1 || !set)
		return (NULL);
	pos_s = 0;
	pos_e = ft_strlen(s1);
	while (s1[pos_s] && ft_is_in_set(s1[pos_s], set))
		pos_s++;
	while (pos_e > pos_s && ft_is_in_set(s1[pos_e - 1], set))
		pos_e--;
	str_trim = (char *)malloc(sizeof(char) * ((pos_e - pos_s) + 1));
	if (!str_trim)
		return (NULL);
	i = 0;
	while (pos_s < pos_e)
	{
		str_trim[i] = s1[pos_s];
		i++;
		pos_s++;
	}
	str_trim[i] = '\0';
	return (str_trim);
}
