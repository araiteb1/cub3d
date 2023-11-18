/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:45:12 by ahaloui           #+#    #+#             */
/*   Updated: 2022/11/03 10:14:57 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*source1;
	unsigned char	*source2;

	source1 = (unsigned char *)s1;
	source2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while ((source1[i] == source2[i] && source1[i] != '\0')
		&& (source2[i] != '\0' && i < n))
		i++;
	if (i == n)
		i--;
	return (source1[i] - source2[i]);
}
