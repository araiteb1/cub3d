/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:05:11 by ahaloui           #+#    #+#             */
/*   Updated: 2022/11/12 15:16:27 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calcule(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i = 1;
	}
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*ft_get_str(char *new, long n1, int len)
{
	if (n1 < 0)
	{
		new[0] = '-';
		n1 *= -1;
	}
	new[len - 1] = '\0';
	while (n1 != 0)
	{
		new[--len - 1] = (n1 % 10) + '0';
		n1 /= 10;
	}
	return (new);
}

char	*ft_itoa(int n)
{
	char	*new;
	int		len;
	long	n1;

	if (n == 0)
	{
		new = malloc(2);
		if (!new)
			return (NULL);
		new[0] = '0';
		new[1] = 0;
		return (new);
	}
	n1 = (long)n;
	len = calcule(n1) + 1;
	new = (char *)malloc(len);
	if (!new)
		return (NULL);
	return (ft_get_str(new, n1, len));
}
