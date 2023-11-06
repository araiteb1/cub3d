/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:02:08 by ahaloui           #+#    #+#             */
/*   Updated: 2023/10/22 13:11:24 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void move_s(t_map_info *map_info, t_player **player)
{
	double newPlayerX;
	double newPlayerY;
	
	newPlayerX = (*player)->x - cos((*player)->rotationAngle) * (*player)->moveSpeed;
	newPlayerY = (*player)->y - sin((*player)->rotationAngle) * (*player)->moveSpeed;
	if (!check_if_all_walls(map_info, newPlayerX, newPlayerY))
	{
		(*player)->x = newPlayerX;
		(*player)->y = newPlayerY;
	}
}

void move_w(t_map_info *map_info, t_player **player)
{
	double newPlayerX;
	double newPlayerY;

	newPlayerX = (*player)->x + cos((*player)->rotationAngle) * (*player)->moveSpeed;
	newPlayerY = (*player)->y + sin((*player)->rotationAngle) * (*player)->moveSpeed;
	if (!check_if_all_walls(map_info, newPlayerX, newPlayerY))
	{
		(*player)->x = newPlayerX;
		(*player)->y = newPlayerY;
	}
}

void move_right(t_map_info *map_info, t_player **player)
{
	(void)map_info;
    (*player)->rotationAngle += (*player)->rotationSpeed;
}

void move_left(t_map_info *map_info, t_player **player)
{
	(void)map_info;
    (*player)->rotationAngle -= (*player)->rotationSpeed;
}

void move_a(t_map_info *map_info, t_player **player)
{
	double newPlayerX;
	double newPlayerY;

	newPlayerX = (*player)->x - cos((*player)->rotationAngle + M_PI / 2) * (*player)->moveSpeed;
	newPlayerY = (*player)->y + sin((*player)->rotationAngle - M_PI / 2) * (*player)->moveSpeed;
	if (!check_if_all_walls(map_info, newPlayerX, newPlayerY))
	{
		(*player)->x = newPlayerX;
		(*player)->y = newPlayerY;
	}
}

void move_d(t_map_info *map_info, t_player **player)
{
	double newPlayerX;
	double newPlayerY;

	newPlayerX = (*player)->x + cos((*player)->rotationAngle + M_PI / 2) * (*player)->moveSpeed;
	newPlayerY = (*player)->y - sin((*player)->rotationAngle - M_PI / 2) * (*player)->moveSpeed;
	if (!check_if_all_walls(map_info, newPlayerX, newPlayerY))
	{
		(*player)->x = newPlayerX;
		(*player)->y = newPlayerY;
	}
}

