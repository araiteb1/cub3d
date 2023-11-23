/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:06:05 by ahaloui           #+#    #+#             */
/*   Updated: 2023/11/23 13:57:20 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_nb_commas(char *line)
{
	int	i;
	int	nb_commas;

	i = 0;
	nb_commas = 0;
	while (line[i])
	{
		if (line[i] == ',')
			nb_commas++;
		i++;
	}
	return (nb_commas);
}

int	get_size_array(char **split)
{
	int	nb_size;

	nb_size = 0;
	while (split[nb_size])
		nb_size++;
	return (nb_size);
}

int	only_digit(char *color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (!ft_isdigit(color[i]) && color[i] != ' ' && color[i] != '+')
			return (1);
		i++;
	}
	return (0);
}

int	fill_colors_and_free(char **colors)
{
	int	color;
	int	i;

	i = 0;
	color = create_trgb(0, ft_atoi(colors[0]),
			ft_atoi(colors[1]), ft_atoi(colors[2]));
	while (colors[i])
	{
		free(colors[i]);
		i++;
	}
	free(colors);
	return (color);
}

int	get_color(char *line)
{
	char	**colors;
	int		i;

	i = 1;
	if (get_nb_commas(line) != 2)
		writing_error("Colors");
	colors = ft_split(&line[i], ',');
	i = -1;
	while (colors[++i])
	{
		if (check_is_digit(colors[i]))
			writing_error("Colors");
	}
	if (!colors || get_size_array(colors) != 3)
		writing_error("Colors");
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(colors[i]) < 0
			|| ft_atoi(colors[i]) > 255 
			|| only_digit(colors[i]))
			writing_error("Colors");
		i++;
	}
	return (fill_colors_and_free(colors));
}
