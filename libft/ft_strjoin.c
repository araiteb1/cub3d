/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:06:07 by ahaloui           #+#    #+#             */
/*   Updated: 2022/11/11 10:34:14 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	char		*str;
	size_t		len;
	int			i;
	int			j;

	str = NULL;
	if (!s1 || !s2)
		return (str);
	else
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (str != NULL)
		{
			i = -1;
			while (s1[++i])
				str[i] = s1[i];
			j = -1;
			while (s2[++j])
				str[i++] = s2[j];
			str[i] = '\0';
		}
	}
	return (str);
}
