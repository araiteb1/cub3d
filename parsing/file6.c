/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:51:18 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/24 11:41:44 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_line_of_map(char *line)
{
	int	i;

	i = 0;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'W'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	get_biggest_line(char **map)
{
	int	i;
	int	j;
	int	max_line;

	i = 0;
	max_line = 0;
	while (map[i])
	{
		j = ft_strlen(map[i]);
		if (j > max_line)
			max_line = j;
		i++;
	}
	return (max_line);
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

int	surround_map(t_map_info *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->num_lines)
	{
		j = 0;
		while (map_info->map[i][j])
		{
			if (i == 0 || i == map_info->num_lines - 1)
			{
				if (map_info->map[i][j] != '1' && map_info->map[i][j] != ' ')
					return (1);
			}
			else if (j == 0 || j == (int)ft_strlen(map_info->map[i]) - 1)
			{
				if (map_info->map[i][j] != '1' && map_info->map[i][j] != ' ')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
