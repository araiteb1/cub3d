/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:44:51 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/18 22:07:19 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

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

int check_each_side(char **map, int i, int j)
{
	if (map[i][j + 1] == ' '
		|| map[i][j - 1] == ' '
		|| map[i + 1][j] == ' '
		|| map[i - 1][j] == ' ')
		return (1);
	return (0);
}

int isMapClosed(t_map_info *map_info)
{
	int i;
	int j;

	i = 0;
	while (map_info->map[i])
	{
		j = 0;
		while (map_info->map[i][j])
		{
			if (map_info->map[i][j] == '0' || map_info->map[i][j] == 'N' 
				|| map_info->map[i][j] == 'S' || map_info->map[i][j] == 'W' 
				|| map_info->map[i][j] == 'E')
			if (check_each_side(map_info->map, i, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int get_nb_player(t_map_info *map_info)
{
	int i;
	int j;
	int playerCount;

	i = 0;
	playerCount = 0;
	while (i < map_info->num_lines)
	{
		j = 0;
		while (map_info->map[i][j])
		{
			if (map_info->map[i][j] == 'N' || map_info->map[i][j] == 'S' 
				|| map_info->map[i][j] == 'W' || map_info->map[i][j] == 'E')
				playerCount++;
			j++;
		}
		i++;
	}
	if (playerCount != 1)
		return (1);
	return (0);
}
