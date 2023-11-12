/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:30:10 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/12 14:54:40 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../cub3d.h"

void    init_data_tex(t_raycast *rc, t_map_info *mp)
{
    char *path;
    if(!mp->textur)
        return ;
    path = ft_strtrim(mp->textur, " ");
    mp->texture = (mlx_image_t *)malloc(sizeof(mlx_image_t));
    mp->x_tex = (int)(rc->wallx * mp->texture->height);
    if((mp->textur == mp->no_texture || mp->textur == mp->so_texture)  && rc->raydirx > 0 )
        mp->x_tex = mp->texture->width - mp->x_tex - 1;
    if((mp->textur == mp->we_texture || mp->textur == mp->ea_texture)  && rc->raydiry > 0 )
        mp->x_tex = mp->texture->width - mp->x_tex - 1;
    mp->step_tex = (double)mp->texture->height / rc->line ;
    mp->pos_tex = (rc->start - HEIGHT / 2.0 + rc->line / 2.0) * mp->step_tex;
    mp->texture->context = mlx_load_xpm42(path);
    if(!mp->texture->context)
        return ;
    printf("%d || %d \n", mp->x_tex, mp->y_tex);
    exit(0);
}
int color_for_tex(t_map_info *mp)
{
    char *tmp;
    int cln;
    // int color;

    cln = mp->y_tex * mp->texture->count + mp->x_tex * 4;
    tmp = mp->textur + cln;
    return (cln);
     
}
void draw_line_pixel(t_raycast *rc, t_map_info *mp, int x)
{
    int y;

    y = 0;
    while(y < rc->start)
        mlx_put_pixel(mp->img, x, y++, 115692);
    init_data_tex(rc, mp);
    while(y < rc->end)
    {
        mp->y_tex = (int)mp->pos_tex & (mp->texture->height - 1);
        mp->pos_tex += mp->step_tex;
        mlx_put_pixel(mp->img, x, y++, color_for_tex(mp));
        
    }
    while(y < HEIGHT)
        mlx_put_pixel(mp->img, x, y++, 422154);
}