/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 03:57:12 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/19 03:57:32 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_mlx(t_map_info *map_info)
{
	map_info->mlx = mlx_init();
	map_info->win = mlx_new_window(map_info->mlx, WIDTH, HEIGHT, "win");
	map_info->img = (t_img *)malloc(sizeof(t_img));
	map_info->img->img = mlx_new_image(map_info->mlx, WIDTH, HEIGHT);
	map_info->img->addr = mlx_get_data_addr(map_info->img->img, &map_info->img->bpp,
				&map_info->img->line_length, &map_info->img->end);
}