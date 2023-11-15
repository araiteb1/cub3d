/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:24:37 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/09 02:41:57 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int get_biggest_line(char **map)
{
	int i;
	int j;
	int max;

	i = 0;
	max = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}


void fill_map(t_map_info *map_info)
{
	int i;
	int j;
	int max;

	i = 0;
	max = get_biggest_line(map_info->map);
	map_info->num_cols = max;
	while (map_info->map[i])
	{
		if (check_all_spaces(map_info->map[i]))
			writing_error("Map is not valid");
		j = ft_strlen(map_info->map[i]);
		while (j < max)
		{
			map_info->map[i] = ft_strjoin(map_info->map[i], " ");
			j++;
		}
		i++;
	}
}

int surround_map(char **map, int lineCount)
{
	int i;
	int j;

	i = 0;
	while (i < lineCount)
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || i == lineCount - 1)
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

int check_all_spaces(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != ' ')
            return (0);
        i++;
    }
    return (1);
}