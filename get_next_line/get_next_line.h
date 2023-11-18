/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:17:42 by ahaloui           #+#    #+#             */
/*   Updated: 2022/11/25 14:13:36 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<string.h>
# include<fcntl.h>
# include<limits.h>

char	*ft_get_new_line(char *stash);
char	*ft_clean_stash(char *stash);
char	*ft_save(int fd, char *stash);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
int		ft_strchr(char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *stash, char *buff);

#endif 