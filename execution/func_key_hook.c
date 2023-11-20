/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_key_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:30:21 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/20 04:14:37 by araiteb          ###   ########.fr       */
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

void	rotation(t_map_info *mp, int key)
{
	double	rotspeed;
	double	dir_new_x;

	rotspeed = ROTSPEED;
	if (key == KEY_RIGHT)
		rotspeed = -ROTSPEED;
	dir_new_x = mp->info_player->dirx;
	mp->info_player->dirx = dir_new_x * cos(rotspeed)
		- mp->info_player->diry * sin(rotspeed);
	mp->info_player->diry = dir_new_x * sin(rotspeed)
		+ mp->info_player->diry * cos(rotspeed);
	dir_new_x = mp->info_player->planex;
	mp->info_player->planex = dir_new_x * cos(rotspeed)
		- mp->info_player->planey * sin(rotspeed);
	mp->info_player->planey = dir_new_x * sin(rotspeed)
		+ mp->info_player->planey * cos(rotspeed);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
	str = NULL;
}

int	close_win(t_map_info *mp)
{
	mlx_clear_window(mp->mlx, mp->win);
	mlx_destroy_image(mp->mlx, mp->img->img);
	exit (0);
	return (1);
}

int	key_definie(int key, t_map_info *mp)
{
	if (key == KEY_ESC)
		close_win(mp);
	if (key == KEY_W)
		move_up(mp);
	if (key == KEY_S)
		move_down(mp);
	if (key == KEY_D)
		move_left1(mp);
	if (key == KEY_A)
		move_right1(mp);
	if (key == KEY_LEFT || key == KEY_RIGHT)
		rotation(mp, key);
	mlx_clear_window(mp->mlx, mp->win);
	mlx_destroy_image(mp->mlx, mp->img->img);
	mp->img->img = mlx_new_image(mp->mlx, WIDTH, HEIGHT);
	raycast_data(mp);
	return (1);
}
