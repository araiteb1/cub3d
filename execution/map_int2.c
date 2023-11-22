/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_int2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:40:40 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/22 08:52:19 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	len_line(char const *str, char sep)
{
	int	wcount;
	int	i;

	wcount = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == sep)
			wcount++;
		i++;
	}
	wcount++;
	return (wcount);
}

size_t	word_len(char const *str, char sep)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != sep)
		len++;
	return (len);
}

size_t	max_len_line(const char *str, char sep)
{
	int	i;
	int	len;
	int	mxlen;
	int	cur_len;

	mxlen = 0;
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		cur_len = word_len(str + i, sep);
		if (mxlen < cur_len)
			mxlen = cur_len;
		i += cur_len + 1;
	}
	return (mxlen);
}

void	get_coord_direct(t_map_info *mp, char direc)
{
	if (direc == 'W' || direc == 'E')
	{
		mp->info_player->dirx = 0;
		mp->info_player->diry = (-(direc == 'W') || 1.0);
		mp->info_player->planex = 0.66 * (-(direc == 'W') || 1.0);
		mp->info_player->planey = 0.0;
	}
	else if (direc == 'N' || direc == 'S')
	{
		mp->info_player->dirx = (-(direc == 'S') || 1.0);
		mp->info_player->diry = 0.0;
		mp->info_player->planex = 0.0;
		mp->info_player->planey = -0.66 * (-(direc == 'S') || 1.0);
	}
}

void	re_adapte_img(t_map_info *mp)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_put(mp, x, y, 0);
			x++;
		}
		y++;
	}
}
