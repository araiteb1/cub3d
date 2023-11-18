/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:53:55 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/18 22:12:02 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

int valide_texture(char *line)
{
	char	*tmp_line;
	char	*tmp_line1;
	int		start;

	start = 0;
	if (!line)
		return (1);
	tmp_line = ft_strtrim(line, " ");
	while (tmp_line[start] != ' ' && tmp_line[start])
		start++;
	tmp_line1 = ft_substr(tmp_line, 0, start);
	if (ft_strcmp(tmp_line1, "NO"))
		return (free(tmp_line1), free(tmp_line), 0);
	else if (ft_strcmp(tmp_line1, "SO"))
		return (free(tmp_line1), free(tmp_line), 0);
	else if (ft_strcmp(tmp_line1, "WE"))
		return (free(tmp_line1), free(tmp_line), 0);
	else if (ft_strcmp(tmp_line1, "EA"))
		return (free(tmp_line1), free(tmp_line), 0);
	else if (ft_strcmp(tmp_line1, "F"))
		return (free(tmp_line1), free(tmp_line), 0);
	else if (ft_strcmp(tmp_line1, "C"))
		return (free(tmp_line1), free(tmp_line), 0);
	return (free(tmp_line1), free(tmp_line), 1);
}

void help_fill_textures_1(t_map_info *map_info, char *line, char *tmp_line)
{
	if (ft_strcmp(tmp_line, "NO"))
		map_info->no_texture = ft_strdup(line);
	else if (ft_strcmp(tmp_line, "SO"))
		map_info->so_texture = ft_strdup(line);
	else if (ft_strcmp(tmp_line, "WE"))
		map_info->we_texture = ft_strdup(line);
	else if (ft_strcmp(tmp_line, "EA"))
		map_info->ea_texture = ft_strdup(line);
	else if (ft_strcmp(tmp_line, "C"))
	{
		map_info->c_color = get_color(line);
		map_info->c_texture = ft_strdup(line);
	}
	else if (ft_strcmp(tmp_line, "F"))
	{
		map_info->f_color = get_color(line);
		map_info->f_texture = ft_strdup(line);
	}
}

int help_fill_textures(t_map_info *map_info, char *line)
{
	int start;
	char *tmp_line;

	if (!line)
		return (1);
	start = 0;
	while (line[start] != ' ' && line[start])
		start++;
	tmp_line = ft_substr(line, 0, start);
	help_fill_textures_1(map_info, line, tmp_line);
	return (free(tmp_line), 0);
}

int	fill_textures(t_map_info *map_info, char *line)
{
	char	*tmp_line;
	int		start;
	
	start = 0;
	tmp_line = ft_strtrim(line, " ");
	if (tmp_line[ft_strlen(tmp_line) - 1] == '\n')
		tmp_line[ft_strlen(tmp_line) - 1] = '\0';
	if (help_fill_textures(map_info, tmp_line))
		return (free(tmp_line), 1);
	return (free(tmp_line), 0);
}

int	help_read_textures(t_map_info *map_info, char *line, int *nb_textures)
{
	if (!line)
		return (1);
	if (!valide_texture(line))
	{
		if (fill_textures(map_info, line))
			return (1);
		free(line);
		(*nb_textures)++;
	}
	else
		writing_error("Textures Missign");
	return (0);
}



