/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:44:51 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/21 18:10:35 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_player_positon(t_map_info *map_info, int i, int j)
{
	map_info->info_player->x_pos = i;
	map_info->info_player->y_pos = j;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	check_each_side(char **map, int i, int j)
{
	if (map[i][j + 1] == ' '
		|| map[i][j - 1] == ' '
		|| map[i + 1][j] == ' '
		|| map[i - 1][j] == ' ')
		return (1);
	return (0);
}

int	check_is_map_closed(t_map_info *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (map_info->map[i])
	{
		j = 0;
		while (map_info->map[i][j])
		{
			if (map_info->map[i][j] == 'N' 
				|| map_info->map[i][j] == 'S' || map_info->map[i][j] == 'W' 
				|| map_info->map[i][j] == 'E')
				init_player_positon(map_info, i, j);
			if (map_info->map[i][j] == '0' || map_info->map[i][j] == 'N' 
				|| map_info->map[i][j] == 'S'
				|| map_info->map[i][j] == 'W' 
				|| map_info->map[i][j] == 'E')
				if (check_each_side(map_info->map, i, j))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_nb_player(t_map_info *map_info)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (i < map_info->num_lines)
	{
		j = 0;
		while (map_info->map[i][j])
		{
			if (map_info->map[i][j] == 'N' || map_info->map[i][j] == 'S' 
				|| map_info->map[i][j] == 'W' || map_info->map[i][j] == 'E')
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (1);
	return (0);
}
