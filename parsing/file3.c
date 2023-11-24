/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:58:19 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/24 12:32:13 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_textures(t_map_info *map_info)
{
	if (!map_info->no_texture
		|| !map_info->so_texture
		|| !map_info->we_texture
		|| !map_info->ea_texture 
		|| !map_info->c_texture 
		|| !map_info->f_texture)
		return (1);
	return (0);
}

char	*get_path(char *str)
{
	int		start;
	char	*path;

	if (!str)
		return (NULL);
	start = 0;
	while (str[start] != ' ' && str[start])
		start++;
	path = ft_strtrim(&str[start], " ");
	if (!path)
		return (NULL);
	return (path);
}

int	check_paths(t_map_info *map_info)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (open(map_info->paths[i], O_RDONLY) == -1)
			return (1);
		i++;
	}
	return (0);
}

int	init_path(t_map_info *map_info)
{
	map_info->paths = malloc(sizeof(char *) * 5);
	if (!map_info->paths)
		return (1);
	map_info->paths[0] = get_path(map_info->no_texture);
	pars_textures(map_info, map_info->paths[0], &map_info->texture[0]);
	map_info->paths[1] = get_path(map_info->so_texture);
	pars_textures(map_info, map_info->paths[1], &map_info->texture[1]);
	map_info->paths[2] = get_path(map_info->we_texture);
	pars_textures(map_info, map_info->paths[2], &map_info->texture[2]);
	map_info->paths[3] = get_path(map_info->ea_texture);
	pars_textures(map_info, map_info->paths[3], &map_info->texture[3]);
	map_info->paths[4] = NULL;
	if (!map_info->paths[0] || !map_info->paths[1]
		|| !map_info->paths[2] || !map_info->paths[3])
		return (1);
	if (check_paths(map_info))
		return (1);
	return (0);
}

int	read_textures(t_map_info *map_info)
{
	int		fd;
	int		nb_textures;
	char	*line;

	fd = open(map_info->file_name, O_RDONLY);
	if (fd == -1)
		writing_error("Failed to open file");
	nb_textures = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strcmp(line, "\n"))
			free(line);
		else
		{
			if (help_read_textures(map_info, line, &nb_textures))
				return (1);
			if (nb_textures == 6)
				break ;
		}
		line = get_next_line(fd);
	}
	return (0);
}
