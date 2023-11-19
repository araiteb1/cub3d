/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:27:26 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/18 22:24:09 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    pars_textures(t_map_info *mp, char *path, t_img **texture)
{
    // // int i;
    // // printf("ok\n");
    if((*texture))
    {
        if(mp->texture[0] && (mp->texture[0])->ptr)
            mlx_destroy_image(mp->mlx, (mp->texture[0])->ptr);
        free(*mp->texture);
    //     // i = 0;
    //     // while(i++ < 4)
    //     // {
    //         // if((*mp->texture)->ptr)
    //         mlx_destroy_image(mp->mlx, (*mp->texture)->ptr);
    //         free(*mp->texture);
    //         exit(1);
    //     // }
    //     if(mp->img && mp->img->img)
    //         mlx_destroy_image(mp->mlx, mp->img->img);
    //     if(mp->img)
    //             free(mp->img);
    //     // printf("0 %d\n", (*texture)->width);
    //     // return ;
    }
    (*texture) = (t_img *)malloc(sizeof(t_img));
    if(!(*texture))
    {
        printf("1\n");
        return ;
    }
   (*texture)->ptr = mlx_xpm_file_to_image(mp->mlx, path,
			&(*texture)->width, &(*texture)->height);
    if(!(*texture)->ptr)
    {
        printf("2\n");
        return ;
    }
    printf("%d || %d \n", (*texture)->width, (*texture)->height);
    exit (0);
    (*texture)->addr = mlx_get_data_addr((*texture)->ptr, &(*texture)->bpp,
			&(*texture)->line_length, &(*texture)->end);
}

// void    textur_to_img(t_map_info *mp, char *path)
// {
    
//     if (!ft_strcmp(path ,mp->paths[0]))
//         pars_textures(mp, path, &mp->texture[0]);
//     if (!ft_strcmp(path ,mp->paths[1]))
//         pars_textures(mp, path, &mp->texture[1]);
//     if (!ft_strcmp(path ,mp->paths[2]))
//         pars_textures(mp, path, &mp->texture[2]);
//     if (!ft_strcmp(path ,mp->paths[3]))
//         pars_textures(mp, path, &mp->texture[3]);
// }

void	init_data_tex(t_raycast *rc, t_map_info *mp)
{
	mp->x_tex = (int)(rc->wallx * mp->textur->height);
	if ((mp->textur == mp->texture[0] || mp->textur == mp->texture[1]) && rc->raydirx > 0)
		mp->x_tex = mp->textur->width - mp->x_tex - 1;
	if ((mp->textur == mp->texture[2] || mp->textur == mp->texture[3]) && rc->raydiry > 0)
		mp->x_tex = mp->textur->width - mp->x_tex - 1;
	mp->step_tex = (double)mp->textur->height / rc->line ;
	mp->pos_tex = (rc->start - HEIGHT / 2.0 + rc->line / 2.0) * mp->step_tex;
}