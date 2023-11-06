/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_key_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:30:21 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/06 05:08:31 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

void  move(t_map_info *mp)
{
    double dx;
    double dy;
    double mvspeed;

    dx = 0.0;
    dy = 0.0;
    mvspeed = 0.0;
    if(mp->key == UP_KEY)
    {
        mvspeed = MVSPEED * (-1.0);
        dx += mp->info_player->dirx *mvspeed;
        dy += mp->info_player->diry *mvspeed;
    }
    if(mp->key == DOWN_KEY)
    {
        mvspeed = MVSPEED * (1.0);
        dx += mp->info_player->dirx *mvspeed;
        dy += mp->info_player->diry *mvspeed;
    }
    if(mp->key == LEFT_KEY)
    {
        mvspeed = MVSPEED * (-1.0);
       dx += mp->info_player->dirx;
        dy += mp->info_player->diry;
    }
    if(mp->key == RIGHT_KEY)
    {
        mvspeed = MVSPEED * (1.0);
        dx += mp->info_player->planex;
        dy += mp->info_player->planey;
    }
    if(mp->map[(int)(mp->info_player->x_pos + dx)][(int)(mp->info_player->y_pos + dy)] != '0')
        return ;
    mp->info_player->x_pos +=dx;
    mp->info_player->y_pos +=dy;
}

void  rotation(t_map_info *mp)
{
    double rotspeed;
    double dir_new_x;

    rotspeed = ROTSPEED;
    if(mp->key == RIGHT_KEY)
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
    if(mp->img->ptr)
        free(mp->img->ptr);
    exit(0);
    return (0);
}
int key_definie(int key, t_map_info *mp)
{
    if(key == ESC_KEY)
        close_win(mp);
    else if(key == UP_KEY)
        mp->key = UP_KEY;
    else if(key == DOWN_KEY)
        mp->key = DOWN_KEY;
    else if(key == LEFT_KEY)
        mp->key = LEFT_KEY;
    else if(key == RIGHT_KEY)
        mp->key = RIGHT_KEY;
    else
        return (0);
    move(mp);
    rotation(mp);
    raycast_data(mp);
    return(0);
    
}