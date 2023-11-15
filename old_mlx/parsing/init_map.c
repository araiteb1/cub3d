/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:18:30 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/15 17:43:47 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void free_map_info(t_map_info *map_info)
{
    free(map_info->no_texture);
    free(map_info->so_texture);
    free(map_info->we_texture);
    free(map_info->ea_texture);
    free(map_info->c_texture);
    free(map_info->f_texture);
    free(map_info);
}

void printMap(t_map_info *map_info)
{
	int i = 0;
	//printf("hello from printMap\n");
	//printf("no_texture: %s\n", map_info->no_texture);
	//printf("so_texture: %s\n", map_info->so_texture);
	//printf("we_texture: %s\n", map_info->we_texture);
	//printf("ea_texture: %s\n", map_info->ea_texture);
	//printf("c_texture: %s\n", map_info->c_texture);
	//printf("f_texture: %s\n", map_info->f_texture);
    //printf("c_color: %d\n", map_info->c_color);
    //printf("f_color: %d\n", map_info->f_color);
	//printf("Map: {%p}\n", &map_info->map[i]);
	//printf("********************************************************************\n");
	while (map_info->map[i])
	{
		//printf("|%s|\n", map_info->map[i]);
		i++;
	}
}

t_map_info *init_map(char *fileName)
{
	t_map_info *map_info;

    map_info = malloc(sizeof(t_map_info));
    if (!map_info)
        writing_error("Failed to allocate memory");
    map_info->no_texture = NULL;
	map_info->so_texture = NULL;
	map_info->we_texture = NULL;
	map_info->ea_texture = NULL;
	map_info->c_texture = NULL;
	map_info->f_texture = NULL;
	map_info->c_color = -1;
	map_info->f_color = -1;
	map_info->map = NULL;
	map_info->num_lines = 0;
	map_info->num_cols = 0;
	map_info->fileName = fileName;
	map_info->paths = NULL;
	return map_info;
}

void init_mlx(t_map_info *map_info)
{
	map_info->mlx = mlx_init();
	map_info->win = mlx_new_window(map_info->mlx, WIDTH, HEIGHT, "win");
	map_info->img = (t_img *)malloc(sizeof(t_img));
	map_info->img->img = mlx_new_image(map_info->mlx, WIDTH, HEIGHT);
	map_info->img->addr = mlx_get_data_addr(map_info->img->img, &map_info->img->bpp,
				&map_info->img->line_length, &map_info->img->end);
}


void destroy_mlx(t_map_info **_map_info)
{
	// mlx_destroy_image((*_map_info)->mlx, (*_map_info)->img->image);
	// mlx_destroy_window((*_map_info)->mlx, (*_map_info)->mlx_win);
	free((*_map_info)->img);
	free_map((*_map_info)->map);
	free_map_info((*_map_info));
}

void parsing(t_map_info *map_info)
{
    if (!surround_map(map_info->map, map_info->num_lines))
        writing_error("Map is not surrounded by walls");
    if (!isMapClosed(map_info->map, map_info->num_lines))
        writing_error("Map is not closed");
    if (!get_numebr_player(map_info->map, map_info->num_lines))
        writing_error("Map must have one player");
}