/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:19:30 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/18 22:08:55 by ahaloui          ###   ########.fr       */
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




void ff()
{
	system("leaks cub3D");
}

int main(int ac, char **av)
{
	t_map_info *map_info;
	
	map_info = init_map(av[1]);
	check_all_parsing(ac, av[1], map_info);
	print_textures(map_info);
	atexit(ff);
	free_all_parsing(map_info);
}