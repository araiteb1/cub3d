/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:45:18 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/16 16:43:54 by araiteb          ###   ########.fr       */
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
#include"mlx.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

# define WIDTH 1280
# define HEIGHT 720
# define TILE_SIZE 64

# define MVSPEED			0.5
# define ROTSPEED			0.3

#define MINIMAP_SCALE_FACTOR 2

#define TEXWIDTH 6
#define TEXHEIGHT 6


#define KEY_RIGHT 124
#define KEY_LEFT 123
#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_ESC 53
#define KEY_A 0
#define KEY_D 2
#define KEY_W 13
#define KEY_S 1

#define COLOR_RED 0xFF0000FF
#define COLOR_GREEN 0x0000FF00
#define COLOR_BLUE 0x000000FF
#define COLOR_WHITE 0x00FFFFFF
#define COLOR_BLACK 0x00000000
#define COLOR_YELLOW 0x00FFFF00


typedef struct s_img
{
	void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     end;
    int     width;
    int     height;
    void    *ptr;
}	t_img;

typedef struct s_player
{
	double 			x_pos;
	double 			y_pos;
	double			dirx;
    double			diry;
    double			planex;
    double			planey;
	double 			rotationAngle;
	double 			moveSpeed;
	double			rotationSpeed;
}	t_player;


typedef struct	s_map_info
{
	char **map;
	int **map1;
	int map1_height;
	int map1_width;
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
	void 			*mlx;
	void 			*win;
	t_img			*img;
	double		pos_tex;
	double		step_tex;
	int			x_tex;
	int			y_tex;
	char		*textur;
	char		*textur1;
	t_img	*texture;
	char		**paths;
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
t_player *init_player(t_map_info *);
double playerAngle(t_map_info *map_info);
void get_player_position(t_map_info *map_info, t_player *player);
void init_mlx(t_map_info *map_info);
void printInfoPlayer(t_player *player);


void	init_data_dir(t_map_info *mp,char dir);
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
t_map_info *init_map(char *fileName);
void free_map(char **map);
void free_map_info(t_map_info *map_info);
void parsing(t_map_info *map_info);
void printMap(t_map_info *map_info);

//file_parsing.c
void read_textures(int fd, t_map_info *map_info);
void fill_textures(t_map_info *map_info, char *line);
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
int check_textures(t_map_info *map_info);
int count_lines(int fd, t_map_info *map_info);
void read_map(int fd, t_map_info *map_info);
int skip_textures(t_map_info *map_info, char *line);
int check_line_of_map(char *line);

// file_parsing_3.c
void fill_map(t_map_info *map_info);
int get_biggest_line(char **map);
int surround_map(char **map, int num_lines);
int check_all_spaces(char *line);

//file_parsing_4.c
int check_paths(t_map_info *map_info);
char *get_path(char *line);
void init_path(t_map_info *map_info);
void free_paths(t_map_info *map_info);

/**************************************************************/

//exec
void raycast_data(t_map_info *mp);
void  draw_line(t_raycast *rc, t_map_info *mp);
void  add_algo(t_raycast *rc, t_map_info *mp);
void  get_side_dist(t_map_info *mp, t_raycast *rc);
void  get_coordinate(t_raycast *rc, int x, t_map_info *mp);
void draw_line_pixel(t_raycast *rc, t_map_info *mp, int x);

void  rotation(t_map_info *mp, int key);
int    close_win(t_map_info *mp);
int key_definie(int key ,t_map_info *mp);
int color_for_tex(t_map_info *mp);
void    init_data_tex(t_raycast *rc, t_map_info *mp);
char 	*join_raw_map(t_map_info *mp);
#endif