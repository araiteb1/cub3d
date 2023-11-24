/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:45:53 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/24 12:28:35 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	skip_textures(t_map_info *map_info, char *line)
{
	char	*tmp_line;

	tmp_line = ft_strtrim(line, " ");
	if (tmp_line[ft_strlen(tmp_line) - 1] == '\n')
		tmp_line[ft_strlen(tmp_line) - 1] = '\0';
	if (ft_strcmp(tmp_line, map_info->no_texture))
		return (free(tmp_line), 1);
	if (ft_strcmp(tmp_line, map_info->so_texture))
		return (free(tmp_line), 1);
	if (ft_strcmp(tmp_line, map_info->we_texture))
		return (free(tmp_line), 1);
	if (ft_strcmp(tmp_line, map_info->ea_texture))
		return (free(tmp_line), 1);
	if (ft_strcmp(tmp_line, map_info->c_texture))
		return (free(tmp_line), 1);
	if (ft_strcmp(tmp_line, map_info->f_texture))
		return (free(tmp_line), 1);
	return (free(tmp_line), 0);
}

int	count_lines_part_1(int fd, char *line)
{
	int	nb_lines;

	nb_lines = 0;
	while (line)
	{
		if (ft_strcmp(line, "\n") || check_line_of_map(line))
			writing_error("Map lines or characters are not valid");
		else
			nb_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (nb_lines);
}

int	count_lines_part_2(t_map_info *map_info)
{
	char	*line;
	int		nb_lines;
	int		fd;

	fd = open(map_info->file_name, O_RDONLY);
	if (fd == -1)
		writing_error("Failed to open file");
	nb_lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strcmp(line, "\n")
			|| skip_textures(map_info, line))
		{
			free(line);
			line = get_next_line(fd);
		}
		else
			break ;
	}
	nb_lines = count_lines_part_1(fd, line);
	return (nb_lines);
}

void	help_read_map(int fd, t_map_info *map_info, char *line)
{
	int	size_map;
	int	len;

	size_map = 0;
	map_info->num_lines = count_lines_part_2(map_info);
	map_info->map = malloc(sizeof(char *) * (map_info->num_lines + 1));
	if (!map_info->map)
		writing_error("Failed to allocate memory");
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		len = ft_strlen(line);
		while (line[len] == ' ' && line[len])
			len--;
		map_info->map[size_map] = ft_substr(line, 0, len);
		if (!map_info->map[size_map])
			writing_error("Failed to allocate memory");
		size_map++;
		free(line);
		line = get_next_line(fd);
	}
	map_info->map[map_info->num_lines] = NULL;
	fill_map(map_info);
	close(fd);
}

int	read_map(t_map_info *map_info)
{
	int		fd;
	int		nb_textures;
	char	*line;

	fd = open(map_info->file_name, O_RDONLY);
	if (fd == -1)
		writing_error("Failed to open file");
	line = get_next_line(fd);
	nb_textures = 0;
	while (line)
	{
		if (ft_strcmp(line, "\n") || skip_textures(map_info, line))
		{
			if (skip_textures(map_info, line))
				nb_textures++;
			if (nb_textures > 6)
				return (free(line), 1);
			free(line);
			line = get_next_line(fd);
		}
		else
			break ;
	}
	help_read_map(fd, map_info, line);
	return (0);
}
