/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:29:56 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/05 22:29:57 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
#define CUB3D_H


#define MAPWIDTH 24
#define MAPHEIGHT 24
#define WIDTH 640
#define HEIGHT 480

# define MVSPEED			0.5
# define ROTSPEED			0.3

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <float.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "defkey.h"

typedef struct s_imag
{
	int		width;
	int		height;
	int		bits_of_pixel;
	int		size_line;
	int		end;
	void	*ptr;
	char	*data;
}	t_imag;

typedef struct s_info
{
    t_imag         *img;
    double         posx;
    void	        *mlx;
	void	        *win;
	void	        *img_mlx;
    double         posy;
    double         dirx;
    double         diry;
    double         planex;
    double         planey;
    double         time;
    double         oldtime;
    double          key;
}t_info;



typedef struct s_raycast
{
    int line;
    int start;
    int end;
    double wallx;
    double camerax;
    double raydirx;
    double raydiry;
    int  mapx;
    int  mapy;
    double deltadistx;
    double deltadisty;
    double sidedistx;
    double sidedisty;
    double perp_walldist;
    int stepx;
    int stepy;
    int hit;
    int side;
}t_raycast;


void    put_pixel_in_img(t_info *dt, int x, int y, int col);
void draw_line_pixel(t_raycast *rc, t_info *dt, int x);
void  init_data(t_info *dt);
void  get_coordinate(t_raycast *rc, int x, t_info *dt);
void  get_side_dist(t_info *dt, t_raycast *rc);
void  add_algo(t_raycast *rc);
void  draw_line(t_raycast *rc);
void	clr_img(t_info *dt);
void raycast_data(t_info *dt);
int key_definie(int key, t_info *dt);
void  rotation(t_info *dt);
void  move(t_info *dt);
int     close_win(t_info *dt);
// int main(int ac, char **av);
#endif