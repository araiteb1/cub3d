/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:31:09 by ahaloui           #+#    #+#             */
/*   Updated: 2023/10/11 19:53:12 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void writing_error(char *str)
{
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	exit(1);
}

int check_extension_of_file(char *fileName)
{
	int len;

	len = 0;
	while (fileName[len])
		len++;
	if (fileName[len - 1] == 'b' && fileName[len - 2] == 'u'
		&& fileName[len - 3] == 'c' && fileName[len - 4] == '.')
		return (1);
	return (0);
}

int check_each_side(char **map, int i, int j)
{
	if (map[i][j + 1] == ' ' 
		|| map[i][j - 1] == ' ' 
			|| map[i - 1][j] == ' '
				|| map[i + 1][j] == ' ')
		return (0);
	return (1);
}

int isMapClosed(char **map, int num_lines)
{
	int i;
	int j;

	i = 0;
	while (i < num_lines)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' 
				|| map[i][j] == 'S' || map[i][j] == 'W' 
					|| map[i][j] == 'E')
			{
				if (!check_each_side(map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int get_numebr_player(char **map, int lineCount)
{
	int i;
	int j;
	int playerCount;

	i = 0;
	playerCount = 0;
	while (i < lineCount)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' 
				|| map[i][j] == 'W' || map[i][j] == 'E')
				playerCount++;
			j++;
		}
		i++;
	}
	if (playerCount != 1)
		return (0);
	return (1);
}

