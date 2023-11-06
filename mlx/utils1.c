/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:50:34 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/06 04:07:57 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int    is_palyer(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}


// void rander_line_player(t_map_info *map_info, int x0, int y0, int x1, int y1)
// {
// 	int dx;
// 	int dy;
// 	int steps;
// 	int i;
// 	float xinc;
// 	float yinc;
// 	float x;
// 	float y;

// 	dx = x1 - x0;
// 	dy = y1 - y0;
// 	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
// 	xinc = dx / (float)steps;
// 	yinc = dy / (float)steps;
// 	x = x0;
// 	y = y0;
// 	i = 0;
// 	while (i <= steps)
// 	{
//         if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
// 		    mlx_put_pixel(map_info->img, x, y, COLOR_RED);
// 		x += xinc;
// 		y += yinc;
// 		i++;
// 	}
// }

// void rander_player(t_map_info **map_info, int x, int y, int color)
// {
// 	int i;
// 	int j;
// 	int size;

// 	size = 4;
// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
//             if (x + i >= 0 && x + i < WIDTH && y + j >= 0 && y + j < HEIGHT)
// 			    mlx_put_pixel((*map_info)->img, x + i, y + j, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void rander_square(t_map_info **map_info, int x, int y, int color)
// {
// 	int i;
// 	int j;
// 	int size;

// 	size = TILE_SIZE - 1;
// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
//             if (x + i >= 0 && x + i < WIDTH && y + j >= 0 && y + j < HEIGHT)
// 			    mlx_put_pixel((*map_info)->img, x + i, y + j, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int rander_map(t_map_info *map_info)
// {	
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < map_info->num_lines)
// 	{
// 		j = 0;
// 		while (j < map_info->num_cols)
// 		{
// 			if (map_info->map[i][j] == '1' || map_info->map[i][j] == ' ')
// 				rander_square(&map_info, j * TILE_SIZE, i * TILE_SIZE, COLOR_WHITE);
// 			else if (map_info->map[i][j] == '0')
// 				rander_square(&map_info, j * TILE_SIZE, i * TILE_SIZE, COLOR_BLACK);
// 			else if (is_palyer(map_info->map[i][j]))
// 				rander_square(&map_info, j * TILE_SIZE, i * TILE_SIZE, COLOR_BLACK);
// 			j++;
// 		}
// 		i++;
// 	}
// 	// rander_player(&map_info, map_info->info_player->x, map_info->info_player->y, COLOR_RED);
// 	// rander_line_player(map_info, map_info->info_player->x, map_info->info_player->y, map_info->info_player->x + cos(map_info->info_player->rotationAngle) * 30, map_info->info_player->y + sin(map_info->info_player->rotationAngle) * 30);
// 	return 0;
// }


