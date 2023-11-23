/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 00:18:09 by araiteb           #+#    #+#             */
/*   Updated: 2023/11/22 08:52:19 by araiteb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	init_data_map1(t_map_info *mp, char *lines)
{
	mp->map1_height = len_line(lines, '\n');
	mp->map1 = (int **)malloc(mp->map1_height * sizeof(int *));
	if (!mp->map1)
		return ;
	mp->map1_width = max_len_line(lines, '\n');
}

void	init_line_map1(char c, int i, int *j, t_map_info *mp)
{
	if (c == ' ')
		mp->map1[i][(*j)++] = 1;
	else if (c == '0' || c == '1')
		mp->map1[i][(*j)++] = c - '0';
	else
		get_coord_direct(mp, c);
}

void	init_int_map(t_map_info *mp)
{
	int		i;
	int		j;
	int		k;
	char	*lines;

	lines = join_raw_map(mp);
	init_data_map1(mp, lines);
	k = 0;
	i = -1;
	while (++i < mp->map1_height && lines[k])
	{
		mp->map1[i] = (int *)malloc((mp->map1_width + 1) * sizeof(int));
		if (!mp->map1[i])
			return ;
		j = 0;
		while (lines[k] && lines[k] != '\n' && j < mp->map1_width)
		{
			init_line_map1(lines[k], i, &j, mp);
			k++;
		}
		k += (lines[k] == '\n');
	}
	free(lines);
}
