/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_raycas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:30:28 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/15 15:19:20 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../cub3d.h"

void  get_coordinate(t_raycast *rc, int x, t_map_info *mp)
{
    rc->camerax = 2.0 * x  / WIDTH - 1.0;
    rc->raydirx = mp->info_player->dirx + mp->info_player->planex * rc->camerax;
    rc->raydiry = mp->info_player->diry + mp->info_player->planey * rc->camerax;
    rc->mapx = (int)mp->info_player->x_pos;
    rc->mapy = (int)mp->info_player->y_pos;
    rc->sidedistx = 0.0;
    rc->sidedisty = 0.0;
    rc->deltadistx = fabs(1/rc->raydirx);
    if(rc->raydirx == 0)
      rc->deltadistx = 1e30;
    rc->deltadisty = fabs(1/rc->raydiry);
    if(rc->raydiry == 0)
      rc->deltadisty = 1e30;
    rc->perp_walldist = 0.0;
    rc->stepx = 0;
    rc->stepy = 0;
    mp->textur = NULL;

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
  int	hit;

	hit = 0;
  while(hit == 0)
  {
    if(rc->sidedistx < rc->sidedisty)
    {
      rc->sidedistx += rc->deltadistx;
      rc->mapx += rc->stepx;
      mp->textur = mp->so_texture;
      if(rc->raydirx > 0)
        mp->textur = mp->no_texture;
    }
    else
    {
      rc->sidedisty += rc->deltadisty;
      rc->mapy += rc->stepy;
      mp->textur = mp->we_texture;
      if(rc->raydiry > 0)
        mp->textur = mp->ea_texture;
    }
    if (mp->map1[rc->mapx][rc->mapy] > 0)
      hit = 1;
  }
}

void  draw_line(t_raycast *rc, t_map_info *mp)
{
  if (mp->textur == mp->no_texture || mp->textur == mp->so_texture)
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
  if (mp->textur == mp->no_texture || mp->textur == mp->so_texture)
		rc->wallx = mp->info_player->y_pos + rc->perp_walldist * rc->raydiry;
	else
		rc->wallx = mp->info_player->x_pos + rc->perp_walldist * rc->raydirx;
  rc->wallx -= floor(rc->wallx);
}

void raycast_data(t_map_info *mp)
{
  int x;
  t_raycast *rc;
  rc = (t_raycast *)malloc (sizeof(t_raycast));
    if(!rc)
      return ;
  x = 0;
  mlx_destroy_image(mp->mlx, mp->img->img);
	mp->img->img = mlx_new_image(mp->mlx, WIDTH, HEIGHT);
  while(x < WIDTH)
  {
    get_coordinate(rc, x, mp);
    get_side_dist(mp, rc);
    add_algo(rc, mp);
    draw_line(rc, mp);
    draw_line_pixel(rc, mp, x);
    x++;
  }
  mlx_put_image_to_window(mp->mlx , mp->win ,mp->img, 0, 0);
  free(rc);
}
           
