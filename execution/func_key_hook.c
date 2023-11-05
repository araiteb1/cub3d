/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_key_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:30:21 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/05 22:30:22 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

 int         worldMap1[MAPWIDTH][MAPHEIGHT]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void  move(t_info *dt)
{
    double dx;
    double dy;
    double mvspeed;

    dx = 0.0;
    dy = 0.0;
    mvspeed = 0.0;
    if(dt->key == A_KEY)
    {
        mvspeed = MVSPEED * (-1.0);
        dx += dt->dirx *mvspeed;
        dy += dt->diry *mvspeed;
    }
    if(dt->key == D_KEY)
    {
        mvspeed = MVSPEED * (1.0);
        dx += dt->dirx *mvspeed;
        dy += dt->diry *mvspeed;
    }
    if(dt->key == W_KEY)
    {
        mvspeed = MVSPEED * (-1.0);
        dx += dt->planex *mvspeed;
        dy += dt->planey *mvspeed;
    }
    if(dt->key == S_KEY)
    {
        mvspeed = MVSPEED * (1.0);
        dx += dt->planex *mvspeed;
        dy += dt->planey *mvspeed;
    }
    if(worldMap1[(int)(dt->posx + dx)][(int)(dt->posy + dy)] != 0)
        return ;
    dt->posx +=dx;
    dt->posy +=dy;
}

void  rotation(t_info *dt)
{
    double rotspeed;
    double dir_new_x;

    rotspeed = ROTSPEED;
    if(dt->key == RIGHT_KEY)
        rotspeed = -ROTSPEED;
    dir_new_x = dt->dirx;
    dt->dirx = dir_new_x * cos(rotspeed) - dt->diry * sin(rotspeed);
    dt->diry = dir_new_x * sin(rotspeed) + dt->diry * cos(rotspeed);
    dir_new_x = dt->planex;
    dt->planex = dir_new_x * cos(rotspeed) - dt->planey * sin(rotspeed);
    dt->planey = dir_new_x * sin(rotspeed) + dt->planey * cos(rotspeed);
}

int     close_win(t_info *dt)
{
    if(dt->img->ptr)
        free(dt->img->ptr);
    exit(0);
    return (0);
}
int key_definie(int key, t_info *dt)
{
    if(key == ESC_KEY)
        close_win(dt);
    else if(key == A_KEY)
        dt->key = A_KEY;
    else if(key == D_KEY)
        dt->key = D_KEY;
    else if(key == W_KEY)
        dt->key = W_KEY;
    else if(key == S_KEY)
        dt->key = S_KEY;
    else if(key == LEFT_KEY)
        dt->key = LEFT_KEY;
    else if(key == RIGHT_KEY)
        dt->key = RIGHT_KEY;
    else
        return (0);
    move(dt);
    rotation(dt);
    raycast_data(dt);
    return(0);
    
}