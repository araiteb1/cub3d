/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_raycas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:30:28 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/06 05:00:51 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../cub3d.h"

void  init_data_ray(t_player *dt)
{
  dt->dirx = -1;
  dt->diry = 0;
  dt->planex = 0;
  dt->planey = 0.66;

}
void  get_coordinate(t_raycast *rc, int x, t_player *dt)
{
  rc->camerax = (2.0 * x )/ (WIDTH - 1.0);
  rc->raydirx = dt->dirx + dt->planex * rc->camerax;
  rc->raydiry = dt->diry + dt->planey * rc->camerax;
  rc->mapx = (int)dt->y_pos;
  rc->mapy = (int)dt->x_pos;
  rc->deltadistx = fabs(1/rc->raydirx);
  if(rc->raydirx == 0)
    rc->deltadistx = 1e30;
  rc->deltadisty = fabs(1/rc->raydiry);
  if(rc->raydiry == 0)
    rc->deltadisty = 1e30;
  rc->perp_walldist = 0.0;
  rc->stepx = 0;
  rc->stepy = 0;
  rc->hit = 0;

}

void  get_side_dist(t_map_info *mp, t_raycast *rc)
{
  if(rc->raydirx < 0)
  {
    rc->stepx = -1;
    rc->sidedistx = (mp->info_player->x_pos - rc->mapx) * rc->deltadistx;
  }
  else
  {
    rc->stepx = 1;
    rc->sidedistx = (rc->mapx + 1.0 - mp->info_player->x_pos) * rc->deltadistx;
  }
  if(rc->raydiry < 0)
  {
    rc->stepy = -1;
    rc->sidedisty = (mp->info_player->y_pos - rc->mapy) * rc->deltadisty;
  }
  else
  {
    rc->stepy = 1;
    rc->sidedisty = (rc->mapy + 1.0 - mp->info_player->y_pos) * rc->deltadisty;
  }
}

void  add_algo(t_raycast *rc, t_map_info *mp)
{
  while(rc->hit == 0)
  {
    if(rc->sidedistx < rc->sidedisty)
    {
      rc->sidedistx += rc->deltadistx;
      rc->mapx += rc->stepx;
      rc->side = 0;
    }
    else
    {
      rc->sidedisty += rc->deltadisty;
      rc->mapy += rc->stepy;
      rc->side = 1;
    }
    if (mp->map[rc->mapx][rc->mapy] != '0')
      rc->hit = 1;
  }
}

void  draw_line(t_raycast *rc)
{
  if(rc->side == 0)
    rc->perp_walldist = rc->sidedistx - rc->deltadistx;
  else
    rc->perp_walldist = rc->sidedisty - rc->deltadisty;
  rc->line = (int)(HEIGHT / rc->perp_walldist);
	rc->start = -rc->line / 2.0 + HEIGHT / 2.0;
	if (rc->start < 0)
		rc->start = 0;
	rc->end = rc->line / 2.0 + HEIGHT / 2.0;
	if (rc->end >=HEIGHT)
		rc->end = HEIGHT - 1;

}

void raycast_data(t_map_info *mp)
{
  int x;
  t_raycast *rc;
  rc = (t_raycast *)malloc (sizeof(t_raycast));
    if(!rc)
      return ;
  x = 0;
  while(x < WIDTH)
  {
    get_coordinate(rc, x, mp->info_player);
    get_side_dist(mp, rc);
    add_algo(rc, mp);
    draw_line(rc);
    draw_line_pixel(rc, mp, x);
    x++;
  }
  mlx_put_image_to_window(mp->mlx, mp->win, mp->img->ptr, 0, 0);
}
           
