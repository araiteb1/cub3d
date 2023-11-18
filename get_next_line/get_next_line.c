/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:18:57 by ahaloui           #+#    #+#             */
/*   Updated: 2022/11/25 14:10:46 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_new_line(char *stash)
{
	int		pos;
	char	*line;

	pos = 0;
	if (!stash[pos])
		return (NULL);
	while (stash[pos] && stash[pos] != '\n')
		pos++;
	line = malloc(pos + 2);
	if (!line)
		return (NULL);
	pos = 0;
	while (stash[pos] && stash[pos] != '\n')
	{
		line[pos] = stash[pos];
		pos++;
	}
	if (stash[pos] == '\n')
	{
		line[pos] = stash[pos];
		pos++;
	}
	line[pos] = '\0';
	return (line);
}

char	*ft_clean_stash(char *stash)
{
	int		pos;
	int		j;
	char	*new_stash;
	int		len;

	pos = 0;
	while (stash[pos] && stash[pos] != '\n')
		pos++;
	if (!stash[pos])
		return (free(stash), NULL);
	len = ft_strlen(stash) - pos;
	new_stash = malloc(len + 1);
	if (!new_stash)
		return (NULL);
	pos++;
	j = 0;
	while (stash[pos])
		new_stash[j++] = stash[pos++];
	new_stash[j] = '\0';
	return (free(stash), new_stash);
}

char	*ft_save(int fd, char *stash)
{
	char	*buff;
	int		nbytes_readed;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	nbytes_readed = 1;
	while (ft_strchr(stash, '\n') != 1 && nbytes_readed != 0)
	{
		nbytes_readed = read(fd, buff, BUFFER_SIZE);
		if (nbytes_readed == -1)
			return (free(stash), free(buff), NULL);
		buff[nbytes_readed] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	return (free(buff), stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE < 0 || fd >= OPEN_MAX)
		return (NULL);
	stash = ft_save(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_new_line(stash);
	stash = ft_clean_stash(stash);
	return (line);
}
