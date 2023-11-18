/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:25:12 by ahaloui           #+#    #+#             */
/*   Updated: 2022/10/26 09:22:06 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst)
	{
		if (*lst == NULL)
		{
			*lst = new;
			new = NULL;
		}
		else
		{
			tmp = *lst;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
			tmp = NULL;
			new = NULL;
		}
	}
}
