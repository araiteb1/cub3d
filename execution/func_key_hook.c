/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_key_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:30:21 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/23 08:03:53 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotation(t_map_info *mp, int key)
{
	double	rotspeed;
	double	new_direcx;

	rotspeed = ROTSPEED;
	if (key == KEY_RIGHT)
		rotspeed = -ROTSPEED;
	new_direcx = mp->info_player->dirx;
	mp->info_player->dirx = new_direcx * cos(rotspeed)
		- mp->info_player->diry * sin(rotspeed);
	mp->info_player->diry = new_direcx * sin(rotspeed)
		+ mp->info_player->diry * cos(rotspeed);
	new_direcx = mp->info_player->planex;
	mp->info_player->planex = new_direcx * cos(rotspeed)
		- mp->info_player->planey * sin(rotspeed);
	mp->info_player->planey = new_direcx * sin(rotspeed)
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
	ft_free_matrix(mp->map1, mp->map1_height);
	if (mp->img)
		free (mp->img);
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
	raycast_data(mp);
	return (1);
}
