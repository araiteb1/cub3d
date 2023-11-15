/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:29:15 by ahaloui           #+#    #+#             */
/*   Updated: 2023/10/11 12:30:14 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2 [i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == '\0' && s2 [i] == '\0')
		return (1);
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
} 
int only_digit(char *color)
{
	int i = 0;
	while (color[i])
	{
		if (!ft_isdigit(color[i]) 
			&& color[i] != ' '
				&& color[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

int ft_size_of_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int count_number_of_commas(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	return (count);
}
