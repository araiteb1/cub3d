/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:30:10 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/22 12:19:48 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	pixel_put(t_map_info *mp, int x, int y, int color)
{
	int	cln;

	if (mp->img->bpp != 32)
		color = mlx_get_color_value(mp->mlx, color);
	cln = (y * mp->img->line_length) + (x * (mp->img->bpp / 8));
	if (mp->img->end == 0)
	{
		mp->img->addr[cln + 0] = (color) & 0xFF;
		mp->img->addr[cln + 1] = (color >> 8) & 0xFF;
		mp->img->addr[cln + 2] = (color >> 16) & 0xFF;
		mp->img->addr[cln + 3] = (color >> 24);
	}
	else if (mp->img->end == 1)
	{
		mp->img->addr[cln + 0] = (color >> 24);
		mp->img->addr[cln + 1] = (color >> 16) & 0xFF;
		mp->img->addr[cln + 2] = (color >> 8) & 0xFF;
		mp->img->addr[cln + 3] = (color) & 0xFF;
	}
}

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
	while (y < rc->start)
		pixel_put(mp, x, y++, mp->c_color);
	init_data_tex(rc, mp);
	while (y < rc->end)
	{
		mp->y_tex = (int)mp->pos_tex & (mp->textur->height - 1);
		mp->pos_tex += mp->step_tex;
		pixel_put(mp, x, y++, color_for_tex(mp));
	}
	while (y < HEIGHT)
		pixel_put(mp, x, y++, mp->f_color);
}
