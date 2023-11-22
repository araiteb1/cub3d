/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:33:46 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/22 14:49:26 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_if_wall(t_map_info *mp, double dx, double dy)
{
	if (mp->map1[(int)(mp->info_player->x_pos + dx)]
		[(int)(mp->info_player->y_pos + dy)] > 0)
		return ;
	mp->info_player->x_pos += dx;
	mp->info_player->y_pos += dy;
}

void	move_up(t_map_info *mp)
{
	double	dx;
	double	dy;
	double	mvspeed;

	mvspeed = MVSPEED * (1.0);
	dx = mp->info_player->dirx * mvspeed;
	dy = mp->info_player->diry * mvspeed;
	check_if_wall(mp, dx, dy);
}

void	move_down(t_map_info *mp)
{
	double	dx;
	double	dy;
	double	mvspeed;

	mvspeed = MVSPEED * (-1.0);
	dx = mp->info_player->dirx * mvspeed;
	dy = mp->info_player->diry * mvspeed;
	check_if_wall(mp, dx, dy);
}

void	move_left1(t_map_info *mp)
{
	double	dx;
	double	dy;
	double	mvspeed;

	mvspeed = MVSPEED * (1.0);
	dx = mp->info_player->planex * mvspeed;
	dy = mp->info_player->planey * mvspeed;
	check_if_wall(mp, dx, dy);
}

void	move_right1(t_map_info *mp)
{
	double	dx;
	double	dy;
	double	mvspeed;

	mvspeed = MVSPEED * (-1.0);
	dx = mp->info_player->planex * mvspeed;
	dy = mp->info_player->planey * mvspeed;
	check_if_wall(mp, dx, dy);
}
