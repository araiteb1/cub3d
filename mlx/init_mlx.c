/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:04:25 by ahaloui           #+#    #+#             */
/*   Updated: 2023/10/25 15:22:48 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void get_player_position(t_map_info **map_info, t_player **player)
{
    int i;
    int j;

    i = 0;
    while (i < (*map_info)->num_lines)
    {
        j = 0;
        while (j < (*map_info)->num_cols)
        {
            if (is_palyer((*map_info)->map[i][j]))
            {
                (*player)->x_pos = j;
                (*player)->y_pos = i;
                return ;
            }
            j++;
        }
        i++;
    }
}


double playerAngle(t_map_info *map_info, int x, int y)
{
	if ((map_info)->map[y][x] == 'W')
		return (M_PI);
	else if ((map_info)->map[y][x] == 'N')
		return (3 * M_PI / 2);
	else if ((map_info)->map[y][x] == 'S')
		return (M_PI / 2);
	return (0);
}



void init_player(t_map_info **map_info)
{
    (*map_info)->info_player = malloc(sizeof(t_player));
    if (!(*map_info)->info_player)
        writing_error("Failed to allocate memory");
    get_player_position(map_info, &(*map_info)->info_player);
    (*map_info)->info_player->x = ((*map_info)->info_player->x_pos * TILE_SIZE ) +(TILE_SIZE / 2);
    (*map_info)->info_player->y = ((*map_info)->info_player->y_pos * TILE_SIZE ) +(TILE_SIZE / 2);
    (*map_info)->info_player->rotationAngle = playerAngle(*map_info, (*map_info)->info_player->x_pos, (*map_info)->info_player->y_pos);
    (*map_info)->info_player->moveSpeed = 3;
    (*map_info)->info_player->rotationSpeed = 2 * (M_PI / 180);
    (*map_info)->info_player->fieldOfView = 60 * (M_PI / 180);
    (*map_info)->info_player->num_rays = WIDTH / 2;
}


void printInfoPlayer(t_player *player)
{
    printf("rotationAngle = %f\n", player->rotationAngle);
    printf("moveSpeed = %f\n", player->moveSpeed);
    printf("rotationSpeed = %f\n", player->rotationSpeed);
}
