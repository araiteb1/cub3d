/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:30:10 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/17 16:19:01 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_curr_pathtxt(t_map_info *mp)
{
	if (!mp->textur)
		return ;
	if (!ft_strcmp(mp->textur, mp->no_texture))
		mp->textur1 = ft_strdup(mp->paths[0]);
	if (!ft_strcmp(mp->textur, mp->so_texture))
		mp->textur1 = ft_strdup(mp->paths[1]);
	if (!ft_strcmp(mp->textur, mp->ea_texture))
		mp->textur1 = ft_strdup(mp->paths[3]);
	if (!ft_strcmp(mp->textur, mp->we_texture))
		mp->textur1 = ft_strdup(mp->paths[2]);
}

void	init_data_tex(t_raycast *rc, t_map_info *mp)
{
	if (!mp->textur)
		return ;
	mp->texture = (t_img *)malloc(sizeof(t_img));
	get_curr_pathtxt(mp);
	mp->texture->ptr = mlx_xpm_file_to_image(mp->mlx, mp->textur1,
			&mp->texture->width, &mp->texture->height);
	free(mp->textur1);
	if (!mp->texture->ptr)
		return ;
	mp->texture->addr = mlx_get_data_addr(mp->texture->ptr, &mp->texture->bpp,
			&mp->texture->line_length, &mp->texture->end);
	if (!mp->texture->addr)
		return ;
	mp->x_tex = (int)(rc->wallx * mp->texture->height);
	if ((!ft_strcmp(mp->textur, mp->no_texture)
			|| !ft_strcmp(mp->textur, mp->so_texture)) && rc->raydirx > 0)
		mp->x_tex = mp->texture->width - mp->x_tex - 1;
	if ((!ft_strcmp(mp->textur, mp->we_texture)
			|| !ft_strcmp(mp->textur, mp->ea_texture)) && rc->raydiry > 0)
		mp->x_tex = mp->texture->width - mp->x_tex - 1;
	mp->step_tex = (double)mp->texture->height / rc->line ;
	mp->pos_tex = (rc->start - HEIGHT / 2.0 + rc->line / 2.0) * mp->step_tex;
}

int	color_for_tex(t_map_info *mp)
{
	char	*tmp;
	int		cln;
	int		color;

	cln = mp->y_tex * mp->texture->line_length
		+ mp->x_tex * (mp->texture->bpp / 8);
	tmp = mp->texture->addr + cln;
	if (mp->texture->end == 0)
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
		mlx_pixel_put(mp->mlx, mp->win, x, y++, mp->c_color);
	init_data_tex(rc, mp);
	while (y < rc->end)
	{
		mp->y_tex = (int)mp->pos_tex & (mp->texture->height - 1);
		mp->pos_tex += mp->step_tex;
		mlx_pixel_put(mp->mlx, mp->win, x, y++, color_for_tex(mp));
	}
	while (y < HEIGHT)
		mlx_pixel_put(mp->mlx, mp->win, x, y++, mp->f_color);
	mlx_destroy_image(mp->mlx, mp->texture->ptr);
	free (mp->texture);
}
