/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:02:47 by ahaloui           #+#    #+#             */
/*   Updated: 2022/11/12 15:15:33 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words_me(char *str, char c)
{
	int	count;
	int	find;

	count = 0;
	find = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str != c && find == 0)
		{
			find = 1;
			count++;
		}
		else if (*str == c)
			find = 0;
		str++;
	}
	return (count + 1);
}

static int	get_size_word(char *str, char c, int pos)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] && str[i] == c)
		i++;
	while (pos--)
	{
		while (str[i] && str[i] != c)
			i++;
		while (str[i] && str[i] == c)
			i++;
	}
	while (str[i] && str[i] != c)
	{
		i++;
		size++;
	}
	return (size + 1);
}

static char	*get_word(char *str, char c, int pos)
{
	int		size_word;
	char	*word;
	int		i;
	int		j;

	size_word = get_size_word(str, c, pos);
	word = (char *)malloc(sizeof(char) * size_word);
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && str[i] == c)
		i++;
	while (pos--)
	{
		while (str[i] && str[i] != c)
			i++;
		while (str[i] && str[i] == c)
			i++;
	}
	j = -1;
	while (++j < size_word - 1)
		word[j] = str[i++];
	word[size_word - 1] = 0;
	return (word);
}

char	**ft_split(const char *s, char c)
{
	unsigned int	i;
	char			**split;
	unsigned int	d;

	i = -1;
	if (!s)
		return (0);
	d = count_words_me((char *)s, c);
	split = (char **)malloc(d * sizeof(char *));
	if (!split)
		return (0);
	while (++i < d - 1)
	{
		split[i] = get_word((char *)s, c, i);
		if (!split[i])
		{
			i--;
			while (--i >= 0)
				free(split[i]);
			free (split);
		}
	}
	split[d - 1] = 0;
	return (split);
}
