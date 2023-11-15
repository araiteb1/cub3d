/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:48:01 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/15 08:52:12 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int check_wall(t_map_info *map_info, double x, double y)
{
	int i;
	int j;

	i = floor((x) / TILE_SIZE);
	j = floor((y) / TILE_SIZE);
	if (i < 0 || i >= map_info->num_cols || j < 0 || j >= map_info->num_lines)
		return (1);
	if (map_info->map[j][i] == '1')
		return (1);
	return (0);
}


int	check_if_all_walls(t_map_info *data, double x, double y)
{
	if (check_wall(data, x, y) == 1)
		return (1);
	else if (check_wall(data, x, y - 3) == 1)
		return (1);
	else if (check_wall(data, x, y + 3) == 1)
		return (1);
	else if (check_wall(data, x - 3, y) == 1)
		return (1);
	else if (check_wall(data, x + 3, y) == 1)
		return (1);
	else 
		return (0);
}

// void update_player(t_map_info *map_info, t_player **player)
// {
// 	if (mlx_is_key_down(map_info->mlx, MLX_KEY_W))
// 		move_w(map_info, player);
// 	else if (mlx_is_key_down(map_info->mlx, MLX_KEY_S))
// 		move_s(map_info, player);
// 	else if (mlx_is_key_down(map_info->mlx, MLX_KEY_A))
// 		move_a(map_info, player);
// 	else if (mlx_is_key_down(map_info->mlx, MLX_KEY_D))
// 		move_d(map_info, player);
// 	else if (mlx_is_key_down(map_info->mlx, MLX_KEY_RIGHT))
// 		move_right(map_info, player);
// 	else if (mlx_is_key_down(map_info->mlx, MLX_KEY_LEFT))
// 		move_left(map_info, player);
// 	else if (mlx_is_key_down(map_info->mlx, MLX_KEY_ESCAPE))
// 		exit(1);
// }

int find_intersection(t_map_info *map_info, double x, double y)
{
	int i;
	int j;

	i = floor((x) / TILE_SIZE);
	j = floor((y) / TILE_SIZE);
	if (i < 0 || i >= map_info->num_cols || j < 0 || j >= map_info->num_lines)
		return (1);
	if (map_info->map[j][i] == '1')
		return (1);
	return (0);
}


// void key_hook(void *ptr)
// {
// 	t_map_info *map_info;

// 	map_info = (t_map_info *)ptr;
// 	// mlx_delete_image(map_info->mlx, map_info->img);
// 	// map_info->img = mlx_new_image(map_info->mlx, WIDTH, HEIGHT);
// 	// mlx_image_to_window(map_info->mlx, map_info->img, 0, 0);
// 	// update_player(map_info, &map_info->info_player);
// 	// rander_map(map_info);
// 	// rander_rays(&map_info);
// 	rander_player(&map_info, map_info->info_player->x , map_info->info_player->y, COLOR_RED);
// 	rander_line_player(map_info, map_info->info_player->x, map_info->info_player->y, map_info->info_player->x + cos(map_info->info_player->rotationAngle) * 30 , map_info->info_player->y + sin(map_info->info_player->rotationAngle) *30);
// 	raycast_data(map_info);
// }
