/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:30:22 by ahaloui           #+#    #+#             */
/*   Updated: 2023/10/11 14:01:57 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int free_colors(char **colors)
{
	int color;
	int i;

	i = 0;
	color = create_trgb(0, ft_atoi(colors[0]),
		ft_atoi(colors[1]), ft_atoi(colors[2]));
	while (colors[i])
	{
		free(colors[i]);
		i++;
	}
	free(colors);
	return (color);
}

int get_color(char *line)
{
	char **colors;
	int i;

	if (count_number_of_commas(line) != 2)
		writing_error("Colors");
	i = 1;
	while (line[i] == ' ')
		i++;
	colors = ft_split(&line[i], ',');
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(colors[i]) < 0 
			|| ft_atoi(colors[i]) > 255 
				|| !only_digit(colors[i])
					|| ft_size_of_array(colors) != 3)
						writing_error("Colors");
		i++;
	}
	return (free_colors(colors));
}


int valide_texture(char *line)
{
	int i;
	char *tmp_line;

	i = 0;
	while (line[i] == ' ' && line[i])
		i++;
	while (line[i] != ' ' && line[i])
		i++;
	tmp_line = ft_substr(line, 0, i);
	if (ft_strcmp(tmp_line, "NO"))
		return (free(tmp_line),1);
	else if (ft_strcmp(tmp_line, "SO"))
		return (free(tmp_line),1);
	else if (ft_strcmp(tmp_line, "WE"))
		return (free(tmp_line),1);
	else if (ft_strcmp(tmp_line, "EA"))
		return (free(tmp_line),1);
	else if (ft_strcmp(tmp_line, "F"))
		return (free(tmp_line),1);
	else if (ft_strcmp(tmp_line, "C"))
		return (free(tmp_line),1);
	return (free(tmp_line),0);
}

void fill_textures(t_map_info **map_info, char *line)
{
	int i;
	char *tmp_line;

	i = 0;
	while (line[i] != ' ' && line[i])
		i++;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	
	tmp_line = ft_substr(line, 0, i);
	if(ft_strcmp(tmp_line, "NO"))
		(*map_info)->no_texture = ft_strdup(line);
	else if(ft_strcmp(tmp_line, "SO"))
	 	(*map_info)->so_texture = ft_strdup(line);
	else if(ft_strcmp(tmp_line, "WE"))
	 	(*map_info)->we_texture = ft_strdup(line);
	else if(ft_strcmp(tmp_line, "EA"))
	 	(*map_info)->ea_texture = ft_strdup(line);
	else if(ft_strcmp(tmp_line, "C"))
	{
	 	(*map_info)->c_color = get_color(line);
		(*map_info)->c_texture = ft_strdup(line);
	}
	else if(ft_strcmp(tmp_line, "F"))
	{
		(*map_info)->f_color = get_color(line);
		(*map_info)->f_texture = ft_strdup(line);
	}
	free(tmp_line);
}

void read_textures(int fd, t_map_info **map_info)
{
	(void)map_info;
	char *line;
	int count_textures;

	line = get_next_line(fd);
	count_textures = 0;
	while (line)
	{
		if (ft_strcmp(line, "\n"))
		{
			free(line);
			line = get_next_line(fd);
		}
		else
		{
			if (valide_texture(line))
			{
				fill_textures(map_info, line);
				free(line);
				count_textures++;
			}
			else
				writing_error("Textures Missign");
			line = get_next_line(fd);
			if (count_textures == 6)
				break;
		}
	}
	if (!check_textures(map_info))
        writing_error("Missing textures");
	free(line);
}
