/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 04:11:05 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/07 11:10:22 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;
	void		*content_cpy;

	content_cpy = NULL;
	if (!content)
		content_size = 0;
	else
	{
		content_cpy = ft_memalloc(content_size);
		content_cpy = ft_memcpy(content_cpy, content, content_size);
	}
	list = (t_list *)ft_memalloc(sizeof(t_list));
	if (list)
	{
		list->content = content_cpy;
		list->content_size = content_size;
		list->next = NULL;
		return (list);
	}
	return (NULL);
}
