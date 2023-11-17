/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:06:42 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/16 16:29:41 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_paths(t_map_info *map_info)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (open(map_info->paths[i], O_RDONLY) == -1)
			return (0);
		i++;
	}
	return (1);
}


char *get_path(char *line)
{
	int i;
	char *path;

	i = 0;
	while (line[i] != ' ' && line[i])
		i++;
	path = ft_strtrim(line + i, " ");
	return (path);
}

void init_path(t_map_info *map_info)
{
	map_info->paths = malloc(sizeof(char *) * 5);
	map_info->paths[0] = get_path(map_info->no_texture);
	map_info->paths[1] = get_path(map_info->so_texture);
	map_info->paths[2] = get_path(map_info->we_texture);
	map_info->paths[3] = get_path(map_info->ea_texture);
	map_info->paths[4] = NULL;
	if (!check_paths(map_info))
			writing_error("Wrong path to texture");
}

void free_paths(t_map_info *map_info)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(map_info->paths[i]);
		i++;
	}
	free(map_info->paths);
}