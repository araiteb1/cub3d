/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_key_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:30:21 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/07 05:34:16 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"
void check_if_wall(t_map_info *mp, double *dx, double *dy)
{
    // if(mp->map[(int)(mp->info_player->x_pos + (*dx))][(int)(mp->info_player->y_pos + (*dy))] != '0')
    //     return ;
    mp->info_player->x_pos +=(*dx);
    mp->info_player->y_pos +=(*dy);
    
}

void  move_up(t_map_info *mp)
{
    double dx;
    double dy;
    double mvspeed;

    dx = 0.0;
    dy = 0.0;
    mvspeed = 0.0;
    if(mp->key == KEY_UP)
    {
        mvspeed = MVSPEED * (-1.0);
        dx += mp->info_player->dirx *mvspeed;
        dy += mp->info_player->diry *mvspeed;
    }
    check_if_wall(mp, &dx, &dy);
}
void  move_down(t_map_info *mp)
{
    double dx;
    double dy;
    double mvspeed;

    dx = 0.0;
    dy = 0.0;
    mvspeed = 0.0;
    if(mp->key == KEY_DOWN)
    {
        mvspeed = MVSPEED * (1.0);
        dx += mp->info_player->dirx *mvspeed;
        dy += mp->info_player->diry *mvspeed;
    }
    check_if_wall(mp, &dx, &dy);
}
void  move_left1(t_map_info *mp)
{
    double dx;
    double dy;
    double mvspeed;
    dx = 0.0;
    dy = 0.0;
    mvspeed = 0.0;
    if(mp->key == KEY_LEFT)
    {
        mvspeed = MVSPEED * (-1.0);
       dx += mp->info_player->dirx;
        dy += mp->info_player->diry;
    }
    check_if_wall(mp, &dx, &dy);
}
void  move_right1(t_map_info *mp)
{
    double dx;
    double dy;
    double mvspeed;
    dx = 0.0;
    dy = 0.0;
    mvspeed = 0.0;
    if(mp->key == KEY_RIGHT)
    {
        mvspeed = MVSPEED * (1.0);
        dx += mp->info_player->planex;
        dy += mp->info_player->planey;
    }
    check_if_wall(mp, &dx, &dy);
}


void  rotation(t_map_info *mp)
{
    double rotspeed;
    double dir_new_x;

    rotspeed = ROTSPEED;
    if(mp->key == KEY_RIGHT)
        rotspeed = -ROTSPEED;
    dir_new_x = mp->info_player->dirx;
    mp->info_player->dirx = dir_new_x * cos(rotspeed) - mp->info_player->diry * sin(rotspeed);
    mp->info_player->diry = dir_new_x * sin(rotspeed) + mp->info_player->diry * cos(rotspeed);
    dir_new_x = mp->info_player->planex;
    mp->info_player->planex = dir_new_x * cos(rotspeed) - mp->info_player->planey * sin(rotspeed);
    mp->info_player->planey = dir_new_x * sin(rotspeed) + mp->info_player->planey * cos(rotspeed);
}

int     close_win(t_map_info *mp)
{
    printf("sfsdfsdfsfsdf\n");
    if(mp->img->context)
        free(mp->img->context);
    exit(0);
    return (0);
}
void key_definie(void *ptr)
{
    t_map_info *mp;

	mp = (t_map_info *)ptr;
	// mlx_delete_image(mp->mlx, mp->img);
	// mp->img = mlx_new_image(mp->mlx, WIDTH, HEIGHT);
	// mlx_image_to_window(mp->mlx, mp->img, 0, 0);
   if (mlx_is_key_down(mp->mlx, KEY_ESC))
   {
        printf("here\n");
        close_win(mp);
   }
    if (mlx_is_key_down(mp->mlx, KEY_UP))
       move_up(mp);
   if (mlx_is_key_down(mp->mlx, KEY_DOWN))
       move_down(mp);
    if (mlx_is_key_down(mp->mlx, KEY_LEFT))
        move_left1(mp);
    if (mlx_is_key_down(mp->mlx, KEY_RIGHT))
       move_right1(mp);
    else
        return ;
    // move(mp);
    rotation(mp);
    raycast_data(mp);
    // return(0);
    
}