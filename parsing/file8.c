/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:09:02 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/23 15:21:24 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_is_digit(char *line)
{
	int		i;
	char	*tmp_line;

	i = 0;
	tmp_line = ft_strtrim(line, " ");
	if (tmp_line[i] == '+')
		i++;
	while (tmp_line[i])
	{
		if (!ft_isdigit(tmp_line[i]))
			return (free(tmp_line), 1);
		i++;
	}
	return (free(tmp_line), 0);
}

void	free_map_info(t_map_info *map_info)
{
	free(map_info->no_texture);
	free(map_info->so_texture);
	free(map_info->we_texture);
	free(map_info->ea_texture);
	free(map_info->c_texture);
	free(map_info->f_texture);
	free(map_info);
}

void	free_paths(t_map_info *map_info)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(map_info->paths[i]);
		i++;
	}
	free(map_info->paths);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_all_parsing(t_map_info *map_info)
{
	int	i;

	i = 0;
	free_paths(map_info);
	free_map(map_info->map);
	free_map_info(map_info);
	ft_free_matrix(map_info->map1, map_info->map1_height);
	while (map_info->texture[i])
	{
		free(map_info->texture[i]);
		i++;
	}
	if (map_info->img)
		free (map_info->img);
}
