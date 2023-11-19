/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_raycas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:30:28 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/19 04:41:29 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_coordinate(t_raycast *rc, int x, t_map_info *mp)
{
	rc->camerax = 2.0 * x / WIDTH - 1.0;
	rc->raydirx = mp->info_player->dirx + mp->info_player->planex * rc->camerax;
	rc->raydiry = mp->info_player->diry + mp->info_player->planey * rc->camerax;
	// printf("%f || %f \n", mp->info_player->x_pos, mp->info_player->y_pos);
	// exit(0);
	rc->mapx = (int)mp->info_player->x_pos;
	rc->mapy = (int)mp->info_player->y_pos;
	rc->sidedistx = 0.0;
	rc->sidedisty = 0.0;
	rc->deltadistx = fabs(1 / rc->raydirx);
	if (rc->raydirx == 0)
		rc->deltadistx = 1e30;
	rc->deltadisty = fabs(1 / rc->raydiry);
	if (rc->raydiry == 0)
		rc->deltadisty = 1e30;
	rc->perp_walldist = 0.0;
	rc->stepx = 0.0;
	rc->stepy = 0.0;
	mp->textur = NULL;
}

void	get_side_dist(t_map_info *mp, t_raycast *rc)
{
	// printf("side_dist ::: %f || %f \n",rc->raydirx,rc->raydiry );
	// printf("side_dist2 ::: %f || %f || %d || %d || %f || %f \n",mp->info_player->x_pos,rc->deltadistx, rc->mapx, rc->mapy, mp->info_player->y_pos,rc->deltadisty);
	if (rc->raydirx < 0)
	{
		rc->stepx = -1;
		rc->sidedistx = (mp->info_player->x_pos - rc->mapx) * rc->deltadistx;
		// printf("cond ::: %f \n",rc->sidedistx );
	}
	else
	{
		rc->stepx = 1;
		rc->sidedistx = (rc->mapx + 1.0 - mp->info_player->x_pos)
			* rc->deltadistx;
		// printf("cond ::: %f \n",rc->sidedistx );
	}
	if (rc->raydiry < 0)
	{
		rc->stepy = -1;
		rc->sidedisty = (mp->info_player->y_pos - rc->mapy) * rc->deltadisty;
		// printf("cond ::: %f \n",rc->sidedisty );
	}
	else
	{
		rc->stepy = 1;
		rc->sidedisty = (rc->mapy + 1.0 - mp->info_player->y_pos)
			* rc->deltadisty;
		// printf("cond ::: %f \n",rc->sidedisty );
	}
}

void	add_algo(t_raycast *rc, t_map_info *mp)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		// printf("ALGO add ======>%f || %f || %d\n",rc->sidedistx,rc->sidedisty, mp->t[rc->mapx][rc->mapy]);
		// printf("ALGO add2 ======>%d ||  %d\n",rc->mapx,rc->mapy);
		// printf("ALGO add3 ======>[%d]\n",mp->t[1][25]);
		if (rc->sidedistx < rc->sidedisty)
		{
			rc->sidedistx += rc->deltadistx;
			rc->mapx += rc->stepx;
			mp->textur = mp->texture[1];
			if (rc->raydirx > 0)
				mp->textur = mp->texture[0];
		}
		else
		{
			rc->sidedisty += rc->deltadisty;
			rc->mapy += rc->stepy;
			mp->textur = mp->texture[2];
			if (rc->raydiry > 0)
				mp->textur = mp->texture[3];
		}
		if (mp->map1[rc->mapx][rc->mapy] > 0)
			hit = 1;
	}
	// printf("ALGO add4 ======>[%d] || [%d] || [%d] || [%d]\n",mp->t[rc->mapx][rc->mapy], hit, rc->mapx, rc->mapy);
	
}

void	draw_line(t_raycast *rc, t_map_info *mp)
{
	// printf("1======>%f || %f \n",rc->sidedistx,rc->deltadistx);
	if (mp->textur == mp->texture[0] || mp->textur == mp->texture[1])
		rc->perp_walldist = rc->sidedistx - rc->deltadistx;
	else
		rc->perp_walldist = rc->sidedisty - rc->deltadisty;
	rc->line = (int)(HEIGHT / rc->perp_walldist);
	// printf("======>%f || %d \n",rc->perp_walldist,rc->line);
	rc->start = -rc->line / 2.0 + HEIGHT / 2.0;
	if (rc->start < 0)
		rc->start = 0;
	rc->end = rc->line / 2.0 + HEIGHT / 2.0;
	if (rc->end >= HEIGHT)
		rc->end = HEIGHT - 1;
	if (mp->textur == mp->texture[0] || mp->textur == mp->texture[1])
		rc->wallx = mp->info_player->y_pos + rc->perp_walldist * rc->raydiry;
	else
		rc->wallx = mp->info_player->x_pos + rc->perp_walldist * rc->raydirx;
	rc->wallx -= floor(rc->wallx);
}

void	raycast_data(t_map_info *mp)
{
	int			x;
	t_raycast	*rc;

	rc = (t_raycast *)malloc (sizeof(t_raycast));
	if (!rc)
		return ;
	x = 0;
	while (x < WIDTH)
	{
		get_coordinate(rc, x, mp);
		get_side_dist(mp, rc);
		add_algo(rc, mp);
		draw_line(rc, mp);
		draw_line_pixel(rc, mp, x);
		x++;
	}
	mlx_put_image_to_window(mp->mlx, mp->win, mp->img, 0, 0);
	free (rc);
}
