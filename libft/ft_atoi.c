/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:22:33 by ahaloui           #+#    #+#             */
/*   Updated: 2022/11/12 13:58:30 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	is_white_space(char c)
{
	if ((c >= '\t' && c <= '\r' ) || c == ' ' )
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	signe;
	int	result;

	result = 0;
	signe = 1;
	while (is_white_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = (10 * result) + *str - '0';
		str++;
	}
	return (result * signe);
}
