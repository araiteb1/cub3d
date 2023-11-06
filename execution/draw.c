/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:30:10 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/06 04:55:20 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../cub3d.h"
void    put_pixel_in_img(t_map_info *mp, int x, int y, int col)
{
    int cln;

    if(mp->img->bits_of_pixel != 32)
        mlx_get_color_value(mp->mlx, col);
    cln = (y * mp->img->size_line) + (x * 4);
    if(mp->img->end == 1)
    {
       mp->img->data [cln + 0] = (col >> 24); 
       mp->img->data [cln + 1] = (col >> 16) & 0xFF; 
       mp->img->data [cln + 2] = (col >> 8) & 0xFF; 
       mp->img->data [cln + 3] = (col) & 0xFF; 
    }
    else if(mp->img->end == 0)
    {
        // printf("[%d] ||  [%d]\n", col, cln);
        mp->img->data [cln + 0] = (col) & 0xFF;
        // printf("%c\n", mp->img->data [cln + 0]);
        mp->img->data [cln + 1] = (col >> 8) & 0xFF; 
        mp->img->data [cln + 2] = (col >> 16) & 0xFF; 
        mp->img->data [cln + 3] = (col >> 24); 
        // exit(0);
    }
}
void draw_line_pixel(t_raycast *rc, t_map_info *mp, int x)
{
    int y;

    y = 0;
    while(y < rc->start)
        put_pixel_in_img(mp, x, y++, 1703935);
    while(y < rc->end)
        put_pixel_in_img(mp, x, y++, 143986);
    while(y < HEIGHT)
        put_pixel_in_img(mp, x, y++, 2142863);
}