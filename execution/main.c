/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:30:28 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/05 22:30:29 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "cub3d.h"
  int         worldMap[MAPWIDTH][MAPHEIGHT]=
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
void  init_data(t_info *dt)
{
  dt->mlx = mlx_init();
  if(!dt->mlx)
    exit (1);
  dt->win = mlx_new_window(dt->mlx, WIDTH, HEIGHT, "win");
  if(!dt->win)
    exit (1);
  dt->img = (t_imag *)malloc(sizeof(t_imag));

  dt->img->ptr= mlx_new_image(dt->mlx, WIDTH, HEIGHT);
  if (!dt->img->ptr)
    exit (1);
  dt->img->data = mlx_get_data_addr(dt->img->ptr, &dt->img->bits_of_pixel, &dt->img->size_line,&dt->img->end);
  dt->posx = 22;
  dt->posy = 12;
  dt->dirx = -1;
  dt->diry = 0;
  dt->planex = 0;
  dt->planey = 0.66;
  dt->time = 0;
  dt->oldtime = 0;

}
void  get_coordinate(t_raycast *rc, int x, t_info *dt)
{
  rc->camerax = (2.0 * x )/ (WIDTH - 1.0);
  rc->raydirx = dt->dirx + dt->planex * rc->camerax;
  rc->raydiry = dt->diry + dt->planey * rc->camerax;
  rc->mapx = (int)dt->posx;
  rc->mapy = (int)dt->posy;
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

void  get_side_dist(t_info *dt, t_raycast *rc)
{
  if(rc->raydirx < 0)
  {
    rc->stepx = -1;
    rc->sidedistx = (dt->posx - rc->mapx) * rc->deltadistx;
  }
  else
  {
    rc->stepx = 1;
    rc->sidedistx = (rc->mapx + 1.0 - dt->posx) * rc->deltadistx;
  }
  if(rc->raydiry < 0)
  {
    rc->stepy = -1;
    rc->sidedisty = (dt->posy - rc->mapy) * rc->deltadisty;
  }
  else
  {
    rc->stepy = 1;
    rc->sidedisty = (rc->mapy + 1.0 - dt->posy) * rc->deltadisty;
  }
}

void  add_algo(t_raycast *rc)
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
    if (worldMap[rc->mapx][rc->mapy] > 0)
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

void raycast_data(t_info *dt)
{
  int x;
  t_raycast *rc;
  rc = (t_raycast *)malloc (sizeof(t_raycast));
    if(!rc)
      return ;
  x = 0;
  while(x < WIDTH)
  {
    get_coordinate(rc, x, dt);
    get_side_dist(dt, rc);
    add_algo(rc);
    draw_line(rc);
    draw_line_pixel(rc, dt, x);
    x++;
  }
  mlx_put_image_to_window(dt->mlx, dt->win, dt->img->ptr, 0, 0);
}
int main(int ac, char **av)
{
  (void)av;
  if (ac == 2)
  {
    t_info *dt;
    dt = (t_info *)malloc (sizeof(t_info));
    if(!dt)
      return (0);
    init_data(dt);
    raycast_data(dt);
    mlx_hook(dt->win, 17, 0, close_win, dt);
    mlx_hook(dt->win, 2, 0, key_definie, dt);
    mlx_loop (dt->mlx);
  }
  return (0);                               
}
                   
