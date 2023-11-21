/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:27:26 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/21 13:33:19 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	pars_textures(t_map_info *mp, char *path, t_img **texture)
{
	*texture = (t_img *)malloc(sizeof(t_img));
	if (!(*texture))
		return ;
	(*texture)->img = mlx_xpm_file_to_image(mp->mlx, path,
			&(*texture)->width, &(*texture)->height);
	if (!(*texture)->img)
		return ;
	(*texture)->addr = mlx_get_data_addr((*texture)->img, &(*texture)->bpp,
			&(*texture)->line_length, &(*texture)->end);
}

void	init_data_tex(t_raycast *rc, t_map_info *mp)
{
	mp->x_tex = (int)(rc->wallx * mp->textur->height);
	if ((mp->textur == mp->texture[0]
			|| mp->textur == mp->texture[1]) && rc->raydirx > 0)
		mp->x_tex = mp->textur->width - mp->x_tex - 1;
	if ((mp->textur == mp->texture[2]
			|| mp->textur == mp->texture[3]) && rc->raydiry > 0)
		mp->x_tex = mp->textur->width - mp->x_tex - 1;
	mp->step_tex = (double)mp->textur->height / rc->line;
	mp->pos_tex = (rc->start - HEIGHT / 2.0 + rc->line / 2.0) * mp->step_tex;
}
