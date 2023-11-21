/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 00:18:09 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/21 13:03:32 by araiteb          ###   ########.fr       */
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

char	*join_raw_map(t_map_info *mp)
{
	int		h;
	char	*lines;

	h = 0;
	lines = NULL;
	while (mp->map[h])
	{
		lines = ft_strjoin(lines, mp->map[h]);
		if (mp->map[h + 1])
			lines = ft_strjoin(lines, "\n");
		h++;
	}
	return (lines);
}

void	init_int_map(t_map_info *mp)
{
	int		i;
	int		j;
	int		k;
	char	*lines;

	lines = join_raw_map(mp);
	mp->map1_height = len_line(lines, '\n');
	mp->map1 = (int **)malloc(mp->map1_height * sizeof(int *));
	if (!mp->map1)
		return ;
	mp->map1_width = max_len_line(lines, '\n');
	k = 0;
	i = -1;
	j = ft_strlen(lines);
	while (++i < mp->map1_height)
	{
		mp->map1[i] = (int *)ft_calloc(mp->map1_width + 1, sizeof(int));
		j = 0;
		while (lines[k] && lines[k] != '\n' && j < mp->map1_width)
		{
			if (lines[k] == ' ')
				mp->map1[i][j++] = 1;
			else if (lines[k] == '0' || lines[k] == '1')
				mp->map1[i][j++] = lines[k] - '0';
			else
				init_data_dir(mp, lines[k]);
			k++;
		}
		k += (lines[k] == '\n');
	}
	free(lines);
}

void	init_data_dir(t_map_info *mp, char dir)
{
	if (dir == 'W' || dir == 'E')
	{
		mp->info_player->dirx = 0;
		mp->info_player->diry = (-(dir == 'W') || 1.0);
		mp->info_player->planex = 0.66 * (-(dir == 'W') || 1.0);
		mp->info_player->planey = 0.0;
	}
	else if (dir == 'N' || dir == 'S')
	{
		mp->info_player->dirx = (-(dir == 'S') || 1.0);
		mp->info_player->diry = 0.0;
		mp->info_player->planex = 0.0;
		mp->info_player->planey = -0.66 * (-(dir == 'S') || 1.0);
	}
}