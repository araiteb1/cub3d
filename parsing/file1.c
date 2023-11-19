/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:19:20 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/19 04:29:54 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void writing_error(char *str)
{
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	exit(EXIT_FAILURE);
}

t_map_info	*init_map(char *fileName)
{
	t_map_info	*map_info;

	map_info = (t_map_info *) malloc(sizeof(t_map_info));
	if (!map_info)
	{
		writing_error("Failed to allocate memory");
		return NULL;
	}
	map_info->info_player = (t_player *)malloc(sizeof(t_player));
	if(!map_info->info_player)
		return NULL;
	map_info->no_texture = NULL;
	map_info->so_texture = NULL;
	map_info->we_texture = NULL;
	map_info->ea_texture = NULL;
	map_info->c_texture = NULL;
	map_info->f_texture = NULL;
	map_info->c_color = -1;
	map_info->f_color = -1;
	map_info->map = NULL;
	// map_info->t = (int **)malloc(10*  sizeof(int *));
	map_info->map1_height = 0;
	map_info->map1_width = 0;
	map_info->num_lines = 0;
	map_info->num_cols = 0;
	map_info->fileName = fileName;
	map_info->paths = NULL;
	// map_info->info_player->x_pos = -1;
	// map_info->info_player->y_pos = -1;
	return (map_info);
}


int check_file_name(char *str)
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

int parsing(int ac, char *str, t_map_info *map_info)
{
	if (ac != 2)
		return (1);
	if (check_file_name(str))
		return (2);
	if (read_textures(map_info))
		return (3);
	if (check_textures(map_info))
		return (4);
    if(init_path(map_info))
		return (5);
	if (read_map(map_info))
		return (6);
	if (surround_map(map_info))
		return (7);
	if (isMapClosed(map_info))
		return (8);
	if (get_nb_player(map_info))
		return (9);
	return (0);
}


int	check_all_parsing(int ac, char *str, t_map_info *map_info)
{
	int	result_of_parsing;

	result_of_parsing = parsing(ac, str, map_info);
	if (result_of_parsing == 1)
		writing_error("Wrong Number of Argumets");
	if (result_of_parsing == 2)
		writing_error("Wrong file extension");
	if ((result_of_parsing == 3) || (result_of_parsing == 4))
		writing_error("Textures Missign");
	if (result_of_parsing == 5)
		writing_error("Wrong path to texture");
	if (result_of_parsing == 6)
		writing_error("Textures Duplicated or missing");
	if (result_of_parsing == 7)
		writing_error("Map is not surrounded by walls");
	if (result_of_parsing == 8)
		writing_error("Map is not closed");
	if (result_of_parsing == 9)
		writing_error("Map must have one player");
	return (0);
}