/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:19:20 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/24 12:43:06 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2 [i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == '\0' && s2 [i] == '\0')
		return (1);
	return (0);
}

void ff ()
{
	system("leaks cub3D");
}

void	writing_error(char *str)
{
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	atexit(ff);
	exit(EXIT_FAILURE);
}

t_map_info	*init_map(char *fileName)
{
	t_map_info	*map_info;

	map_info = (t_map_info *) malloc(sizeof(t_map_info));
	if (!map_info)
		return (NULL);
	map_info->info_player = (t_player *)malloc(sizeof(t_player));
	if (!map_info->info_player)
		return (NULL);
	map_info->no_texture = NULL;
	map_info->so_texture = NULL;
	map_info->we_texture = NULL;
	map_info->ea_texture = NULL;
	map_info->c_texture = NULL;
	map_info->f_texture = NULL;
	map_info->c_color = -1;
	map_info->f_color = -1;
	map_info->map = NULL;
	map_info->map1_height = 0;
	map_info->map1_width = 0;
	map_info->num_lines = 0;
	map_info->num_cols = 0;
	map_info->file_name = fileName;
	map_info->paths = NULL;
	return (map_info);
}

int	check_file_name(char *str)
{
	int	len;

	if (!str)
		return (1);
	len = ft_strlen(str);
	if (str[len - 1] == 'b' && str[len - 2] == 'u'
		&& str[len - 3] == 'c' && str[len - 4] == '.')
		return (0);
	return (1);
}

int	check_all_parsing(int ac, char *str, t_map_info *map_info)
{
	if (ac != 2)
		writing_error("Wrong Number of Argumets");
	if (check_file_name(str))
		writing_error("Wrong file extension");
	if (read_textures(map_info))
		writing_error("Textures Missign");
	if (check_textures(map_info))
		writing_error("Textures Missign");
	if (init_path(map_info))
		writing_error("Wrong path to texture");
	if (read_map(map_info))
		writing_error("Textures Duplicated or missing");
	if (surround_map(map_info))
		writing_error("Map is not surrounded by walls");
	if (check_is_map_closed(map_info))
		writing_error("Map is not closed");
	if (get_nb_player(map_info))
		writing_error("Map must have one player");
	return (0);
}
