/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:45:18 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/07 05:33:09 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <float.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./libmlx42/includes/MLX42.h"

# define WIDTH 2000
# define HEIGHT 1000
# define TILE_SIZE 64

# define MVSPEED			0.1
# define ROTSPEED			0.1

#define MINIMAP_SCALE_FACTOR 2

#define TEXWIDTH 64
#define TEXHEIGHT 64

#define KEY_RIGHT 262
#define KEY_LEFT 263
#define KEY_UP 264
#define KEY_DOWN 265
#define KEY_ESC 256

#define COLOR_RED 0xFF0000FF
#define COLOR_GREEN 0x0000FF00
#define COLOR_BLUE 0x000000FF
#define COLOR_WHITE 0x00FFFFFF
#define COLOR_BLACK 0x00000000
#define COLOR_YELLOW 0x00FFFF00

typedef struct s_ray
{
	double rayAngle;
	double wallHitX;
	double wallHitY;
	double distance;
	int wasHitVertical;
	int isRayFacingUp;
	int isRayFacingDown;
	int isRayFacingLeft;
	int isRayFacingRight;
	int wallHitContent;
}	t_ray;

typedef struct s_player
{
	double x_pos;
	double y_pos;
	double x;
	double y;
	double         dirx;
    double         diry;
    double         planex;
    double         planey;
	double rotationAngle;
	double moveSpeed;
	double rotationSpeed;
	double fieldOfView;
	double num_rays;
	// t_imag	*textur[4];
	t_ray *rays;
}	t_player;


typedef struct	s_map_info
{
	char **map;
	int num_lines;
	int num_cols;
	char *no_texture;
	char *so_texture;
	char *we_texture;
	char *ea_texture;
	char *c_texture;
	char *f_texture;
	int c_color;
	int f_color;
	char *fileName;
	t_player		*info_player;
	t_ray 			*rays;
	mlx_t 			*mlx;
	mlx_image_t		*img;
	double		pos_tex;
	double		step_tex;
	int			x_tex;
	int			y_tex;
	// t_imag		*texture;
	// void		*win;
	int key;
}	t_map_info;
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

/**************************************************************/
// init_mlx.c
void init_player(t_map_info **map_info);
double playerAngle(t_map_info *map_info, int x, int y);
void get_player_position(t_map_info **map_info, t_player **player);
void init_mlx(t_map_info *map_info);
void printInfoPlayer(t_player *player);



// player_move.c
void move_s(t_map_info *map_info, t_player **player);
void move_w(t_map_info *map_info, t_player **player);
void move_right(t_map_info *map_info, t_player **player);
void move_left(t_map_info *map_info, t_player **player);
void move_a(t_map_info *map_info, t_player **player);
void move_d(t_map_info *map_info, t_player **player);



// utils.c
void update_player(t_map_info *map_info, t_player **player);
int check_wall(t_map_info *map_info, double x, double y);
int	check_if_all_walls(t_map_info *data, double x, double y);
void key_hook(void *ptr);


// utils1.c
int		is_palyer(char c);
void	rander_line_player(t_map_info *map_info, int x0, int y0, int x1, int y1);
void	rander_player(t_map_info **map_info, int x, int y, int color);
void	rander_square(t_map_info **map_info, int x, int y, int color);
int		rander_map(t_map_info *map_info);



/**************************************************************/
// file_error.c
void writing_error(char *str);
int check_extension_of_file(char *fileName);
int check_each_side(char **map, int i, int j);
int isMapClosed(char **map, int num_lines);
int get_numebr_player(char **map, int lineCount);

// init_map.c
void init_map(t_map_info **map_info, char *fileName);
void free_map(char **map);
void free_map_info(t_map_info *map_info);
void parsing(t_map_info *map_info);
void printMap(t_map_info *map_info);

//file_parsing.c
void read_textures(int fd, t_map_info **map_info);
void fill_textures(t_map_info **map_info, char *line);
int valide_texture(char *line);
int get_color(char *line);
int free_colors(char **colors);

// file_parsing_1.c
int ft_strcmp(char *s1, char *s2);
int	create_trgb(int t, int r, int g, int b);
int only_digit(char *color);
int ft_size_of_array(char **array);
int count_number_of_commas(char *line);

// file_parsing_2.c
int check_textures(t_map_info **map_info);
int count_lines(int fd, t_map_info **map_info);
void read_map(int fd, t_map_info **map_info);
int skip_textures(t_map_info **map_info, char *line);
int check_line_of_map(char *line);

// file_parsing_3.c
void fill_map(t_map_info **map_info);
int get_biggest_line(char **map);
int surround_map(char **map, int num_lines);
int check_all_spaces(char *line);
/**************************************************************/

// raycasting
// void castAllrays(t_map_info **s_map_info);
// void castRay(double rayAngle, int stripId, t_map_info **map_info);
// void rander_rays(t_map_info **map_info);
//exec
void raycast_data(t_map_info *mp);
void  draw_line(t_raycast *rc);
void  add_algo(t_raycast *rc, t_map_info *mp);
void  get_side_dist(t_map_info *mp, t_raycast *rc);
void  get_coordinate(t_raycast *rc, int x, t_map_info *mp);
void  init_data_ray(t_player *dt);
void draw_line_pixel(t_raycast *rc, t_map_info *mp, int x);
//hook
// void  move(t_map_info *mp);
void  rotation(t_map_info *mp);
int     close_win(t_map_info *mp);
void key_definie(void *ptr);
int color_for_tex(t_map_info *mp);
void    init_data_tex(t_raycast *rc, t_map_info *mp);
#endif