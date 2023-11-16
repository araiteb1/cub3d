/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:24:37 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/16 19:22:58 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_biggest_line(char **map)
{
	int	i;
	int	j;
	int	max_line;

	i = 0;
	max_line = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > max_line)
			max_line = j;
		i++;
	}
	return (max_line);
}


void	fill_map(t_map_info *map_info)
{
	int	i;
	int	j;
	int	max_line;

	i = 0;
	max_line = get_biggest_line(map_info->map);
	map_info->num_cols = max_line;
	while (map_info->map[i])
	{
		if (check_all_spaces(map_info->map[i]))
			writing_error("Map is not valid");
		j = ft_strlen(map_info->map[i]);
		while (j < max_line)
		{
			map_info->map[i] = ft_strjoin(map_info->map[i], " ");
			j++;
		}
		i++;
	}
}

int	surround_map(char **map, int nbr_lines)
{
	int	i;
	int	j;

	i = 0;
	while (i < nbr_lines)
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || i == nbr_lines - 1)
			{
				if (map[i][j] != '1' && map[i][j] != ' ' )
					return (0);
			}
			else if (j == 0 || j == (int)ft_strlen(map[i]) - 1)
			{
				if (map[i][j] != '1' && map[i][j] != ' ')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_all_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
