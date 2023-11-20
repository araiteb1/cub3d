/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:19:30 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/20 04:18:41 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_textures(t_map_info *map_info)
{
	int i = 0;
	printf("NO: %s\n", map_info->no_texture);
	printf("SO: %s\n", map_info->so_texture);
	printf("WE: %s\n", map_info->we_texture);
	printf("EA: %s\n", map_info->ea_texture);
	printf("C: %s\n", map_info->c_texture);
	printf("F: %s\n", map_info->f_texture);
	printf("C: %d\n", map_info->c_color);
	printf("F: %d\n", map_info->f_color);

	while (i < 4)
	{
		printf("paths[%d]: |%s|\n", i, map_info->paths[i]);
		i++;
	}
	i = 0;
	while (map_info->map[i])
	{
		printf("|%s|\n", map_info->map[i]);
		i++;
	}
}

void 	f()
{
	system("leaks cub3D");
}
int main(int ac, char **av)
{
	t_map_info *map_info;
	
	atexit(f);
	map_info = init_map(av[1]);
	init_mlx(map_info);
	check_all_parsing(ac, av[1], map_info);
	init_int_map(map_info);
	raycast_data(map_info);
	mlx_hook(map_info->win,2,0, key_definie, map_info);
	mlx_hook(map_info->win,17 , 0, close_win, map_info);
	mlx_loop(map_info->mlx);
	// print_textures(map_info);
	free_all_parsing(map_info);
}