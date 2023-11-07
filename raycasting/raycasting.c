/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:24:40 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/07 03:46:29 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float remainder1(float x, float y)
{
    float result;
    result = x - (int)(x / y) * y;
    if (result < 0)
        result += y;
    return (result);
}

float normalizeAngle(float angle)
{
    angle = remainder1(angle, (2 * M_PI));
    if (angle < 0)
        angle = (2 * M_PI) + angle;
    return (angle);
}

// int hasWallAt(float x, float y, t_map_info **map_info)
// {
//     int mapGridIndexX;
//     int mapGridIndexY;

//     mapGridIndexX = floor(x / TILE_SIZE);
//     mapGridIndexY = floor(y / TILE_SIZE);
//     if (mapGridIndexX < 0 || mapGridIndexX > (*map_info)->num_cols || mapGridIndexY < 0 || mapGridIndexY > (*map_info)->num_lines)
//         return (1);
//     return ((*map_info)->map[mapGridIndexY][mapGridIndexX] == 1);
// }

float distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
    return (sqrtf((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void castRay(double rayAngle, int stripId, t_map_info **map_info)
{
    rayAngle = normalizeAngle(rayAngle);
    
    int isRayFacingDown;
    int isRayFacingUp;

    int isRayFacingRight;
    int isRayFacingLeft;
    
    float xintercept;
    float yintercept;
    
    float xstep;
    float ystep;

    int foundHorzWallHit = 0;
    float horzWallHitX = 0;
    float horzWallHitY = 0;
    int horzWallContent = 0;

    if (rayAngle > 0 && rayAngle < M_PI)
        isRayFacingDown = 1;
    else
        isRayFacingDown = 0;
    if (rayAngle < 0.5 * M_PI || rayAngle > 1.5 * M_PI)
        isRayFacingRight = 1;
    else
        isRayFacingRight = 0;

    isRayFacingLeft = !isRayFacingRight;
    isRayFacingUp = !isRayFacingDown;

    yintercept = floor((*map_info)->info_player->y_pos / TILE_SIZE) * TILE_SIZE;
    if (isRayFacingDown)
        yintercept += TILE_SIZE;
    xintercept = (*map_info)->info_player->x_pos + (yintercept - (*map_info)->info_player->y_pos) / tan(rayAngle);
    
    ystep = TILE_SIZE;
    if (isRayFacingUp)
        ystep *= -1;

    xstep = TILE_SIZE / tan(rayAngle);
    if ((isRayFacingLeft && xstep > 0) || (isRayFacingRight && xstep < 0))
        xstep *= -1;
        
    float nextHorzTouchX = xintercept;
    float nextHorzTouchY = yintercept;

    while (nextHorzTouchX >= 0 && nextHorzTouchX <= (*map_info)->num_cols * TILE_SIZE && nextHorzTouchY >= 0 && nextHorzTouchY <= (*map_info)->num_lines * TILE_SIZE)
    {
        float xToCheck = 0;
        float yToCheck = 0;

        xToCheck = nextHorzTouchX;
        if (isRayFacingUp)
            yToCheck = nextHorzTouchY - 1;
        else
            yToCheck = nextHorzTouchY;
        if (check_wall(*map_info, xToCheck, yToCheck))
        {
            horzWallHitX = nextHorzTouchX;
            horzWallHitY = nextHorzTouchY;
            horzWallContent = (*map_info)->map[1][2];
            foundHorzWallHit = 1;
            break;
        }
        else
        {
            nextHorzTouchX += xstep;
            nextHorzTouchY += ystep;
        }
    }

    // VERTICAL RAY-GRID INTERSECTION CODE
    int foundVertWallHit = 0;
    float vertWallHitX = 0;
    float vertWallHitY = 0;
    int vertWallContent = 0;
    
    yintercept = floor((*map_info)->info_player->y_pos / TILE_SIZE) * TILE_SIZE;
    if (isRayFacingRight)
        yintercept += TILE_SIZE;
    xintercept = (*map_info)->info_player->x_pos + (yintercept - (*map_info)->info_player->y_pos) * tan(rayAngle);

    ystep = TILE_SIZE;
    if (isRayFacingLeft)
        ystep *= -1;
    
    xstep = TILE_SIZE * tan(rayAngle);
    if ((isRayFacingUp && xstep > 0) || (isRayFacingDown && xstep < 0))
        xstep *= -1;
    
    float nextVertTouchX = xintercept;
    float nextVertTouchY = yintercept;

    while (nextVertTouchX >= 0 && nextVertTouchX <= (*map_info)->num_cols * TILE_SIZE && nextVertTouchY >= 0 && nextVertTouchY <= (*map_info)->num_lines * TILE_SIZE)
    {
        float xToCheck;
        float yToCheck = nextVertTouchY;
        if (isRayFacingLeft)
            xToCheck = nextVertTouchX - 1;
        else
            xToCheck = nextVertTouchX;
        if (check_wall(*map_info ,xToCheck, yToCheck))
        {
            vertWallHitX = nextVertTouchX;
            vertWallHitY = nextVertTouchY;
            vertWallContent = (*map_info)->map[(int)floor(yToCheck / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)];
            foundVertWallHit = 1;
            break;
        }
        else
        {
            nextVertTouchX += xstep;
            nextVertTouchY += ystep;
        }
    }

    // Calculate both horizontal and vertical distances and choose the smallest value
    float horzHitDistance;
    float vertHitDistance;
    
    if (foundHorzWallHit)
        horzHitDistance = distanceBetweenPoints((*map_info)->info_player->x_pos, (*map_info)->info_player->y_pos, horzWallHitX, horzWallHitY);
    else
        horzHitDistance = FLT_MAX;

    if (foundVertWallHit)
        vertHitDistance = distanceBetweenPoints((*map_info)->info_player->x_pos, (*map_info)->info_player->y_pos, vertWallHitX, vertWallHitY);
    else
        vertHitDistance = FLT_MAX;
    
    if (vertHitDistance < horzHitDistance)
    {
        (*map_info)->info_player->rays[stripId].distance = vertHitDistance;
        (*map_info)->info_player->rays[stripId].wallHitX = vertWallHitX;
        (*map_info)->info_player->rays[stripId].wallHitY = vertWallHitY;
        (*map_info)->info_player->rays[stripId].wallHitContent = vertWallContent;
        (*map_info)->info_player->rays[stripId].wasHitVertical = 1;
    }
    else
    {
        (*map_info)->info_player->rays[stripId].distance = horzHitDistance;
        (*map_info)->info_player->rays[stripId].wallHitX = horzWallHitX;
        (*map_info)->info_player->rays[stripId].wallHitY = horzWallHitY;
        (*map_info)->info_player->rays[stripId].wallHitContent = horzWallContent;
        (*map_info)->info_player->rays[stripId].wasHitVertical = 0;
    }
    (*map_info)->info_player->rays[stripId].rayAngle = rayAngle;
    (*map_info)->info_player->rays[stripId].isRayFacingDown = isRayFacingDown;
    (*map_info)->info_player->rays[stripId].isRayFacingUp = isRayFacingUp;
    (*map_info)->info_player->rays[stripId].isRayFacingLeft = isRayFacingLeft;
    (*map_info)->info_player->rays[stripId].isRayFacingRight = isRayFacingRight;
}
 
void castAllrays(t_map_info **map_info)
{
    double rayAngle;
    int i;

    i = 0;
    rayAngle = (*map_info)->info_player->rotationAngle - ((*map_info)->info_player->fieldOfView / 2);
    while (i < (*map_info)->info_player->num_rays)
    {
        castRay(rayAngle, i, map_info);
        rayAngle += (*map_info)->info_player->fieldOfView / (*map_info)->info_player->num_rays;
        i++;
    }
}



// void rander_rays(t_map_info **map_info)
// {
//     int i;
//     int color;
//     int j;
//     int x1;
//     int y1;
//     int x2;
//     int y2;

//     i = 0;
//     j = 0;
//     while (i < (*map_info)->info_player->num_rays)
//     {
//         x1 = ((*map_info)->info_player->x) * MINIMAP_SCALE_FACTOR;
//         y1 = ((*map_info)->info_player->y) * MINIMAP_SCALE_FACTOR;
//         x2 = (*map_info)->info_player->rays[i].wallHitX * MINIMAP_SCALE_FACTOR;
//         y2 = (*map_info)->info_player->rays[i].wallHitY * MINIMAP_SCALE_FACTOR;
//         color = COLOR_RED;
//         rander_line_player(*map_info, x1, y1, x2, y2);
//         i++;
//     }
// }