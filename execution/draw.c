/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:30:10 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/05 22:40:38 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"cub3d.h"
void    put_pixel_in_img(t_info *dt, int x, int y, int col)
{
    int cln;

    if(dt->img->bits_of_pixel != 32)
        mlx_get_color_value(dt->mlx, col);
    cln = (y * dt->img->size_line) + (x * 4);
    if(dt->img->end == 1)
    {
       dt->img->data [cln + 0] = (col >> 24); 
       dt->img->data [cln + 1] = (col >> 16) & 0xFF; 
       dt->img->data [cln + 2] = (col >> 8) & 0xFF; 
       dt->img->data [cln + 3] = (col) & 0xFF; 
    }
    else if(dt->img->end == 0)
    {
        // printf("[%d] ||  [%d]\n", col, cln);
        dt->img->data [cln + 0] = (col) & 0xFF;
        // printf("%c\n", dt->img->data [cln + 0]);
        dt->img->data [cln + 1] = (col >> 8) & 0xFF; 
        dt->img->data [cln + 2] = (col >> 16) & 0xFF; 
        dt->img->data [cln + 3] = (col >> 24); 
        // exit(0);
    }
}
void draw_line_pixel(t_raycast *rc, t_info *dt, int x)
{
    int y;

    y = 0;
    while(y < rc->start)
    {
        // printf("%d ||  %d  || %d || %d\n", y, rc->start, rc->end, HEIGHT);
        put_pixel_in_img(dt, x, y, 1703935);
        y++;    
    }
    while(y < rc->end)
        put_pixel_in_img(dt, x, y++, 143986);
    while(y < HEIGHT)
        put_pixel_in_img(dt, x, y++, 2142863);
}