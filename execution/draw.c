/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:30:10 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/07 05:39:22 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../cub3d.h"
// void    put_pixel_in_img(t_map_info *mp, int x, int y, int col)
// {
//     int cln;

//     if(mp->img->pixels != 32)
//         mlx_get_color_value(mp->mlx, col);
//     cln = (y * mp->img->count) + (x * 4);
//     if(mp->img->enabled == 1)
//     {
//        mp->img->instances [cln + 0] = (col >> 24); 
//        mp->img->instances [cln + 1] = (col >> 16) & 0xFF; 
//        mp->img->instances [cln + 2] = (col >> 8) & 0xFF; 
//        mp->img->instances [cln + 3] = (col) & 0xFF; 
//     }
//     else if(mp->img->enabled == 0)
//     {
//         // printf("[%d] ||  [%d]\n", col, cln);
//         mp->img->instances [cln + 0] = (col) & 0xFF;
//         // printf("%c\n", mp->img->instances [cln + 0]);
//         mp->img->instances [cln + 1] = (col >> 8) & 0xFF; 
//         mp->img->instances [cln + 2] = (col >> 16) & 0xFF; 
//         mp->img->instances [cln + 3] = (col >> 24); 
//         // exit(0);
//     }
// }

// void    init_data_tex(t_raycast *rc, t_map_info *mp)
// {
//     mp->x_tex = (int)(rc->wallx * TEXHEIGHT);
//     if((mp->texture == mp->info_player->textur[0] || mp->texture == mp->info_player->textur[1])  && rc->raydirx > 0 )
//         mp->x_tex = mp->texture->width - mp->x_tex - 1;
//     if((mp->texture == mp->info_player->textur[2] || mp->texture == mp->info_player->textur[3])  && rc->raydiry > 0 )
//         mp->x_tex = TEXWIDTH - mp->x_tex - 1;
//     mp->step_tex = (double)TEXHEIGHT / rc->line ;
//     mp->pos_tex = (rc->start - HEIGHT / 2.0 + rc->line / 2.0) * mp->step_tex;
// }
// int color_for_tex(t_map_info *mp)
// {
//     char *tmp;
//     int cln;
//     int color;

//     cln = mp->y_tex * 8000 + mp->x_tex * 4;
//     tmp = mp->texture->data + cln;
//     if(mp->texture->end == 0)
//         color = ((unsigned char)tmp[2] << 16) + ((unsigned char)tmp[1] << 8) + ((unsigned char)tmp[0]);
//     color = ((unsigned char)tmp[0] << 16) + ((unsigned char)tmp[1] << 8) + ((unsigned char)tmp[2]);
//     return (color);
     
// }
void draw_line_pixel(t_raycast *rc, t_map_info *mp, int x)
{
    int y;
    // int col;

    y = 0;
    while(y < rc->start)
        mlx_put_pixel(mp->img, x, y++, mp->c_color);
    // init_data_tex(rc, mp);
    while(y < rc->end)
    {
        mlx_put_pixel(mp->img, x, y++, 143986);
        
    }
    while(y < HEIGHT)
        mlx_put_pixel(mp->img, x, y++, mp->f_color);
}