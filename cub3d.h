/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:17:03 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/22 09:22:56 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

# define WIDTH 1280
# define HEIGHT 720

# define MVSPEED			0.5
# define ROTSPEED			0.2

# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_ESC 53
# define KEY_A 0
# define KEY_D 2
# define KEY_W 13
# define KEY_S 1

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		end;
	int		width;
	int		height;
	void	*ptr;
}	t_img;
typedef struct s_player
{
	double	x_pos;
	double	y_pos;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
}	t_player;

typedef struct s_raycast
{
	int		line;
	int		start;
	int		end;
	double	wallx;
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	deltadistx;
	double	deltadisty;
	double	sidedistx;
	double	sidedisty;
	double	perp_walldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
}	t_raycast;

typedef struct s_map_info
{
	char		**map;
	int			**map1;
	int			num_lines;
	int			map1_height;
	int			map1_width;
	int			num_cols;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*c_texture;
	char		*f_texture;
	int			c_color;
	int			f_color;
	char		**paths;
	void		*mlx;
	void		*win;
	double		pos_tex;
	double		step_tex;
	int			x_tex;
	int			y_tex;
	char		*fileName;
	t_img		*img;
	t_img		*textur;
	t_img		*texture[4];
	t_player	*info_player;
}	t_map_info;

// file1.c
void		writing_error(char *str);
t_map_info	*init_map(char *fileName);
int			ft_strcmp(char *s1, char *s2);
int			check_file_name(char *str);
int			check_all_parsing(int ac, char *str, t_map_info *map_info);

// file2.c
int		valide_texture(char *line);
int		help_fill_textures(t_map_info *map_info, char *line);
int		fill_textures(t_map_info *map_info, char *line);
int		help_read_textures(t_map_info *map_info, char *line, int *nb_textures);
int		read_textures(t_map_info *map_info);
// file3.c
int		check_textures(t_map_info *map_info);
char	*get_path(char *str);
int		init_path(t_map_info *map_info);
//file4.c
int		get_nb_commas(char *line);
int		get_size_array(char **split);
int		only_digit(char *color);
int		create_trgb(int t, int r, int g, int b);
int		get_color(char *line);
int		fill_colors_and_free(char **colors);
//file5.c
int		read_map(t_map_info *map_info);
void	help_read_map(int fd, t_map_info *map_info, char *line);
int		skip_textures(t_map_info *map_info, char *line);
int		count_lines_part_1(int fd, char *line);
int		count_lines_part_2(t_map_info *map_info);
//file6.c
int		check_line_of_map(char *line);
int		get_biggest_line(char **map);
int		check_all_spaces(char *line);
void	fill_map(t_map_info *map_info);
int		surround_map(t_map_info *map_info);

//file7.c
int		check_each_side(char **map, int i, int j);
int		isMapClosed(t_map_info *map_info);
int		get_nb_player(t_map_info *map_info);

//file8.c
void	free_all_parsing(t_map_info *map_info);
void	free_map(char **map);
void	free_paths(t_map_info *map_info);
void	free_map_info(t_map_info *map_info);

//*--------execution-----------*//

void	pars_textures(t_map_info *mp, char *path, t_img **texture);
void	init_data_tex(t_raycast *rc, t_map_info *mp);
void	raycast_data(t_map_info *mp);
void	draw_line(t_raycast *rc, t_map_info *mp);
void	add_algo(t_raycast *rc, t_map_info *mp);
void	get_side_dist(t_map_info *mp, t_raycast *rc);
void	get_coordinate(t_raycast *rc, int x, t_map_info *mp);
void	draw_line_pixel(t_raycast *rc, t_map_info *mp, int x);
void	rotation(t_map_info *mp, int key);
int		close_win(t_map_info *mp);
int		key_definie(int key, t_map_info *mp);
int		color_for_tex(t_map_info *mp);
void	init_data_tex(t_raycast *rc, t_map_info *mp);
char	*join_raw_map(t_map_info *mp);
void	init_int_map(t_map_info *mp);
void	get_coord_direct(t_map_info *mp, char dir);
void	init_mlx(t_map_info *map_info);
void	pixel_put(t_map_info *mp, int x, int y, int color);
int		len_line(char const *str, char sep);
size_t	word_len(char const *str, char sep);
size_t	max_len_line(const char *str, char sep);
void	re_adapte_img(t_map_info *mp);
/*--------move-------*/

void	check_if_wall(t_map_info *mp, double dx, double dy);
void	move_up(t_map_info *mp);
void	move_down(t_map_info *mp);
void	move_left1(t_map_info *mp);
void	move_right1(t_map_info *mp);
void	ft_free_matrix(int **str, int size);
#endif