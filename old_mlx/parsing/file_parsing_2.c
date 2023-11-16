/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:33:25 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/16 19:20:16 by ahaloui          ###   ########.fr       */
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
		return (0);
	return (1);
}

int	check_line_of_map(char *line)
{
	int	i;

	i = 0;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'W' && line[i] != 'E' 
			&& line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	skip_textures(t_map_info *map_info, char *line)
{
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	if (ft_strcmp(line, map_info->no_texture))
		return (1);
	else if (ft_strcmp(line, map_info->so_texture))
		return (1);
	else if (ft_strcmp(line, map_info->we_texture))
		return (1);
	else if (ft_strcmp(line, map_info->ea_texture))
		return (1);
	else if (ft_strcmp(line, map_info->c_texture))
		return (1);
	else if (ft_strcmp(line, map_info->f_texture))
		return (1);
	return (0);
}

int	help_count_lines(int fd, t_map_info *map_info, char *line)
{
	int	size_map;

	size_map = 0;
	(void)map_info;
	while (line)
	{
		if (ft_strcmp(line, "\n") || !check_line_of_map(line))
			writing_error("Map lines Or characters are not valid");
		else
			size_map++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (size_map);
}

int	count_lines(int fd, t_map_info *map_info)
{
	char	*line;

	fd = open(map_info->fileName, O_RDONLY);
	if (fd == -1)
		writing_error("Failed to open file");
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strcmp(line, "\n") || skip_textures(map_info, line))
		{
			free(line);
			line = get_next_line(fd);
		}
		else
			break ;
	}
	return (help_count_lines(fd, map_info, line));
}

void	read_map_lines(int fd, t_map_info *map_info, char *line)
{
	int	size_map;
	int	len;

	size_map = 0;
	map_info->num_lines = count_lines(fd, map_info);
	map_info->map = malloc(sizeof(char *) * (map_info->num_lines + 1));
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		len = ft_strlen(line);
		while (len > 0 && line[len - 1] == ' ')
			len--;
		map_info->map[size_map] = ft_substr(line, 0, len);
		size_map++;
		free(line);
		line = get_next_line(fd);
	}
	map_info->map[count_lines(fd, map_info)] = NULL;
	close(fd);
}

void	read_map(int fd, t_map_info *map_info)
{
	int		count_textures;
	char	*line;

	fd = open(map_info->fileName, O_RDONLY);
	if (fd == -1)
		writing_error("Failed to open file");
	line = get_next_line(fd);
	count_textures = 0;
	while (line)
	{
		if (ft_strcmp(line, "\n") || skip_textures(map_info, line))
		{
			if (skip_textures(map_info, line))
				count_textures++;
			if (count_textures > 6)
				writing_error("Textures Duplicated or missing");
			free(line);
			line = get_next_line(fd);
		}
		else
			break ;
	}
	read_map_lines(fd, map_info, line);
}
