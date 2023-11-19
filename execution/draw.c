/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:30:10 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/19 04:01:21 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	color_for_tex(t_map_info *mp)
{
	char	*tmp;
	int		cln;
	int		color;

	cln = mp->y_tex * mp->textur->line_length
		+ mp->x_tex * (mp->textur->bpp / 8);
	tmp = mp->textur->addr + cln;
	if (mp->textur->end == 0)
		color = ((((unsigned char)tmp[2]) << 16)
				+ (((unsigned char)tmp[1]) << 8) + ((unsigned char)tmp[0]));
	else
		color = ((((unsigned char)tmp[0]) << 16)
				+ (((unsigned char)tmp[1]) << 8) + ((unsigned char)tmp[2]));
	return (color);
}

void	draw_line_pixel(t_raycast *rc, t_map_info *mp, int x)
{
	int	y;

	y = 0;
	// printf("%d || %d  \n",rc->start,rc->end);
	// exit(0);
	while (y < rc->start)
		mlx_pixel_put(mp->mlx, mp->win, x, y++, mp->c_color);
	// init_data_tex(rc, mp);
	while (y < rc->end)
	{
		// mp->y_tex = (int)mp->pos_tex & (mp->textur->height - 1);
		// mp->pos_tex += mp->step_tex;
		mlx_pixel_put(mp->mlx, mp->win, x, y++, 12546884);
	}
	while (y < HEIGHT)
		mlx_pixel_put(mp->mlx, mp->win, x, y++, mp->f_color);
	// mlx_destroy_image(mp->mlx, mp->textur->ptr);
	// free (mp->textur);
}
