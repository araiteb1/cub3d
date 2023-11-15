/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:04:25 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/15 14:18:10 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void get_player_position(t_map_info *map_info, t_player *player)
{
    int i;
    int j;

    i = 0;
    while (i < map_info->num_lines)
    {
        j = 0;
        while (j < map_info->num_cols)
        {
            if (is_palyer(map_info->map[i][j]))
            {
                player->x_pos = i;
                player->y_pos = j;
                return ;
            }
            j++;
        }
        i++;
    }
}

void	init_data_dir(t_map_info *mp, char dir)
{
	if (mp->info_player->rotationAngle == 0 || mp->info_player->rotationAngle == M_PI)
	{
		mp->info_player->dirx = 0;
		mp->info_player->diry = (-(dir == 'W') || 1.0);
		mp->info_player->planex = 0.66 * (-(dir == 'W') || 1.0);
		mp->info_player->planey = 0.0;
	}
	else if (mp->info_player->rotationAngle == (3 * M_PI / 2) || mp->info_player->rotationAngle == (M_PI / 2))
	{
		mp->info_player->dirx = (-(dir == 'S') || 1.0);
		mp->info_player->diry = 0.0;
		mp->info_player->planex = 0.0;
		mp->info_player->planey = -0.66 * (-(dir == 'S') || 1.0);
	}
}

double playerAngle(t_map_info *mp)
{
    int i = 0;
    char *str;

    str = join_raw_map(mp);
    while(str[i])
    {
        if (str[i] == 'W')
            return (M_PI);
        else if ( str[i] == 'N')
            return (3 * M_PI / 2);
        else if  (str[i] == 'S')
            return (M_PI / 2);
        i++;
    }
	return (0);
}

t_player *init_player(t_map_info *mInfo)
{
    t_player *map_info;

    map_info = malloc(sizeof(t_player));
    if (!map_info)
        writing_error("Failed to allocate memory");
    get_player_position(mInfo, map_info);
    map_info->rotationAngle = playerAngle(mInfo);
    map_info->moveSpeed = 3;
    map_info->rotationSpeed = 2 * (M_PI / 180);
    return map_info;
}


void printInfoPlayer(t_player *player)
{
    printf("rotationAngle = %f\n", player->rotationAngle);
    printf("moveSpeed = %f\n", player->moveSpeed);
    printf("rotationSpeed = %f\n", player->rotationSpeed);
}
