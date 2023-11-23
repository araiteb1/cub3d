/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:19:30 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/23 15:21:51 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	main(int ac, char **av)
{
	t_map_info	*map_info;

	map_info = init_map(av[1]);
	atexit(ff);
	init_mlx(map_info);
	check_all_parsing(ac, av[1], map_info);
	init_int_map(map_info);
	raycast_data(map_info);
	mlx_hook(map_info->win, 2, 0, key_definie, map_info);
	mlx_hook(map_info->win, 17, 0, close_win, map_info);
	mlx_loop(map_info->mlx);
	free_all_parsing(map_info);
	return (0);
}
