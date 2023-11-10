/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:27:36 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/10 05:34:21 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void printInfoRays(t_map_info *map_info)
// {
// 	int i;

// 	i = 0;
// 	while (i < map_info->info_player->num_rays)
// 	{
// 		//printf("rayAngle: %f, wallHitX: %f, wallHitY: %f, distance: %f, wasHitVertical: %d, isRayFacingUp: %d, isRayFacingDown: %d, isRayFacingLeft: %d, isRayFacingRight: %d, wallHitContent: %d\n", map_info->info_player->rays[i].rayAngle, map_info->info_player->rays[i].wallHitX, map_info->info_player->rays[i].wallHitY, map_info->info_player->rays[i].distance, map_info->info_player->rays[i].wasHitVertical, map_info->info_player->rays[i].isRayFacingUp, map_info->info_player->rays[i].isRayFacingDown, map_info->info_player->rays[i].isRayFacingLeft, map_info->info_player->rays[i].isRayFacingRight, map_info->info_player->rays[i].wallHitContent);
// 		i++;
// 	}
// }

// void init_rays(t_map_info **map_info)
// {
// 	int i;

// 	i = 0;
// 	(*map_info)->info_player->rays = malloc(sizeof(t_ray) * (*map_info)->info_player->num_rays);
// 	while (i < (*map_info)->info_player->num_rays)
// 	{
// 		(*map_info)->info_player->rays[i].rayAngle = (*map_info)->info_player->rotationAngle - ((*map_info)->info_player->fieldOfView / 2) + ((*map_info)->info_player->fieldOfView / (*map_info)->info_player->num_rays) * i;
// 		(*map_info)->info_player->rays[i].wallHitX = 0;
// 		(*map_info)->info_player->rays[i].wallHitY = 0;
// 		(*map_info)->info_player->rays[i].distance = 0;
// 		(*map_info)->info_player->rays[i].wasHitVertical = 0;
// 		(*map_info)->info_player->rays[i].isRayFacingUp = 0;
// 		(*map_info)->info_player->rays[i].isRayFacingDown = 0;
// 		(*map_info)->info_player->rays[i].isRayFacingLeft = 0;
// 		(*map_info)->info_player->rays[i].isRayFacingRight = 0;
// 		(*map_info)->info_player->rays[i].wallHitContent = 0;
// 		i++;
// 	}
	
// }
int	word_count(char const *str, char sep)
{
	int	wcount;
	int	flag;
	int	i;

	wcount = 0;
	flag = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == sep)
			flag = 0;
		else if (str[i] != sep && !flag)
		{
			flag = 1;
			wcount++;
		}
		i++;
	}
	return (wcount);
}
void	cln_exit(t_map_info *data, int status)
{
	(void) data;
	(void) status;
	exit(0);
}
void	*sf_calloc(t_map_info *data, size_t size)
{
	void	*ptr;
	char	*str;
	size_t	i;

	ptr = malloc(size);
	if (!ptr)
		cln_exit(data, EXIT_FAILURE);
	str = (char *)ptr;
	i = 0;
	while (i < size)
		str[i++] = (char)0;
	return (ptr);
}
size_t	word_len(char const *str, char sep)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != sep)
		len++;
	return (len);
}
size_t	max_word_len(const char *str, char sep)
{
	int	str_len;
	int	max_len;
	int	cur_len;
	int	i;

	str_len = ft_strlen(str);
	max_len = 0;
	i = 0;
	while (i < str_len)
	{
		cur_len = word_len(str + i, sep);
		if (cur_len > max_len)
			max_len = cur_len;
		i += cur_len + 1;
	}
	return (max_len);
}
char 	*join_raw_map(t_map_info *mp)
{
	int h;
	char *lines = NULL;

	h = 0;
	while(mp->map[h])
	{
		lines = ft_strjoin(lines, mp->map[h]);
		if (mp->map[h + 1])
			lines = ft_strjoin(lines, "\n");
		h++;	
	}
	return (lines);
}
void 	print_map_int(t_map_info *mp)
{
	int i;
	int j;

	i = 0;
	while(i < mp->map1_height)
	{
		j = 0;
		while(j < mp->map1_width)
			printf("%d", mp->map1[i][j++]);
		i++;
		printf("\n");
	}
	// exit(0);
}
void	init_int_map(t_map_info *mp)
{
	int	i;
	int	j;
	int	k;
	char *lines;

	lines = join_raw_map(mp);
	mp->map1_height = word_count(lines, '\n');
	mp->map1 = (int **)sf_calloc(mp, sizeof(int *) * mp->map1_height);
	mp->map1_width = max_word_len(lines, '\n');
	k = 0;
	i = -1;
	while (++i < mp->map1_height)
	{
		mp->map1[i] = (int *)sf_calloc(mp, sizeof(int) * mp->map1_width);
		j = 0;
		while (lines[k] && lines[k] != '\n')
		{
			
			if (lines[k] == ' ')
			{
				mp->map1[i][j++] = 1;
				k++;
			}
			else if (lines[k] == '0' || lines[k] == '1')
				mp->map1[i][j++] = lines[k++] - '0';
			else
				data_init_camera(mp,  i, j++, lines[k++]);
		}
		while (j < mp->map1_width)
			mp->map1[i][j++] = 1;
		k += (lines[k] == '\n');
	}
	free(lines);
	
}
int main(int ac, char **av)
{
	int fd;
	t_map_info *map_info;

	if (ac == 2)
	{
		if(!check_extension_of_file(av[1]))
			writing_error("Wrong file extension");
			
		map_info = init_map(av[1]);
		
		fd = open(map_info->fileName, O_RDONLY);
		if (fd == -1)
			writing_error("Failed to open file");
			
		/**************************************************/
		read_textures(fd, map_info);
		read_map(fd, map_info);
		fill_map(map_info);
		parsing(map_info);
		// printMap(map_info);
		/*************************************************/
		init_mlx(map_info);               
		map_info->info_player = init_player(map_info);
		init_int_map(map_info);
		raycast_data(map_info);
		mlx_loop_hook(map_info->mlx, key_definie, map_info);
		mlx_loop(map_info->mlx);
		/*************************************************/
		// close(fd);
		// free_map(map_info->map); 
		// free_map_info(map_info);
		/**************************************************/
	}
	else
		writing_error("Invalid number of argumets");
	return (0);
}