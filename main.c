/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:27:36 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/06 05:03:17 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void printInfoRays(t_map_info *map_info)
{
	int i;

	i = 0;
	while (i < map_info->info_player->num_rays)
	{
		printf("rayAngle: %f, wallHitX: %f, wallHitY: %f, distance: %f, wasHitVertical: %d, isRayFacingUp: %d, isRayFacingDown: %d, isRayFacingLeft: %d, isRayFacingRight: %d, wallHitContent: %d\n", map_info->info_player->rays[i].rayAngle, map_info->info_player->rays[i].wallHitX, map_info->info_player->rays[i].wallHitY, map_info->info_player->rays[i].distance, map_info->info_player->rays[i].wasHitVertical, map_info->info_player->rays[i].isRayFacingUp, map_info->info_player->rays[i].isRayFacingDown, map_info->info_player->rays[i].isRayFacingLeft, map_info->info_player->rays[i].isRayFacingRight, map_info->info_player->rays[i].wallHitContent);
		i++;
	}
}

void init_rays(t_map_info **map_info)
{
	int i;

	i = 0;
	(*map_info)->info_player->rays = malloc(sizeof(t_ray) * (*map_info)->info_player->num_rays);
	while (i < (*map_info)->info_player->num_rays)
	{
		(*map_info)->info_player->rays[i].rayAngle = (*map_info)->info_player->rotationAngle - ((*map_info)->info_player->fieldOfView / 2) + ((*map_info)->info_player->fieldOfView / (*map_info)->info_player->num_rays) * i;
		(*map_info)->info_player->rays[i].wallHitX = 0;
		(*map_info)->info_player->rays[i].wallHitY = 0;
		(*map_info)->info_player->rays[i].distance = 0;
		(*map_info)->info_player->rays[i].wasHitVertical = 0;
		(*map_info)->info_player->rays[i].isRayFacingUp = 0;
		(*map_info)->info_player->rays[i].isRayFacingDown = 0;
		(*map_info)->info_player->rays[i].isRayFacingLeft = 0;
		(*map_info)->info_player->rays[i].isRayFacingRight = 0;
		(*map_info)->info_player->rays[i].wallHitContent = 0;
		i++;
	}
	
}

int main(int ac, char **av)
{
	int fd;
	t_map_info *map_info;
	// t_player *player = NULL;
	// (void)player;


	if (ac == 2)
	{
		if(!check_extension_of_file(av[1]))
			writing_error("Wrong file extension");
			
		init_map(&map_info, av[1]);
		
		fd = open(map_info->fileName, O_RDONLY);
		if (fd == -1)
			writing_error("Failed to open file");
			
		/**************************************************/
		read_textures(fd, &map_info);
		read_map(fd, &map_info);
		fill_map(&map_info);
		parsing(map_info);

		// printMap(map_info);
		/*************************************************/
		init_mlx(map_info);               
		init_player(&map_info);
		init_data_ray(map_info->info_player);
		raycast_data(map_info);
    	mlx_hook(map_info->win, 2, 0, key_definie, map_info);
		mlx_hook(map_info->win, 17, 0, close_win, map_info);
		// init_rays(&map_info);
		// castAllrays(&map_info);
		// mlx_loop_hook(map_info->mlx, key_hook, map_info);
		mlx_loop(map_info->mlx);
		/*************************************************/
		// close(fd);
		// free_map(map_info->map); 
		// free_map_info(map_info);
		/**************************************************/
	}
	else
		writing_error("Invalid number of argumets");
	// atexit(ff);
	return (0);
}