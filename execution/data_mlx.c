/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 03:57:12 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/24 11:41:50 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_matrix(int **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	init_mlx(t_map_info *map_info)
{
	map_info->mlx = mlx_init();
	if (!map_info->mlx)
		writing_error("Mlx failed\n");
	map_info->win = mlx_new_window(map_info->mlx, WIDTH, HEIGHT, "win");
	if (!map_info->mlx || !map_info->win)
		writing_error("Mlx failed\n");
	map_info->img = (t_img *)malloc(sizeof(t_img));
	if (!map_info->img)
		writing_error("Malloc failed\n");
	map_info->img->img = mlx_new_image(map_info->mlx, WIDTH, HEIGHT);
	if (!map_info->img->img)
		writing_error("Mlx failed\n");
	map_info->img->addr = mlx_get_data_addr(map_info->img->img,
			&map_info->img->bpp, &map_info->img->line_length,
			&map_info->img->end);
	if (!map_info->img->addr)
		writing_error("Mlx failed\n");
}
