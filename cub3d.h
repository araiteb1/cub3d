/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:17:03 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/18 22:09:58 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"


typedef struct s_player
{
	double x_pos;
	double y_pos;
	double         dirx;
    double         diry;
    double         planex;
    double         planey;
	double rotationAngle;
	double moveSpeed;
	double rotationSpeed;
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
	char		**paths;
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
char	 *get_path(char *str);
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
int		skip_textures(t_map_info *map_info,char *line);
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
void 	free_all_parsing(t_map_info *map_info);
void	free_map(char **map);
void	free_paths(t_map_info *map_info);
void	free_map_info(t_map_info *map_info);
# endif